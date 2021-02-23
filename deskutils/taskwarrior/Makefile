# Created by: gahr
# $FreeBSD$

PORTNAME=	taskwarrior
PORTVERSION=	2.5.3
DISTVERSIONPREFIX=	v
CATEGORIES=	deskutils

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Feature-rich command-line todo list manager

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgnutls.so:security/gnutls
TEST_DEPENDS=	faketime:devel/libfaketime

USES=		compiler:c++11-lib cmake python:test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	GothenburgBitFactory
GH_PROJECT=	taskwarrior libshared:libshared
GH_TAGNAME=	418a187:libshared
GH_SUBDIR=	src/libshared:libshared

CMAKE_ARGS+=	-DTASK_DOCDIR:STRING=${DATADIR:S/${PREFIX}\///} \
		-DTASK_MAN1DIR:STRING=man/man1 \
		-DTASK_MAN5DIR:STRING=man/man5

SHEBANG_FILES=	scripts/*/*.pl \
		doc/rc/refresh \

do-test:
	@cd ${WRKSRC}/test && \
	${SETENV} TASK_USE_PATH=1 PATH=${PATH}:${STAGEDIR}/bin \
	${PYTHON_CMD} run_all --verbose && \
	${PYTHON_CMD} problems

.include <bsd.port.mk>
