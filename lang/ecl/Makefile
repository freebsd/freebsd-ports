# New ports collection makefile for: ecl
# Date created:		  29 Januar 2004
# Whom:			Julian Stecklina
#
# $FreeBSD$
#

PORTNAME=	ecl
PORTVERSION=	0.9d.040726
CATEGORIES=	lang
MASTER_SITES=	http://www.inf.tu-dresden.de/~s1054849/
EXTRACT_SUFX=	.tbz

MAINTAINER=	der_julian@web.de
COMMENT=	An ANSI Common Lisp implementation

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

WRKSRC=		${WRKDIR}/ecls
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/ecl

MAN1=		ecl.1
INFO=		ecl ecldev

USE_BZIP2=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
USE_LIBTOOL_VER=	13
CONFIGURE_ARGS=	--with-tcp --enable-threads --with-clos-streams --enable-local-gmp --with-cmuformat
CONFIGURE_ENV=	LDFLAGS=-L${PREFIX}/lib CFLAGS=-I${PREFIX}/include

.include <bsd.port.mk>
