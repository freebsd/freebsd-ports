# Created by: Boris B. Samorodov <bsam@ipt.ru>
# $FreeBSD$

CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for Python

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:devel/mcpp
LIB_DEPENDS=	libIce.so.${LIB_VRS}:devel/ice

USES=		python shebangfix
USE_PYTHON=	py3kplist
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../ice
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${WRKSRC}/python

SHEBANG_FILES=	${BUILD_WRKSRC}/config/s2py.py

MAKE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION}

LIB_VRS=	${PORTVERSION:S|.||g:C|[0-9]$||}
PLIST_SUB=	LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"

OPTIONS_DEFINE=	DEBUG TEST

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYSITEDIR}/Ice/*.so.*
	${ECHO} "Ice" > ${STAGEDIR}${PYSITEDIR}/Ice.pth
	@${FIND} ${STAGEDIR}${PYSITEDIR}/Ice \( -name "*.pyc" -or -name "*.pyo" \) \
		-exec ${CHMOD} u+w {} \;
	@${PYTHON_CMD} -m compileall -d ${PYSITEDIR}/Ice ${STAGEDIR}${PYSITEDIR}/Ice
	@${PYTHON_CMD} -O -m compileall -d ${PYSITEDIR}/Ice ${STAGEDIR}${PYSITEDIR}/Ice

.include "${MASTERDIR}/Makefile"
