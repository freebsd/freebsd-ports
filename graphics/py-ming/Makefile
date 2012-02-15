# New ports collection makefile for:	Python/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTREVISION=	0
CATEGORIES=	graphics python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

BUILD_WRKSRC=	${WRKSRC}/py_ext
CONFIGURE_ARGS=	--enable-python
INSTALL_WRKSRC=	${WRKSRC}/py_ext
PATCH_WRKSRC=	${WRKSRC}/py_ext
PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

MASTERDIR=	${.CURDIR}/../../graphics/ming
SLAVEPORT=	py
PYDISTUTILS_PKGNAME=	mingc
PYDISTUTILS_PKGVERSION=	${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/py_ext/setup.py
	@${LN} -sf ${LOCALBASE}/include/ming ${WRKSRC}/src

.include "${MASTERDIR}/Makefile"
