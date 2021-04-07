PORTNAME=	libgrading
PORTVERSION=	0.1.8
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Simple library for grading C- and C++-language assignments

LICENSE=	APACHE20

LIB_DEPENDS=	libdistance.so:devel/libdistance

USES=		cmake compiler:c++11-lib

USE_GITHUB=	yes
GH_ACCOUNT=	trombonehero

USE_LDCONFIG=	yes

PLIST_FILES=	include/libgrading.h \
		lib/libgrading.so.${PORTVERSION} \
		lib/libgrading.so

.include <bsd.port.mk>
