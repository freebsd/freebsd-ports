# New ports collection makefile for:	llvm-gcc4
# Date created:				25 Jul 2007
# Whom:					Max Khon
#
# $FreeBSD$
#

PORTNAME=	gcc4
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	lang devel
MASTER_SITES=	http://llvm.org/releases/${PORTVERSION}/
PKGNAMEPREFIX=	llvm-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}.source

MAINTAINER=	fjoe@FreeBSD.org
COMMENT=	gcc4 frontend for LLVM

GNU_CONFIGURE=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_ICONV=	yes
USE_PERL5_BUILD=yes
ONLY_FOR_ARCHS=	i386 amd64

BUILD_DEPENDS=	${LOCALBASE}/bin/llc:${PORTSDIR}/devel/llvm

GCC_VER=	4.0.1
WRKSRC=		${WRKDIR}/${DISTNAME}/build
TARGLIB=	${PREFIX}/lib/gcc-llvm-${PORTVERSION}
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS=	--enable-llvm=${LOCALBASE}\
		--enable-languages=c,c++\
		--disable-nls\
		--with-system-zlib\
		--with-libiconv-prefix=${LOCALBASE}\
		--program-prefix=llvm-\
		--libdir=${TARGLIB}\
		--with-gxx-include-dir=${TARGLIB}/include/c++\
		--libexecdir=${TARGLIB}\
		--infodir=${PREFIX}/llvm-gcc
PLIST_SUB=	GCC_VER=${GCC_VER}\
		GNU_HOST=${CONFIGURE_TARGET}
INFO=		llvm-gcc/cpp \
		llvm-gcc/cppinternals \
		llvm-gcc/gcc \
		llvm-gcc/gccinstall \
		llvm-gcc/gccint
MAN1=		llvm-cpp.1 llvm-g++.1 llvm-gcc.1 llvm-gcov.1

post-patch:
	@${MKDIR} ${WRKSRC}
	@${REINPLACE_CMD} -e 's,LLVMBASEPATH/Release/bin/llc,LLVMBASEPATH/bin/llc,'\
	   	 ${WRKSRC}/../gcc/configure\
		 ${WRKSRC}/../libcpp/configure
	@${REINPLACE_CMD}\
	    -e 's,LLVMBINPATH = .*,LLVMBINPATH = @LLVMBASEPATH@/bin,'\
	    -e 's,LLVMSRCDIR := .*,LLVMSRCDIR = @LLVMBASEPATH@,'\
	    	${WRKSRC}/../gcc/Makefile.in

post-install:
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	${MV} -f ${PREFIX}/include/mf-runtime.h \
	         ${TARGLIB}/gcc/${CONFIGURE_TARGET}/4.0.1/include
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
CONFIGURE_ARGS+=	--disable-shared
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

.include <bsd.port.post.mk>
