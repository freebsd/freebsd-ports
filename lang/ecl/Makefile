# New ports collection makefile for: ecl
# Date created:		  29 Januar 2004
# Whom:			Julian Stecklina
#
# $FreeBSD$
#

PORTNAME=	ecl
PORTVERSION=	0.9e
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ecls
DISTNAME=	ecl-0.9e-fix-1
EXTRACT_SUFX=	.tgz

MAINTAINER=	der_julian@web.de
COMMENT=	An ANSI Common Lisp implementation

BUILD_DEPENDS=	texi2html:${PORTSDIR}/textproc/texi2html
LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

WRKSRC=		${WRKDIR}/ecl-${PORTVERSION}
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
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--with-tcp --enable-threads --with-clos-streams --enable-local-gmp --with-cmuformat

# We need to tell ECL where to find the GMP includes
# and libraries.
CONFIGURE_ENV=	LDFLAGS=-L${PREFIX}/lib CFLAGS=-I${PREFIX}/include

.include <bsd.port.mk>
