PORTNAME=	libinjection
PORTVERSION=	4.0.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	SQL / SQLI tokenizer parser analyzer
WWW=		https://github.com/libinjection/libinjection

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool python:build shebangfix

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_GITHUB=	yes

SHEBANG_GLOB=	*.py

.include <bsd.port.mk>
