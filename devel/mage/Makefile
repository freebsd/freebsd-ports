PORTNAME=	mage
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.1
PORTEPOCH=	1
CATEGORIES=	devel

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Command-line make-like build tool using Go as input files
WWW=		https://magefile.org/ \
		https://github.com/magefile/mage/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules

USE_GITHUB=	yes
GH_ACCOUNT=	magefile

PLIST_FILES=	bin/mage

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${GO_ENV} \
	${GO_CMD} run bootstrap.go

.include <bsd.port.mk>
