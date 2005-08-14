# New ports collection makefile for:   panorama-tools
# Date created:        26 august 2004
# Whom:                cartola (Carlos E. G. Carvalho)
#
# $FreeBSD$
# This port has been made as a building and running dependence for the
# hugin port.
# The hugin port is a gui interface to interact with this and other
# tools.

PORTNAME=	libpano12
PORTVERSION=	2.7.0.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.openit.com.br/distfiles/

MAINTAINER=	cartola@openit.com.br
COMMENT=	Panorama Tools to make panorama pictures

LIB_DEPENDS=	tiff:${PORTSDIR}/graphics/tiff \
		png:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_JAVA=	yes
JAVA_VERSION=	1.3+
JAVA_OS=	native

MAKEFILE=	makefile.freebsd
MAKE_ENV=	JAVA_HOME=${JAVA_HOME}

INSTALLS_SHLIB=	yes

post-extract:
	${CP} ${FILESDIR}/makefile.freebsd ${WRKSRC}/makefile.freebsd

.include <bsd.port.mk>
