# Created by: h2
# $FreeBSD$

PORTNAME=	seqan
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	http://packages.seqan.de/seqan-library/
DISTNAME=	${PORTNAME}-library-${PORTVERSION}

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	C++ Sequence Analysis Template Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/share/doc/seqan/LICENSE

USES=		tar:xz
NO_BUILD=	yes

CONFLICTS=	seqan1-[0-9]*

OPTIONS_DEFINE=	DOCS
DOCS_DESC=	Install official API documentation (html)

do-install:
	cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} ./${PORTNAME} ${STAGEDIR}/${PREFIX}/include
	${MKDIR} ${STAGEDIR}/${PREFIX}/share/cmake/Modules
	${INSTALL_DATA} ${WRKSRC}/share/cmake/Modules/FindSeqAn.cmake ${STAGEDIR}/${PREFIX}/share/cmake/Modules/
	${MKDIR} ${STAGEDIR}/${PREFIX}/libdata/pkgconfig
	${INSTALL_DATA} ${WRKSRC}/share/pkgconfig/seqan-2.pc ${STAGEDIR}/${PREFIX}/libdata/pkgconfig/

do-install-DOCS-on:
	cd ${WRKSRC}/share/doc/ && ${COPYTREE_SHARE} ./seqan/ ${STAGEDIR}${DOCSDIR}/../

.include <bsd.port.mk>
