PORTNAME=	genie
DISTVERSION=	g2023092101
CATEGORIES=	devel

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	GENie Project generator tool
WWW=		https://github.com/bkaradzic/GENie

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake
USE_GITHUB=	yes
GH_ACCOUNT=	bkaradzic
GH_PROJECT=	GENie
GH_TAGNAME=	7f00dcb

MAKE_ARGS=	-C build/gmake.freebsd \
		AR=${AR} \
		CC=${CC} \
		CXX=${CXX} \
		verbose=1
MAKE_JOBS_UNSAFE=	yes

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DEBUG

DEBUG_MAKE_ARGS=	config=debug
DEBUG_MAKE_ARGS_OFF=	config=release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/bsd/genie \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
