# New ports collection makefile for:	libiconv
# Date created:				21 August 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	psiconv
PORTVERSION=	0.8.3
CATEGORIES=	converters devel
MASTER_SITES=	http://huizen.dds.nl/~frodol/psiconv/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A conversion utility to convert Psion 5(MX) files into other formats

LIB_DEPENDS=	gnugetopt.1:${PORTSDIR}/devel/libgnugetopt

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-imagemagick=no
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt"
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

.include <bsd.port.mk>
