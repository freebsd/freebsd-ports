# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpeas
PORTREVISION=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	libpeas Python 2 support

LIB_DEPENDS+=	libpeas-1.0.so:devel/libpeas

LIBPEAS_SLAVE=	python2

BUILD_WRKSRC=	${WRKSRC}/loaders/python
INSTALL_WRKSRC=	${WRKSRC}/loaders/python

MASTERDIR=	${.CURDIR}/../../devel/libpeas/

.include "${MASTERDIR}/Makefile"
