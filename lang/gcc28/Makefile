# ex:ts=8
# Ports collection makefile for:	gcc
# Date created:				17 Jan 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.8.1
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU Compiler Collection 2.8

NOT_FOR_ARCHS=	amd64 sparc64 ia64
NO_CDROM=	'old version, not worth the cost in real estate'

LATEST_LINK=	gcc28

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB=	GNUHOST=${CONFIGURE_TARGET}
CONFIGURE_ARGS=	--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/2.8.1/include/g++
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	bootstrap
MAN1=		cccp28.1 g++28.1 gcc28.1

pre-everything::
	@${ECHO_MSG} "GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}"

pre-patch:
	@${MV} ${WRKSRC}/config/i386/freebsd.h ${WRKSRC}/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/config/i386/freebsd-elf.h ${WRKSRC}/config/i386/freebsd.h

pre-configure:
	@# Keep from running `autoconf' and `autoheader' since we modified
	@# configure.in by patching it.
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/configure
	@${TOUCH} ${TOUCH_FLAGS} ${WRKSRC}/cstamp-h.in
	@(cd ${WRKSRC}/config/${ARCH}/ ; \
	MAJ=`/sbin/sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd-aout.h freebsd-aout.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" \
		freebsd-aout.h.in >freebsd-aout.h ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__=[0-9]*:__FreeBSD__=$${MAJ}:" freebsd.h.in \
		>freebsd.h)

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/2.8.1/cc1 \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/2.8.1/cc1obj \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/2.8.1/cc1plus \
	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/2.8.1/cpp ; \
		do ${STRIP_CMD} $$prog ; \
		done)
	${LN} -f ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc28
	${LN} -f ${PREFIX}/bin/g++ ${PREFIX}/bin/g++28
	@${MV} ${PREFIX}/man/man1/cccp.1 ${PREFIX}/man/man1/cccp28.1
	@${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++28.1
	@${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc28.1
.for info in cpp gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
