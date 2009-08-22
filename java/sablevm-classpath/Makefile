# ex:ts=8
# New ports collection makefile for:    sablevm
# Date created:         		26 Nov 2007
# Whom:                 		Björn König <bkoenig@alpha-tierchen.de>
#
# $FreeBSD$
#

PORTNAME=	sablevm-classpath
PORTVERSION=	1.13
PORTREVISION=	6
CATEGORIES=	java
MASTER_SITES=	SF/sablevm/sablevm/${PORTVERSION}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	Classpath of SableVM

BUILD_DEPENDS=	jikes:${PORTSDIR}/java/jikes

OPTIONS=	ZIP "Compress class library" ON \
		GTK2 "Enable Gtk+ AWT peer" ON \
		CAIRO "Use Cairo based Graphics2D" OFF

CONFLICTS=	classpath-[0-9]*

USE_XORG=	x11 ice xtst sm
GNU_CONFIGURE=	yes
USE_GNOME=	# empty
USE_GMAKE=	yes
USE_LDCONFIG=	${PREFIX}/lib/${PORTNAME}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}
CONFIGURE_ENV=	CFLAGS="-I${PREFIX}/include -L${PREFIX}/lib -I${LOCALBASE}/include -L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_ZIP)
CONFIGURE_ARGS+=	--with-compressed-classes=no
PLIST_SUB+=		WITHOUT_ZIP="" WITH_ZIP="@comment "
.else
CONFIGURE_ARGS+=	--with-compressed-classes=zip
BUILD_DEPENDS+=		zip:${PORTSDIR}/archivers/zip
PLIST_SUB+=		WITHOUT_ZIP="@comment " WITH_ZIP=""
.endif

.if defined(WITHOUT_GTK2)
CONFIGURE_ARGS+=	--disable-gtk-peer
PLIST_SUB+=		GTK2="@comment "
.else
USE_GNOME+=		gtk20
PLIST_SUB+=		GTK2=""
.if defined(WITH_CAIRO)
CONFIGURE_ARGS+=	--enable-gtk-cairo
.endif
.endif

post-extract:
	@${REINPLACE_CMD} -e 's,^\(include_HEADERS = \)jni.h jni_md.h \(.*\),\1\2,' \
		${WRKSRC}/include/Makefile.in

.include <bsd.port.post.mk>
