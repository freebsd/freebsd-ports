# New ports collection makefile for:	libiconv
# Date created:				21 August 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psiconv
PORTVERSION=	0.9.7
CATEGORIES=	converters devel
MASTER_SITES=	http://www.frodol.dds.nl/psiconv/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A conversion utility to convert Psion 5(MX) files into other formats

USE_GETOPT_LONG=yes
INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ARGS=	--with-imagemagick=no
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

MAN1=		psiconv.1 psiconv-config.1

.include <bsd.port.mk>
