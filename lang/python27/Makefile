# New ports collection makefile for:    python
# Version required:     1.5
# Date created:         08 August 1995
# Whom:                 jkh
#
# $Id: Makefile,v 1.42 1998/12/02 08:24:49 asami Exp $
#

DISTNAME=       py152b1
PKGNAME=        python-1.5.2b1
CATEGORIES=	lang python tk80
MASTER_SITES=	ftp://www.python.org/pub/python/src/ \
		ftp://ftp.cwi.nl/pub/python/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tg@FreeBSD.ORG

LIB_DEPENDS=	${TK_DEPENDS}

DIST_SUBDIR=	python
WRKSRC=		${WRKDIR}/Python-1.5.2b1
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-fpectl
MAKE_FLAGS=	'OPT=${CFLAGS}'
INSTALL_TARGET=	install
PLIST=		${WRKDIR}/PLIST
MAN1=		python.1

#
# The standard setup file
#
SETUP_FILE=	Setup

#
# Support for Tk is compiled in by default.
#
WITH_TK?=	yes
.if defined(WITH_TK) && $(WITH_TK) == yes
TK_DEPENDS=	tk80.1:${PORTSDIR}/x11-toolkits/tk80
SETUP_LOCAL=	Setup.tk
.endif

#
# If you want to use Python's thread module, you need to set WITH_THREADS
# to 'yes', and you must have the FreeBSD threading c library (libc_r)
# installed. See 'man 3 pthread' for details on libc_r.
#
# This option is enabled by default.
#
WITH_THREADS?=	yes
LIBC_R!=	/sbin/ldconfig -r | grep c_r || true
.if ${LIBC_R} != "" && defined(WITH_THREADS) && ${WITH_THREADS} == yes
CONFIGURE_ARGS+=	--with-thread
CFLAGS+=		-D_THREAD_SAFE
CONFIGURE_ENV=		LDFLAGS="-pthread ${LDFLAGS}"
.endif

#
# The mpz module is built on machines with a full source tree
#
.if exists(/usr/src/contrib/libgmp/gmp-impl.h)
SETUP_LOCAL+=	Setup.gmp
PLIST_GMP=	lib/python1.5/lib-dynload/mpzmodule.so
.endif

post-extract:
	cd ${WRKSRC}/Lib; ${SH} ${FILESDIR}/plat-freebsd2.sh; \
		${SH} ${FILESDIR}/plat-freebsd3.sh

post-configure:
	${CP} ${FILESDIR}/${SETUP_FILE} ${WRKSRC}/Modules/Setup
.for file in ${SETUP_LOCAL}
	${CAT} ${FILESDIR}/${file} >> ${WRKSRC}/Modules/Setup.local
.endfor

.include <bsd.port.pre.mk>

.if ${PORTOBJFORMAT} == elf
LDFLAGS+=	-rdynamic
CONFIGURE_ENV?=	LDFLAGS="${LDFLAGS}"
.endif

pre-install:
.if ${OSVERSION} < 300000
	${MKDIR} ${PREFIX}/lib/python1.5/plat-freebsd3
	${INSTALL_DATA} ${WRKSRC}/Lib/plat-freebsd3/* ${PREFIX}/lib/python1.5/plat-freebsd3
.else
	${MKDIR} ${PREFIX}/lib/python1.5/plat-freebsd2
	${INSTALL_DATA} ${WRKSRC}/Lib/plat-freebsd2/* ${PREFIX}/lib/python1.5/plat-freebsd2
.endif
	@${ECHO} ${PLIST_GMP} | sort -r -o ${PLIST} - ${PKGDIR}/PLIST

post-install:
	${INSTALL_SCRIPT} ${PREFIX}/lib/python1.5/plat-freebsd2/regen ${PREFIX}/lib/python1.5/plat-freebsd3
	strip ${PREFIX}/bin/python
	@${MKDIR} ${PREFIX}/share/doc/python
	${INSTALL_DATA} ${WRKSRC}/Misc/COPYRIGHT ${PREFIX}/share/doc/python

.include <bsd.port.post.mk>
