# $FreeBSD$

PORTNAME=	memleax
PORTVERSION=	1.0.3
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	guy.tabrar@me.com
COMMENT=	Debug memory leaks of running processes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libunwind.so:devel/libunwind
BUILD_DEPENDS=	${LOCALBASE}/lib/libdwarf.a:devel/libdwarf

ONLY_FOR_ARCHS=	amd64

USE_GITHUB=	yes
GH_ACCOUNT=	WuBingzheng

USES=		gmake
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
ALL_TARGET=	memleax
LLD_UNSAFE=	yes # cf. devel/libunwind

PLIST_FILES=	bin/memleax \
		man/man1/memleax.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/memleax ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/memleax.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
