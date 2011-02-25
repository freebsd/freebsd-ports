# ex:ts=8
# Ports collection makefile for:	showimg
# Date created:			Mar 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	showimg
PORTVERSION=	0.9.5
PORTREVISION=	8
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.jalix.org/projects/${PORTNAME}/download/${PORTVERSION}/ \
		http://vxj-se.lunar-linux.org/lunar/cache/

MAINTAINER=	citycat4@ngs.ru
COMMENT=	A picture viewer designed to run under KDE 3.x

USE_BZIP2=		yes
USE_GMAKE=		yes
USE_KDEBASE_VER=	3
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes
CONFIGURE_ARGS+=	--disable-pgsql

OPTIONS=	KIPI "Support for libkipi" on \
		KEXIF "Support for kexif" on \
		KEXIDB "Support for KexiDB/ShowimgDB" on \
		MYSQL "Build MySQL plugin for KexiDB" off \

.include <bsd.port.pre.mk>

.if defined(WITHOUT_KIPI)
CONFIGURE_ARGS+=--disable-libkipi
.else
LIB_DEPENDS+=	kipi:${PORTSDIR}/graphics/libkipi
.endif

.if defined(WITHOUT_KEXIF)
CONFIGURE_ARGS+=--without-kexif
.else
LIB_DEPENDS+=	kexif:${PORTSDIR}/graphics/libkexif
.endif

.if defined(WITHOUT_KEXIDB) && defined(WITHOUT_MYSQL)
CONFIGURE_ARGS+=--without-showimgdb
PLIST_SUB+=	KEXIDB="@comment "
.else
PLIST_SUB+=	KEXIDB=""
.endif

.if defined(WITH_MYSQL)
USE_MYSQL=	yes
PLIST_SUB+=	MYSQL=""
.else
CONFIGURE_ARGS+=--disable-mysql
PLIST_SUB+=	MYSQL="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '347,365d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|-O2||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.post.mk>
