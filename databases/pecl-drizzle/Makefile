# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drizzle
PORTVERSION=	0.4.2
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A PHP wrapper for the libdrizzle library

LIB_DEPENDS=	libdrizzle.so:${PORTSDIR}/databases/libdrizzle

LICENSE=	PHP301

USE_PHP=	yes
USE_PHPEXT=	yes
DEFAULT_PHP_VER=53
IGNORE_WITH_PHP=5
NO_STAGE=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	README EXPERIMENTAL ChangeLog CREDITS

post-install::
		@${MKDIR} ${DOCSDIR}
		@cd ${WRKSRC} && ${INSTALL} ${PORTDOCS} ${DOCSDIR}
.else
PORTDOCS=
.endif

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	drizzle.php

post-install::
		@${MKDIR} ${EXAMPLESDIR}
		@cd ${WRKSRC} && ${INSTALL} ${PORTEXAMPLES} ${EXAMPLESDIR}
.else
PORTEXAMPLES=
.endif

.include <bsd.port.mk>
