PORTNAME=	qbe
DISTVERSION=	g20220411
CATEGORIES=	devel
MASTER_SITES=	https://c9x.me/git/qbe.git/snapshot/
DISTNAME=	qbe-2caa26e388b

MAINTAINER=	se@FreeBSD.org
COMMENT=	Embeddable compiler backend for C type languages

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake

OPTIONS_DEFINE=	DOCS

do-build:
		cd ${WRKSRC}; ${GMAKE}

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/obj/qbe ${STAGEDIR}${PREFIX}/bin
		${MKDIR} ${STAGEDIR}${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/doc/*.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
