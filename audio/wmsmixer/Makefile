PORTNAME=	wmsmixer
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	https://www.dockapps.net/download/

MAINTAINER=	blackend@FreeBSD.org
COMMENT=	Audio mixer for the Window Maker dock

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		alias imake xorg
USE_XORG=	x11 xext xpm
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}"

PLIST_FILES=	bin/wmsmixer
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmsmixer ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
