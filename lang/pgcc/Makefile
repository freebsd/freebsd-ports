# ex:ts=8
# Ports collection makefile for:	egcs
# Version required: 			1998-09-14
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $Id: Makefile,v 1.41 1998/12/05 04:00:40 obrien Exp $
#

DISTNAME=	egcs-1.1.1
PKGNAME=	pgcc-1.1.1
CATEGORIES=	lang
MASTER_SITES=	ftp://go.cygnus.com/pub/ftp.cygnus.com/egcs/releases/egcs-1.1.1/ \
		ftp://ftp.funet.fi/mirrors/ftp.cygnus.com/pub/egcs/releases/egcs-1.1.1/ \
		ftp://egcs.cygnus.com/pub/egcs/releases/egcs-1.1.1/ \
		ftp://ftp.fu-berlin.de/unix/languages/egcs/releases/egcs-1.1.1/ \
		ftp://cambridge.cygnus.com/pub/egcs/releases/egcs-1.1.1/
EXTRACT_SUFX=	.tar.bz2

PATCH_SITES=	http://www.gcc.ml.org/data/source/  \
		ftp://ftp.goof.com/pub/pcg/source/  \
		ftp://ftp.hitachi-sk.co.jp/pub/pentium-gcc/source/  \
		ftp://ftp.fu-berlin.de/unix/languages/pgcc/source/
PATCHFILES=	egcs-1.1.1-pgcc-1.1.1.diff.gz

MAINTAINER=	obrien@FreeBSD.org

BUILD_DEPENDS=  bzip2:${PORTSDIR}/archivers/bzip2

.include <bsd.port.pre.mk>

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS=	-dc
EXTRACT_AFTER_ARGS=	| /usr/bin/tar -xf -
EGCS_REV=	egcs-2.91.60
LIBSTDCPP_REV=	2.9.0

.if ${PORTOBJFORMAT} == "elf"
#GNUHOST=	${ARCH}-unknown-freebsdelf${OSREL}
GNUHOST=	${ARCH}-unknown-freebsdelf
.else
#GNUHOST=	${ARCH}-unknown-freebsd${OSREL}
GNUHOST=	${ARCH}-unknown-freebsd
.endif

PATCH_DIST_STRIP?=	-p1
PLIST_SUB=	EGCS_REV=${EGCS_REV} GNU_HOST=${GNUHOST}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	--with-gnu-as --with-gnu-ld ${GNUHOST} \
		--with-gxx-include-dir=${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/include/g++
ALL_TARGET=	bootstrap
MAN1=		cccp.1 g++.1 g77.1 gcc.1

pre-configure:
	@(cd ${WRKSRC}/gcc/config/${ARCH}/ ; \
	MAJ=`sysctl -n kern.osreldate | ${SED} -e '/.....$$/s///'` ; \
	${MV} freebsd.h freebsd.h.in ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" freebsd.h.in >freebsd.h ; \
	${MV} freebsd-elf.h freebsd-elf.h.in ; \
	${SED} -e "s:__FreeBSD__:__FreeBSD__=$${MAJ}:" freebsd-elf.h.in >freebsd-elf.h)

pre-install:
	${MKDIR} ${PREFIX}/info
	${TOUCH} ${PREFIX}/info/dir

post-install:
	@${RM} -f ${PREFIX}/bin/c++
	@${MV} -f ${PREFIX}/bin/c++filt ${PREFIX}/bin/g++filt
	@(for prog in ${PREFIX}/bin/gcc ${PREFIX}/bin/g++ \
	${PREFIX}/bin/g++filt ${PREFIX}/bin/g77 ${PREFIX}/bin/gcov \
	${PREFIX}/bin/protoize ${PREFIX}/bin/unprotoize \
	${PREFIX}/bin/${GNUHOST}-gcc \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cc1 \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cc1obj \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cc1plus \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/cpp \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/collect2 \
	${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/f771 ; \
		do strip $$prog ; \
		done)
	ln -f ${PREFIX}/bin/gcc ${PREFIX}/bin/egcc
	ln -f ${PREFIX}/bin/g++ ${PREFIX}/bin/eg++
	${MV} ${PREFIX}/lib/libiberty.a  \
		${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}
	${MV} -f ${PREFIX}/lib/libstdc++.a  \
		${PREFIX}/lib/gcc-lib/${GNUHOST}/${EGCS_REV}/libstdc++.a
	if [ ! -f ${PREFIX}/info/dir ]; then \
	    ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	fi
.for info in cpp g77 gcc
	install-info ${PREFIX}/info/${info}.info ${PREFIX}/info/dir
.endfor

.include <bsd.port.post.mk>
