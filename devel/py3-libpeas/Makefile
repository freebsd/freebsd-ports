# Created by: Koop Mast <kwm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpeas
PORTREVISION=	0
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome3
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

COMMENT=	libpeas Python 3 support

LIB_DEPENDS+=	libpeas-1.0.so:devel/libpeas

LIBPEAS_SLAVE=	python3

BUILD_WRKSRC=	${WRKSRC}/loaders/python3
INSTALL_WRKSRC=	${WRKSRC}/loaders/python3

MASTERDIR=	${.CURDIR}/../../devel/libpeas/

.include "${MASTERDIR}/Makefile"
