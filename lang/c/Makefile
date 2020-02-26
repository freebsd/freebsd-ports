# $FreeBSD$

PORTNAME=	c
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11
CATEGORIES=	lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to compile and run C programs like a shell script

LICENSE=	MIT

RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	ryanmjacobs
SHEBANG_FILES=	c

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
