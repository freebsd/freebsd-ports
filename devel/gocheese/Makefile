PORTNAME=	gocheese
DISTVERSION=	6.0.0
CATEGORIES=	devel python
MASTER_SITES=	http://www.gocheese.stargrave.org/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python private package repository and caching proxy
WWW=		http://www.gocheese.stargrave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go tar:zst

GO_PKGNAME=	go.stargrave.org/gocheese/v6
GO_TARGET=	go.stargrave.org/gocheese/v6:${PORTNAME}

INFO=		${PORTNAME}
PLIST_FILES=	bin/${PORTNAME} \
		bin/pyshop2packages.sh

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/pyshop2packages.sh ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
