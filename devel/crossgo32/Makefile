# New ports collection makefile for:    crossgo32
# Version required:     1.3
# Date created:         6 Mar 97
# Whom:                 Pedro Giffuni <pgiffuni@fps.biblos.unal.edu.co>
#
# $Id: Makefile,v 1.2 1997/03/28 02:35:44 obrien Exp $
#

DISTNAME=	crosstree-1.3
PKGNAME=	crossgo32-1.3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --target=${TARGET}
USE_GMAKE=	yes
TARGET= 	i386-go32

MAN1=	i386-go32-ar.1 i386-go32-nm.1 i386-go32-objdump.1 	\
	i386-go32-ranlib.1 i386-go32-size.1 i386-go32-strings.1	\
	i386-go32-strip.1 i386-go32-objcopy.1 i386-go32-nlmconv.1 \
	i386-go32-g++.1 i386-go32-gcc.1 cccp.1 \
	i386-go32-c++filt.1 configure.1 i386-go32-as.1 i386-go32-ld.1 

.include <bsd.port.mk>
