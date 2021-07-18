# Created by: Cristiano Rolim Pereira <cristianorolim@hotmail.com>

PORTNAME=	libawl
DISTVERSIONPREFIX=	r
DISTVERSION=	0.62
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
GL_COMMIT=	827fbfed7dab0ca339998ca6cdcffb328246d83b

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
