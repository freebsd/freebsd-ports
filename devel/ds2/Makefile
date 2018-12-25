# $FreeBSD$

PORTNAME=	ds2
PORTVERSION=	20151028
CATEGORIES=	devel

MAINTAINER=	wg@FreeBSD.org
COMMENT=	Debug server for lldb

LICENSE=	NCSA
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	facebook
GH_TAGNAME=	52c45f3

ONLY_FOR_ARCHS=		amd64
ONLY_FOR_ARCHS_REASON=	the ptrace code only has an amd64 backend

USES=		cmake:insource compiler

PLIST_FILES=	bin/ds2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ds2 ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.pre.mk>

.if ${COMPILER_TYPE} == "gcc"
IGNORE=	builds only on greater than 10.1 and with clang
.endif

.include <bsd.port.post.mk>
