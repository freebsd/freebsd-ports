# $FreeBSD$

PORTNAME=	ds2
PORTVERSION=	20151028
CATEGORIES=	devel

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Debug server for lldb

LICENSE=	NCSA
LICENSE_NAME=	University of Illinois/NCSA Open Source License
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TAGNAME=	52c45f3

USES=		cmake compiler

PLIST_FILES=	bin/ds2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ds2 ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1002000 || ${COMPILER_TYPE} == "gcc"
IGNORE=	builds only on greater than 10.1 and with clang
.endif

.include <bsd.port.post.mk>
