PORTNAME=	phone
PORTVERSION=	0.6.2
CATEGORIES=	comms
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Phone/
PKGNAMEPREFIX=	deforaos-
DISTNAME=	Phone-${PORTVERSION}

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	DeforaOS telephony application
WWW=		https://www.defora.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libSystem.so:devel/deforaos-libsystem \
		libDesktop.so:x11/deforaos-libdesktop \
		libharfbuzz.so:print/harfbuzz
BUILD_DEPENDS=	${LOCALBASE}/include/linux/videodev2.h:multimedia/v4l_compat

USES=		desktop-file-utils gnome pkgconfig ssl
USE_XORG=	x11
USE_GNOME=	gtk30 cairo gdkpixbuf2
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

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Phone/plugins/*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/Phone/modem/*

.include <bsd.port.mk>
