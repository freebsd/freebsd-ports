# Created by: h2
# $FreeBSD$

PORTNAME=	seqan
DISTVERSION=	2.4.0
CATEGORIES=	biology
MASTER_SITES=	http://packages.seqan.de/seqan-library/
DISTNAME=	${PORTNAME}-library-${PORTVERSION}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	C++ sequence analysis template library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/share/doc/seqan/LICENSE

USES=		tar:xz
NO_BUILD=	yes
NO_ARCH=	yes

CONFLICTS=	seqan1-[0-9]*

OPTIONS_DEFINE=	DOCS

PORTDOCS=	*

post-patch: # delete empty doc dirs
	@cd ${WRKSRC}/share/doc/seqan/html && ${RMDIR} docs/seqan docs lists

do-install:
	cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} ./${PORTNAME} ${STAGEDIR}/${PREFIX}/include
	@${MKDIR} ${STAGEDIR}/${PREFIX}/lib/cmake/seqan
	${INSTALL_DATA} ${WRKSRC}/share/cmake/seqan/seqan-config.cmake ${STAGEDIR}/${PREFIX}/lib/cmake/seqan/
	@${MKDIR} ${STAGEDIR}/${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/share/pkgconfig/seqan-2.pc ${STAGEDIR}/${PREFIX}/libdata/pkgconfig/

do-install-DOCS-on:
	cd ${WRKSRC}/share/doc/ && ${COPYTREE_SHARE} ./seqan/ ${STAGEDIR}${DOCSDIR}/../

.include <bsd.port.mk>
