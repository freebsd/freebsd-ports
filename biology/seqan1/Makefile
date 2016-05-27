# Created by: h2
# $FreeBSD$

PORTNAME=	seqan
PORTVERSION=	1.3.1
PORTREVISION=	3
CATEGORIES=	biology
MASTER_SITES=	http://ftp.seqan.de/releases/
PKGNAMESUFFIX=	1

MAINTAINER=	h2+fbsdports@fsfe.org
COMMENT=	C++ Sequence Analysis Library

LICENSE=	BSD3CLAUSE
LICENSE_FILE_BSD=${WRKSRC}/seqan/LICENSE

USES=		zip
NO_BUILD=	yes

CONFLICTS=	seqan-[2-9]*

do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ./${PORTNAME} ${STAGEDIR}/${PREFIX}/include
	cd ${WRKSRC} && ${INSTALL_DATA} ./${PORTNAME}.h ${STAGEDIR}/${PREFIX}/include

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} ./ ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
