# Created by: Ed Schouten <ed@FreeBSD.org>
# $FreeBSD$

PORTNAME=	yaml2argdata
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4
CATEGORIES=	devel

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Helper classes for parsing YAML into Argdata

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	argdata>=0:devel/argdata \
		yaml-cpp>=0:devel/yaml-cpp

USE_GITHUB=	yes
GH_ACCOUNT=	NuxiNL

NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}/${PORTNAME} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/include/${PORTNAME}

.include <bsd.port.mk>
