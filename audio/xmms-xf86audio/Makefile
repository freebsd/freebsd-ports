# $FreeBSD$

PORTNAME=	xmms-xf86audio
PORTVERSION=	0.4.4
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.devin.com/xmms-xf86audio/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XF86Audio multimedia-key support for XMMS

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libxmms.so:multimedia/xmms

MAKE_ARGS=	CC="${CC}" OPT="${CFLAGS}" DEBUG=""

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/xmms/General
	${INSTALL_LIB} ${WRKSRC}/libxf86audio.so \
		${STAGEDIR}${PREFIX}/lib/xmms/General

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
