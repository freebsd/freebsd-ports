# New ports collection makefile for:	llvm-gcc4
# Date created:				25 Jul 2007
# Whom:					Max Khon
#
# $FreeBSD$
#

PORTNAME=	gcc4
PORTVERSION=	2.6
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	llvm-
DISTNAME=	${PKGNAMEPREFIX}gcc-4.2-${PORTVERSION}.source

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	A gcc4 frontend for LLVM

BUILD_DEPENDS+=	llc:${PORTSDIR}/devel/llvm
BUILD_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils
RUN_DEPENDS+=	${LOCALBASE}/bin/as:${PORTSDIR}/devel/binutils

CONFLICTS=	llvm-devel-[0-9]* llvm-2.[0-5]*

GNU_CONFIGURE=	yes
USE_BISON=	build
USE_GCC=	4.2+
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes

GCC_VER=	4.2.1
WRKSRC=		${WRKDIR}/${DISTNAME:S/gcc-/gcc/}/obj
TARGLIB=	${PREFIX}/lib/llvm-gcc-${PORTVERSION}
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--enable-llvm=${LOCALBASE} \
		--enable-languages=c,c++ \
		--disable-nls \
		--with-system-zlib \
		--with-as=${LOCALBASE}/bin/as \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-prefix=llvm- \
		--libdir=${TARGLIB} \
		--with-gxx-include-dir=${TARGLIB}/include/c++ \
		--libexecdir=${TARGLIB} \
		--infodir=${PREFIX}/llvm-gcc
.if defined(MAINTAINER_MODE)
CONFIGURE_ARGS+=	--enable-checking
.endif
PLIST_SUB=	GCC_VER=${GCC_VER} \
		GNU_HOST=${CONFIGURE_TARGET}
INFO=		llvm-gcc/cpp \
		llvm-gcc/cppinternals \
		llvm-gcc/gcc \
		llvm-gcc/gccinstall \
		llvm-gcc/gccint \
		llvm-gcc/libgomp
MAN1=		llvm-cpp.1 llvm-g++.1 llvm-gcc.1 llvm-gcov.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--disable-shared
.endif

.if ${ARCH} == "sparc64"
IGNORE=		does not install: not yet supported on sparc64
.endif

post-extract:
	@${MKDIR} ${WRKSRC}

post-install:
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///}
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
