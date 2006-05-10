# New ports collection makefile for: ecl
# Date created:		  29 Januar 2004
# Whom:			Julian Stecklina
#
# $FreeBSD$
#

PORTNAME=	ecl
PORTVERSION=	0.9g
PORTREVISION=	1
CATEGORIES=	lang lisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecls

MAINTAINER=	der_julian@web.de
COMMENT=	An ANSI Common Lisp implementation

LIB_DEPENDS=	gmp.7:${PORTSDIR}/math/libgmp4

INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/ecl

# It should build and run on 64-bit architectures,
# but it is completely untested.
ONLY_FOR_ARCHS=	i386

MAN1=		ecl.1
INFO=		ecl ecldev

USE_GMAKE=	YES
USE_PERL5_BUILD=yes
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-asdf --with-tcp --with-system-gmp --enable-boehm=included

# We need to tell ECL where to find the GMP includes
# and libraries.
CONFIGURE_ENV=	LDFLAGS=-L${PREFIX}/lib CFLAGS=-I${PREFIX}/include

.include <bsd.port.mk>
