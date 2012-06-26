# New ports collection makefile for:	evas_generic_loaders-raw
# Date created:		9 March 2012
# Whom:			Grzegorz Blach <magik@roorback.net>
#
# $FreeBSD$
#

PORTNAME=	raw
DISTVERSION=	1.1.0
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/
PKGNAMEPREFIX=	evas_generic_loaders-
DISTNAME=	${PKGNAMEPREFIX}${DISTVERSION}

MAINTAINER=	magik@roorback.net
COMMENT=	Additional loader for Evas (raw)

LICENSE=	GPLv2

LIB_DEPENDS=	raw.5:${PORTSDIR}/graphics/libraw

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_EFL=	eina
USE_GNOME=	gnomehack pkgconfig

BINSRC=		${WRKSRC}/src/bin/${PORTNAME}

do-build:
	${MAKE} -C ${BINSRC}

do-install:
	${MAKE} -C ${BINSRC} install

.include <bsd.port.mk>
