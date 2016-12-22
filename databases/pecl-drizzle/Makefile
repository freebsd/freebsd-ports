# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drizzle
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	joneum@bsdproject.de
COMMENT=	PHP wrapper for the libdrizzle library

LICENSE=	PHP301

LIB_DEPENDS=	libdrizzle.so:databases/libdrizzle

USES=		php:ext tar:tgz
IGNORE_WITH_PHP=	70

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	README EXPERIMENTAL ChangeLog CREDITS
PORTEXAMPLES=	drizzle.php

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
