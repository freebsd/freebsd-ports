# ex:ts=8
# Ports collection makefile for:	gcc
# Date created:				17 Jan 1998
# Whom:					David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	2.7.2.3
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU}  \
		ftp://ftp.gnu.org/gnu/libg++/  \
		ftp://ftp.duke.edu/pub/gnu/libg++/  \
		ftp://ftp.net.ohio-state.edu/disk/c/gnu/gnu-0.2/src/
MASTER_SITE_SUBDIR=	gcc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} libg++-2.7.2${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Base C/C++ compiler from FreeBSD 2.2.x & 3.x (for your old code)

DEPRECATED=	"This port is no longer in use by anything in the ports collection and will be removed in the future.  Use a later release instead"

NOT_FOR_ARCHS=	amd64 sparc64 ia64
NO_CDROM=	'old version, not worth the cost in real estate'

LATEST_LINK=	gcc27

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=		"Does not compile"
.endif

GCC_VER=	2.7.2.3
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
PLIST_SUB=	GNUHOST=${CONFIGURE_TARGET} GCC_VER=${GCC_VER}
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld --with-stabs  \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}/include/g++
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	bootstrap
MAN1=		cccp27.1 g++27.1 gcc27.1

pre-everything::
	@${ECHO_MSG} "GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}"

pre-patch:
	@${MV} ${WRKSRC}/config/i386/freebsd.h ${WRKSRC}/config/i386/freebsd-aout.h

pre-configure:
	@(MAJ=`/sbin/sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__[0-9=]*:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h.${ARCH} \
		>${WRKSRC}/config/${ARCH}/freebsd.h )

XGCC=	"${WRKSRC}/stage2/xgcc -B${WRKSRC}/stage2/"
post-build:
	cd ${WRKDIR}/libg++-2.7.2 ; env CC=${XGCC} CXX=${XGCC} ./configure ${CONFIGURE_ARGS}
	cd ${WRKDIR}/libg++-2.7.2 ; ${SETENV} ${MAKE_ENV} ${GMAKE} CC=${XGCC} CXX=${XGCC}

post-install:
	cd ${WRKDIR}/libg++-2.7.2 ; ${SETENV} ${MAKE_ENV} ${GMAKE} CC=${XGCC} CXX=${XGCC} install
	@${RM} -f ${PREFIX}/bin/c++ \
		${PREFIX}/bin/genclass ${PREFIX}/bin/gperf  \
		${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize  \
		${PREFIX}/man/man1/gperf.1 ${PREFIX}/man/man1/configure.1
	@${RM} -rf ${PREFIX}/bin/c++ ${PREFIX}/${CONFIGURE_TARGET}
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}/cc1 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}/cc1obj \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}/cc1plus \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}/cpp ; \
	    do ${STRIP_CMD} $$prog ; \
	done)
	@${MV} -f ${PREFIX}/bin/gcc ${PREFIX}/bin/gcc27
	@${MV} -f ${PREFIX}/bin/g++ ${PREFIX}/bin/g++27
	@${MV} ${PREFIX}/man/man1/cccp.1 ${PREFIX}/man/man1/cccp27.1
	@${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/g++27.1
	@${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/gcc27.1
	@${RM} -rf ${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}/g++-include
	@${MV}  ${PREFIX}/lib/libg++.a ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/libstdc++.a ${PREFIX}/lib/g++-include  \
			${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_VER}

.include <bsd.port.post.mk>
