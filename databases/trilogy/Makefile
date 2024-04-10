PORTNAME=	trilogy
PORTVERSION=	2.8.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client library for MySQL-compatible database servers
WWW=		https://github.com/trilogy-libraries/trilogy

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake ssl

USE_GITHUB=	yes
GH_ACCOUNT=	trilogy-libraries

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/example/trilogy_query ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/inc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/
	${INSTALL_DATA} ${WRKSRC}/libtrilogy.a ${STAGEDIR}${PREFIX}/lib/
	${INSTALL_LIB} ${WRKSRC}/libtrilogy.so ${STAGEDIR}${PREFIX}/lib/

.include <bsd.port.mk>
