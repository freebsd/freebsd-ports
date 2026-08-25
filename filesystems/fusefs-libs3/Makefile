PORTNAME=	fusefs-libs3
DISTVERSION=	3.18.2
CATEGORIES=	filesystems sysutils
MASTER_SITES=	https://github.com/libfuse/libfuse/releases/download/fuse-${DISTVERSION}/
DISTNAME=	fuse-${DISTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	FUSE library version 3 for filesystems implemented in userspace
WWW=		https://github.com/libfuse/libfuse/wiki/Filesystems

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR}

USES=		compiler iconv meson ninja python:test
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PLIST_SUB=	VERSION=${PORTVERSION}

do-test:
	${SU_CMD} "${PYTHON_CMD} -m pytest ${WRKSRC}/_build/test/"

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
IGNORE=	fusefs has not been implemented on DragonFly
.endif

.include <bsd.port.post.mk>
