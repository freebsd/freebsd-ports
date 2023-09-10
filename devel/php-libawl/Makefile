PORTNAME=	libawl
DISTVERSIONPREFIX=	r
DISTVERSION=	0.64
CATEGORIES=	devel
PKGNAMEPREFIX=	${PHP_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Andrew.s Web Libraries - PHP Utility Libraries
WWW=		https://gitlab.com/davical-project/awl

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		php:build,flavors

USE_GITLAB=	yes
GL_ACCOUNT=	davical-project
GL_PROJECT=	awl
GL_TAGNAME=	f1c3753a2f356d856dfc279754f7885080e9e827

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
