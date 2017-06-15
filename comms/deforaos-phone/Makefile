# Created by: Olivier Cochard-Labbe <olivier@FreeBSD.org>
# $FreeBSD$

PORTNAME=	phone
PORTVERSION=	0.5.1
CATEGORIES=	comms
MASTER_SITES=	http://www.defora.org/os/download/download/4455/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Phone-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS telephony application

LICENSE=	GPLv3

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libpulse.so:audio/pulseaudio \
		libpurple.so:net-im/libpurple \
		libsofia-sip-ua.so:net/sofia-sip \
		libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2
BUILD_DEPENDS=	locker:x11/deforaos-locker \
		${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat

USES=		desktop-file-utils pkgconfig
USE_GNOME=	gtk20 cairo
INSTALLS_ICONS=	yes
MAKE_ARGS+=	PREFIX=${PREFIX}
MAKE_ENV+=	MANDIR=${STAGEDIR}${MANPREFIX}/man

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
DOCS_BUILD_DEPENDS=	xsltproc:textproc/libxslt \
	${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl:textproc/docbook-xsl

post-patch-DOCS-off:
	${REINPLACE_CMD} 's|data doc include|data include|' \
		${WRKSRC}/Makefile

post-patch-NLS-off:
	${REINPLACE_CMD} 's|include po src|include src|' \
		${WRKSRC}/Makefile

post-patch:
	@${REINPLACE_CMD} -e 's,/dev/modem,/dev/cuaU0,g' \
		${WRKSRC}/src/modems/hayes.c
	@${REINPLACE_CMD} -e 's|/lib/|/libdata/|g' \
		${WRKSRC}/data/pkgconfig.sh
	@${REINPLACE_CMD} 's|-Wl,-pie||g' \
		${WRKSRC}/tools/Makefile \
		${WRKSRC}/src/Makefile \
		${WRKSRC}/tests/Makefile
	@${REINPLACE_CMD} 's|-lossaudio||' \
		${WRKSRC}/src/plugins/Makefile \
		${WRKSRC}/tests/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Phone/plugins/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Phone/modem/*

.include <bsd.port.mk>
