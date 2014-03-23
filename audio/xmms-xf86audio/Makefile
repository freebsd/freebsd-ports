# $FreeBSD$

PORTNAME=	xmms-xf86audio
PORTVERSION=	0.4.4
CATEGORIES=	audio
MASTER_SITES=	http://www.devin.com/xmms-xf86audio/download/

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XF86Audio multimedia-key support for XMMS

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

LIB_DEPENDS=	libxmms.so:${PORTSDIR}/multimedia/xmms

MAKE_ARGS=	CC="${CC}" OPT="${CFLAGS}" DEBUG=""

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/General
	${INSTALL_DATA} ${WRKSRC}/libxf86audio.so \
	    ${STAGEDIR}${PREFIX}/lib/xmms/General
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
