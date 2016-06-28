# Created by: Gasol Wu <gasol.wu@gmail.com>
# $FreeBSD$

PORTNAME=	trace
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DIST_SUBDIR=	PECL

MAINTAINER=	gasol.wu@gmail.com
COMMENT=	Low-overhead tracing tool for PHP

LICENSE=	APACHE20

WRKSRC_SUBDIR=	extension
CMDTOOLSRC=	${WRKSRC}/../cmdtool

GNU_CONFIGURE=	yes
USES=		gmake php:ext shebangfix tar:tgz
IGNORE_WITH_PHP=	70

SHEBANG_FILES=	${CMDTOOLSRC}/phptrace
PLIST_FILES=	bin/phptrace \
		bin/trace-php

post-patch:
	${REINPLACE_CMD} -e 's|Darwin|FreeBSD|g' ${CMDTOOLSRC}/phptrace

post-build:
	(cd ${CMDTOOLSRC} && ${GMAKE} ${MAKE_ENV})

post-install:
	${INSTALL_PROGRAM} ${CMDTOOLSRC}/trace-php ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${CMDTOOLSRC}/phptrace ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
