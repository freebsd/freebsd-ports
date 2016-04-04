# Created by: Ross Timson <ross@rosstimson.com>
# $FreeBSD$

PORTNAME=	chruby
PORTVERSION=	0.3.9
DISTVERSIONPREFIX=	v
CATEGORIES=	devel ruby

MAINTAINER=	ross@rosstimson.com
COMMENT=	Changes the current Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash

PLIST_FILES=	bin/chruby-exec share/chruby/auto.sh share/chruby/chruby.sh

SUB_FILES=	pkg-message

USE_GITHUB=	yes
GH_ACCOUNT=	postmodern

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/chruby-exec ${STAGEDIR}${PREFIX}/bin
	( cd ${WRKSRC}/share/chruby && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/share/chruby )

.include <bsd.port.mk>
