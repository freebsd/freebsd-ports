PORTNAME=	sigye
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.4
CATEGORIES=	deskutils

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal clock with ASCII art fonts and productivity timers
WWW=		https://github.com/am2rican5/sigye

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	am2rican5

CARGO_BUILD_ARGS=	-p sigye

PLIST_FILES=	bin/${PORTNAME}

do-install:
	# binaries (workaround for error: found a virtual manifest at `xx` instead of a package manifest)
	${INSTALL_PROGRAM} \
		${WRKDIR}/target/release/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
