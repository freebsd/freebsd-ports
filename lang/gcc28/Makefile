# ex:ts=8
# Ports collection makefile for:	gcc
# Version required:			2.8.1
# Date created:				17 Jan 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $Id: Makefile,v 1.19 1998/11/13 07:32:21 obrien Exp $
#

DISTNAME=	gcc-2.8.1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc

MAINTAINER=	obrien@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
GNUHOST=	${ARCH}-unknown-freebsdelf${OSREL}
.else
GNUHOST=	${ARCH}-unknown-freebsd${OSREL}
.endif

PLIST_SUB=	GNUHOST=${GNUHOST}
CONFIGURE_ARGS=	--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${GNUHOST}/2.8.1/include/g++ 
.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ARGS+=	--host=${GNUHOST}
.endif
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	bootstrap
MAN1=		cccp28.1 g++28.1 gcc28.1

pre-fetch:
	@${ECHO} "GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}"

pre-configure:
	@(cd ${WRKSRC}/config/${ARCH}/ ; \
	MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd.h.in \
		>freebsd.h ; \
	${MV} freebsd-elf.h freebsd-elf.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd-elf.h.in \
		>freebsd-elf.h)

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/${GNUHOST}-gcc \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/2.8.1/cc1 \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/2.8.1/cc1obj \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/2.8.1/cc1plus \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/2.8.1/cpp ; \
		do strip $$prog ; \
		done)
	ln -f ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc28
	ln -f ${PREFIX}/bin/g++ ${PREFIX}/bin/g++28
	@${MV} ${PREFIX}/man/man1/cccp.1 ${PREFIX}/man/man1/cccp28.1
	@${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++28.1
	@${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc28.1

.include <bsd.port.post.mk>
