# ex:ts=8
# Ports collection makefile for:	gcc
# Version required:			2.8.0
# Date created:				17 Jan 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $Id: Makefile,v 1.1.1.1 1998/01/16 10:15:13 obrien Exp $
#

DISTNAME=	gcc-2.8.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	obrien@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386-unknown-freebsd
ALL_TARGET=	bootstrap
MAN1=		cccp28.1 g++28.1 gcc28.1

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
	ln -f ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc28
	ln -f ${PREFIX}/bin/g++ ${PREFIX}/bin/g++28
	${MV} ${PREFIX}/man/man1/cccp.1 ${PREFIX}/man/man1/cccp28.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++28.1
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc28.1

.include <bsd.port.mk>
