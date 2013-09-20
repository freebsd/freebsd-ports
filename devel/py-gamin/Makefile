# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$

PORTREVISION=	2
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Gamin file monitoring system

MASTERDIR=	${.CURDIR}/../gamin
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist
USE_FAM=	yes
WANT_FAM_SYSTEM=gamin

GAMIN_SLAVE=	yes

USES=	pathfix
USE_PYTHON=	yes
CONFIGURE_ARGS=	--with-python=${LOCALBASE} \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc

NO_STAGE=	yes
post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
