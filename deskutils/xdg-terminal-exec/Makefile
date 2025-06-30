PORTNAME=	xdg-terminal-exec
DISTVERSIONPREFIX=v
DISTVERSION=	0.13.2
CATEGORIES=	deskutils

MAINTAINER=	arrowd@FreeBSD.org
COMMENT=	Command line interface to launch graphical terminal applications
WWW=		https://gitlab.freedesktop.org/terminal-wg/specifications/-/merge_requests/3

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	ginstall:sysutils/coreutils
TEST_DEPENDS=	bats:devel/bats-core

USES=		gmake

USE_GITHUB=	yes
GH_ACCOUNT=	Vladimir-csp

MAKE_ARGS=	prefix=${STAGEDIR}${PREFIX}
TEST_ENV=	HOME=${WRKDIR}
TEST_TARGET=	test

BINARY_ALIAS=	install=ginstall
OPTIONS_SUB=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	MANPAGES

MANPAGES_BUILD_DEPENDS=	scdoc:textproc/scdoc

post-patch-MANPAGES-off:
	${REINPLACE_CMD} -e 's/scdoc/echo/g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
