# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>
# $FreeBSD$

PORTNAME=	libawl
DISTVERSIONPREFIX=	r
DISTVERSION=	0.61
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Andrew.s Web Libraries - PHP Utility Libraries

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:build,flavors

USE_GITLAB=	yes
GL_ACCOUNT=	davical-project
GL_PROJECT=	awl
GL_COMMIT=	6bdacad0b4fc51583c040d3bbefdd052ed863611

NO_ARCH=	yes
NO_BUILD=	yes

LIBAWLDIR?=	share/awl

post-patch:
	${RM} ${WRKSRC}/inc/*.orig

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/${LIBAWLDIR}
.for d in dba inc
	cd ${WRKSRC} && \
		${COPYTREE_SHARE} ${d} ${STAGEDIR}${PREFIX}/${LIBAWLDIR}/
.endfor

.include <bsd.port.mk>
