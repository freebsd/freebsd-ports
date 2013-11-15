# Created by: Masanori OZAWA <ozawa@ongs.co.jp>
# $FreeBSD$

PORTNAME=	xdtp
PORTVERSION=	1.5.0
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	http://www.ongs.co.jp/software/xdtp/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	XML document transfer program

LICENSE=	BSD

LIB_DEPENDS=	glibmm-2.4:${PORTSDIR}/devel/glibmm

USES=		pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	libxml2 libxslt
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	GDK DEBUG INCLUDE
GDK_DESC=	Build with Gdk-Pixbuf
INCLUDE_DESC=	Install with XDTP include files

OPTIONS_DEFAULT=	GDK INCLUDE

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.if ${PORT_OPTIONS:MGDK}
USE_GNOME+=	gtk20
.else
CONFIGURE_ENV+=	WITHOUT_GDK="yes"
MAKE_ARGS+=	-DWITHOUT_GDK
.endif

.if ${PORT_OPTIONS:MDEBUG}
MAKE_ARGS+=	-DDEBUG
.endif

.if ${PORT_OPTIONS:MINCLUDE}
PLIST_SUB+=	XDTP_INC=""
.else
MAKE_ARGS+=	-DWITHOUT_INCLUDE
PLIST_SUB+=	XDTP_INC="@comment "
.endif

# Unbreak parallel builds (-jX) by calling make(1) correctly
post-patch:
	@${REINPLACE_CMD} -E 's/cd(.+)(;| &&) (\$${MAKE})/\3 -C\1/' \
		${WRKSRC}/Makefile ${WRKSRC}/bin/Makefile \
		${WRKSRC}/java/Makefile ${WRKSRC}/misc/Makefile

.include <bsd.port.mk>
