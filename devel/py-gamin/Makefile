# New ports collection makefile for:   py-gamin
# Date Created:			24 March 2005
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#

PORTREVISION=	0
CATEGORIES=	devel python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Python interface to the Gamin file monitoring system

LIB_DEPENDS=	gamin-1.0:${PORTSDIR}/devel/gamin

MASTERDIR=	${.CURDIR}/../gamin
BUILD_WRKSRC=	${WRKSRC}/python
INSTALL_WRKSRC=	${BUILD_WRKSRC}
DESCR=		${.CURDIR}/pkg-descr
PLIST=		${.CURDIR}/pkg-plist

GAMIN_SLAVE=	yes

USE_GNOME=	gnomehack gnometarget
USE_PYTHON=	yes
CONFIGURE_ARGS=	--with-python=${LOCALBASE} \
		--disable-gtk-doc --with-html-dir=${PREFIX}/share/doc

post-install:
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py -l ${PYTHON_SITELIBDIR}

.include "${MASTERDIR}/Makefile"
