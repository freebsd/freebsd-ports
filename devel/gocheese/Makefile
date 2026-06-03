PORTNAME=	gocheese
DISTVERSION=	5.0.0
PORTREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	http://www.gocheese.stargrave.org/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Python private package repository and caching proxy
WWW=		http://www.gocheese.stargrave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go tar:zst

GO_PKGNAME=	go.cypherpunks.ru/gocheese/v5
GO_TARGET=	go.cypherpunks.ru/gocheese/v5:${PORTNAME}

INFO=		${PORTNAME}
PLIST_FILES=	${DOCSDIR}/README \
		bin/${PORTNAME} \
		bin/pyshop2packages.sh

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/pyshop2packages.sh ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
