# New ports collection makefile for:	pecl-drizzle
# Date created:			30 Apr 2010
# Whom:				Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	drizzle
PORTVERSION=	0.4.2
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	A PHP wrapper for the libdrizzle library

LIB_DEPENDS=	drizzle.0:${PORTSDIR}/databases/libdrizzle

USE_PHP=	yes
USE_PHPEXT=	yes

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
