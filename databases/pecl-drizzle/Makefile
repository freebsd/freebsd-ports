# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	drizzle
PORTVERSION=	0.4.2
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	PHP wrapper for the libdrizzle library

DEPRECATED=	Works only with EOL php 5.6
EXPIRATION_DATE=	2018-12-30

LICENSE=	PHP301

LIB_DEPENDS=	libdrizzle.so:databases/libdrizzle

USES=		php:pecl
IGNORE_WITH_PHP=	71 72 73

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
