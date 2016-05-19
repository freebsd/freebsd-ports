# Created by: h2
# $FreeBSD$

PORTNAME=	seqan
PORTVERSION=	2.1.1
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
	${MKDIR} ${STAGEDIR}/${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/include/ && ${COPYTREE_SHARE} ./${PORTNAME} ${STAGEDIR}/${PREFIX}/include

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/share/doc/ && ${COPYTREE_SHARE} ./seqan/ ${STAGEDIR}${DOCSDIR}/../

.include <bsd.port.mk>
