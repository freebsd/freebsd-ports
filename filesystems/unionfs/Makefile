PORTNAME=	unionfs
DISTVERSIONPREFIX=	v
DISTVERSION=	3.7
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	pkaipila@gmail.com
COMMENT=	FUSE based implementation of the well-known unionfs
WWW=		https://github.com/rpodgorny/unionfs-fuse

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		cmake fuse:3 localbase:ldflags pkgconfig python:test

USE_GITHUB=	yes
GH_ACCOUNT=	rpodgorny
GH_PROJECT=	unionfs-fuse

SUB_FILES=	pkg-message

PLIST_FILES=	bin/unionfs \
		bin/unionfsctl \
		share/man/man8/unionfs.8.gz

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/*

pre-test:
	${RLN} ${BUILD_WRKSRC}/src/unionfs ${WRKSRC}/src/unionfs
	${RLN} ${BUILD_WRKSRC}/src/unionfsctl ${WRKSRC}/src/unionfsctl

do-test:
	cd ${WRKSRC} && ${SETNEV} ${MAKE_ENV} ${PYTHON_CMD} -m pytest -k test_help --verbose

.include <bsd.port.mk>
