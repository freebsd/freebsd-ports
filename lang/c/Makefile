# $FreeBSD$

PORTNAME=	c
PORTVERSION=	0.10
DISTVERSIONPREFIX=	v
CATEGORIES=	lang

MAINTAINER=	neel@neelc.org
COMMENT=	Tool to compile and run C programs like a shell script

LICENSE=	MIT

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	ryanmjacobs
NO_BUILD=	yes

SHEBANG_FILES=	c

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
