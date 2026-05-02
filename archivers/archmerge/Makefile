PORTNAME=	archmerge
DISTVERSION=	0.9.9
CATEGORIES=	archivers
MASTER_SITES=	https://codeberg.org/BSDforge/${PORTNAME}/archive/${DISTVERSION}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Produce a smaller zip file from two others with the best compressed files
WWW=		https://codeberg.org/BSDforge/${PORTNAME}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		ncurses
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/arm \
		share/doc/${PORTNAME}/README

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/arm ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
