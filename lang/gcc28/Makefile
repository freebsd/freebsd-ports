# ex:ts=8
# Ports collection makefile for:	gcc
# Version required:			2.8.0
# Date created:				17 Jan 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $Id$
#

DISTNAME=	gcc-2.8.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386-unknown-freebsd
MAN1=		cccp.1 g++.1 gcc.1

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/i386-unknown-freebsd-gcc \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/2.8.0/cc1 \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/2.8.0/cc1obj \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/2.8.0/cc1plus \
	${PREFIX}/lib/gcc-lib/i386-unknown-freebsd/2.8.0/cpp ; \
		do strip $$prog ; \
		done)

.include <bsd.port.mk>
