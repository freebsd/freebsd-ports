# $FreeBSD$

CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Ice (Internet Communications Engine) language mapping for Python

LICENSE=	GPLv2

BROKEN_powerpc64=	fails to compile: gmake: Ice_BuiltinSequences_ice.py: Segmentation fault (core dumped)

BUILD_DEPENDS=	mcpp:devel/mcpp
LIB_DEPENDS=	libIce.so.${LIB_VRS}:devel/ice37 \
		libmcpp.so:devel/mcpp

USES=		gettext-runtime python shebangfix
USE_PYTHON=	py3kplist
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../ice37
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

SHEBANG_GLOB=	*.py

MAKE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION}
MAKE_ARGS+=	PYTHON=${PYTHON_CMD}

LIB_VRS=	${PORTVERSION:S|.||g:C|[0-9]$||}
PLIST_SUB=	LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"

OPTIONS_DEFINE=	DEBUG TEST
TEST_BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYSITEDIR}/IcePy.so
	${ECHO} "Ice" > ${STAGEDIR}${PYSITEDIR}/Ice.pth
	@${FIND} ${STAGEDIR}${PYSITEDIR}/Ice \( -name "*.pyc" -or -name "*.pyo" \) \
		-exec ${CHMOD} u+w {} \;
.for dir in Glacier2 Ice IceBox IceGrid IceMx IcePatch2 IceStorm
	@${PYTHON_CMD} -m compileall -d ${PYSITEDIR}/Ice ${STAGEDIR}${PYSITEDIR}/${dir}
	@${PYTHON_CMD} -O -m compileall -d ${PYSITEDIR}/Ice ${STAGEDIR}${PYSITEDIR}/${dir}
.endfor

.include "${MASTERDIR}/Makefile"
