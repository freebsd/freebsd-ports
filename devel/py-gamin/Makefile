# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	3
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Gamin file monitoring system

MASTERDIR=	${.CURDIR}/../gamin
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

GAMIN_SLAVE=	yes

USES=		fam:gamin python:2.7
USE_PYTHON=	flavors
CONFIGURE_ARGS=	--with-python=${PYTHON_CMD} \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${STAGEDIR}${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${STAGEDIR}${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
