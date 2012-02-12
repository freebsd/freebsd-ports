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
PKGNAMESUFFIX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module for Ming which allows you to create Flash 4/5 movies

MASTERDIR=	${.CURDIR}/../../graphics/ming
PLIST=		${.CURDIR}/pkg-plist
PLIST_SUB=	PYTHON_VER=${PYTHON_VER}
INSTALL_WRKSRC=		${WRKSRC}/py_ext
USE_PYTHON=	yes
#USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	mingc
PYDISTUTILS_PKGVERSION=	0.4.3
CONFIGURE_ARGS+=	--enable-python
PATCHDIR=	${.CURDIR}/files
SLAVE_PORT=	py

#post-patch:
#	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/setup.py
#	@${LN} -sf ${LOCALBASE}/include/ming ${WRKSRC}/../src

.include "${MASTERDIR}/Makefile"
