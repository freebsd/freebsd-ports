# ex:ts=8
# Ports collection makefile for:  pgcc
# Date created:			  10 Dec 1998
# Whom:				  David O'Brien <obrien@NUXI.com>
#
# $FreeBSD$
#

PORTNAME=	pgcc
PORTVERSION=	2.95.2
CATEGORIES=	lang
MASTER_SITES=	ftp://go.cygnus.com/pub/sourceware.cygnus.com/pub/egcs/releases/${DISTNAME}/ \
		ftp://egcs.cygnus.com/pub/egcs/releases/${DISTNAME}/ \
		${MASTER_SITE_GNU} \
		ftp://ftp.nluug.nl/pub/languages/egcs/releases/${DISTNAME}/ \
		ftp://ftp.iij.ad.jp/pub/egcs/releases/${DISTNAME}/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/${DISTNAME}/
MASTER_SITE_SUBDIR=	gcc
DISTNAME=	gcc-${PORTVERSION}
DISTFILES=	gcc-core-${DISTNAME:S/gcc-//g}${EXTRACT_SUFX} \
		gcc-g++-${DISTNAME:S/gcc-//g}${EXTRACT_SUFX} \
		gcc-g77-${DISTNAME:S/gcc-//g}${EXTRACT_SUFX} \
		gcc-java-${DISTNAME:S/gcc-//g}${EXTRACT_SUFX} \
		gcc-objc-${DISTNAME:S/gcc-//g}${EXTRACT_SUFX}

PATCH_SITES=	http://www.gcc.ml.org/data/source/  \
		ftp://ftp.goof.com/pub/pcg/source/  \
		ftp://ftp.hitachi-sk.co.jp/pub/pentium-gcc/source/  \
		ftp://ftp.fu-berlin.de/unix/languages/pgcc/source/
PATCHFILES=	gcc-2.95.2-pgcc-2.95.3.diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=  autoconf:${PORTSDIR}/devel/autoconf

ONLY_FOR_ARCHS=	i386

USE_BZIP2=	yes

.include <bsd.port.pre.mk>

GCC_REV=	p${DISTNAME}
LIBSTDCPP_REV=	4

.if ${PORTOBJFORMAT} == "elf"
PLIST=		${WRKDIR}/PLIST
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsdaout${OSREL}
.endif

PLIST_SUB=	EGCS_REV=${GCC_REV} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/include/g++
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+= --enable-shared
.endif
.if defined(WANT_THREADS)
#	?is this an ObjC only thing?
CONFIGURE_ARGS+= --enable-threads=posix
.endif
ALL_TARGET=	bootstrap
MAN1=		cccp.1 pg++.1 pg77.1 pgcc.1

pre-patch:
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd.h ${WRKSRC}/gcc/config/i386/freebsd-aout.h
	@${MV} ${WRKSRC}/gcc/config/i386/freebsd-elf.h ${WRKSRC}/gcc/config/i386/freebsd.h

pre-configure:
	@(MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${SED} -e "s:__FreeBSD__[0-9=]*:__FreeBSD__=$${MAJ}:" ${FILESDIR}/freebsd.h \
		>${WRKSRC}/gcc/config/freebsd.h )
.if ${PORTOBJFORMAT} == "elf" && ${MACHINE_ARCH} == "i386"
	@${SED} -e 's/^@comment ELF-only://' ${PKGDIR}/pkg-plist >${PLIST}
.endif

pre-install:
	${MKDIR} ${PREFIX}/info

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
		${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
		${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
		${PREFIX}/bin/${CONFIGURE_TARGET}-gcc \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1obj \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cc1plus \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/cpp \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/collect2 \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/f771 ; \
	do \
		strip $$prog ; \
	done)
	${MV} ${PREFIX}/bin/${CONFIGURE_TARGET}-gcc ${PREFIX}/bin/${CONFIGURE_TARGET}-pgcc
	${MV} ${PREFIX}/bin/gcc ${PREFIX}/bin/pgcc
	${MV} ${PREFIX}/bin/g++ ${PREFIX}/bin/pg++
	${MV} ${PREFIX}/bin/g77 ${PREFIX}/bin/pg77
	${MV} ${PREFIX}/bin/gcov ${PREFIX}/bin/pgcov
	${MV} ${PREFIX}/bin/g++filt ${PREFIX}/bin/pg++filt
	${MV} ${PREFIX}/bin/gcj ${PREFIX}/bin/pgcj
	${MV} ${PREFIX}/bin/gcjh ${PREFIX}/bin/pgcjh
	${MV} ${PREFIX}/bin/jv-scan ${PREFIX}/bin/pjv-scan
	${MV} ${PREFIX}/bin/jcf-dump ${PREFIX}/bin/pjcf-dump
	${RM} -f ${PREFIX}/bin/cpp
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a.${LIBSTDCPP_REV}  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}/libstdc++.a
	${MV} ${PREFIX}/man/man1/gcc.1 ${PREFIX}/man/man1/pgcc.1
	${MV} ${PREFIX}/man/man1/g++.1 ${PREFIX}/man/man1/pg++.1
	${MV} ${PREFIX}/man/man1/g77.1 ${PREFIX}/man/man1/pg77.1
.if defined(WANT_SHAREDLIBS)
	${MV} -f ${PREFIX}/lib/libstdc++.so*  \
		${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${GCC_REV}
.endif
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
