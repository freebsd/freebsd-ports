# New ports collection makefile for:	libiconv
# Date created:				21 August 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psiconv
PORTVERSION=	0.8.3
PORTREVISION=	1
CATEGORIES=	converters devel
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A conversion utility to convert Psion 5(MX) files into other formats

USE_GETOPT_LONG=yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-imagemagick=no
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
