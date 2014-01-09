# Created by: Boris B. Samorodov <bsam@ipt.ru>
# $FreeBSD$

CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	freebsd@grem.de
COMMENT=	Ice (Internet Communications Engine) language mapping for Python

LICENSE=	GPLv2

BUILD_DEPENDS=	mcpp:${PORTSDIR}/devel/mcpp \
		slice2py:${PORTSDIR}/devel/ice
LIB_DEPENDS=	Ice.${LIB_VRS}:${PORTSDIR}/devel/ice

USE_PYTHON=	yes
SLAVE_PORT=	yes
MASTERDIR=	${.CURDIR}/../ice
PLIST=		${.CURDIR}/pkg-plist

BUILD_WRKSRC=	${WRKSRC}/py
INSTALL_WRKSRC=	${WRKSRC}/py

LIB_VRS=	${PORTVERSION:S|.||g:C|[0-9]$||}
PLIST_SUB=	LIB_VERSION="${PORTVERSION}" LIB_VRS="${LIB_VRS}"

# bypass infrastructure bug (taken from www/py-django)
OPTIONSFILE=	${PORT_DBDIR}/py-${PORTNAME}/options
OPTIONS_DEFINE=	DEBUG DOCS TESTS
OPTIONS_DEFAULT=TESTS
TESTS_DESC=	Run tests

post-install:
	${ECHO} "Ice" > ${STAGEDIR}${PYSITEDIR}/Ice.pth
	@${FIND} ${STAGEDIR}${PYSITEDIR}/Ice \( -name "*.pyc" -or -name "*.pyo" \) \
		-exec ${CHMOD} u+w {} \;
	@${PYTHON_CMD} -m compileall ${STAGEDIR}${PYSITEDIR}/Ice
	@${PYTHON_CMD} -O -m compileall ${STAGEDIR}${PYSITEDIR}/Ice

.include "${MASTERDIR}/Makefile"
