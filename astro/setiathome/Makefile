# Ports collection makefile for:    setiathome
# Version required:     0.46
# Date created:         22 Apr 1999
# Whom:                 stb@freebsd.org
#
# $Id: Makefile,v 1.3 1999/04/22 02:00:16 stb Exp $
#

PKGNAME=	setiathome-0.46
CATEGORIES=	astro
MASTER_SITES=   http://setiathome.ssl.berkeley.edu/software/ \
		http://www.freebsd.org/~stb/mirror/setiathome.ssl.berkeley.edu/software/

MAINTAINER=	stb@freebsd.org

ONLY_FOR_ARCHS=	i386

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 310000
DISTFILES=      setiathome-0.46.i386-unknown-freebsd3.1.tar
WRKSRC=         setiathome-0.46.i386-unknown-freebsd3.1
.elif ${OSVERSION} >= 228000
DISTFILES=      setiathome-0.46.i386-unknown-freebsd2.2.8.tar
WRKSRC=         setiathome-0.46.i386-unknown-freebsd2.2.8
.elif ${OSVERSION} >= 227000
DISTFILES=      setiathome-0.46.i386-unknown-freebsd2.2.7.tar
WRKSRC=         setiathome-0.46.i386-unknown-freebsd2.2.7
.elif ${OSVERSION} >= 226000
DISTFILES=      setiathome-0.46.i386-unknown-freebsd2.2.6.tar
WRKSRC=         setiathome-0.46.i386-unknown-freebsd2.2.6
.else
DISTFILES=
.endif

.if make(makesum)
DISTFILES=	setiathome-0.46.i386-unknown-freebsd2.2.6.tar	\
			setiathome-0.46.i386-unknown-freebsd2.2.7.tar	\
			setiathome-0.46.i386-unknown-freebsd2.2.8.tar	\
			setiathome-0.46.i386-unknown-freebsd3.1.tar
.endif

NO_BUILD=	"binary distribution"

MAN1=		setiathome.1

pre-fetch:
	@if [ -z "${DISTFILES}" ]; then \
		${ECHO} "It seems you are running FreeBSD `uname -r`, which is not currently";	\
		${ECHO} "supported.  SETI@home currently supports only FreeBSD 2.2.6 and above,";	\
		${ECHO} "and FreeBSD 3.1."; \
		${ECHO} \
		exit 72; \
	fi;

do-install:
	${INSTALL_PROGRAM}	${WRKDIR}/${WRKSRC}/setiathome ${PREFIX}/bin
	${INSTALL_MAN}		${FILESDIR}/setiathome.1 ${MAN1PREFIX}/man/man1

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGDIR}/INSTALL ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
