# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	g95
PORTVERSION=	3.5.${SNAPDATE}
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	maho/tree-ssa
#		http://people.redhat.com/dnovillo/pub/tree-ssa/snapshot/
DISTNAME=	tree-ssa-${SNAPDATE}

MAINTAINER?=	maho@FreeBSD.org
COMMENT=	GNU Fortran Compiler 90/95 from tree-ssa branch

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_PERL5_BUILD=yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

SNAPDATE=	20040130

.include <bsd.port.pre.mk>

CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}

SRCDIR=		${WRKDIR}/gcc
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc/${CONFIGURE_TARGET}/3.5-tree-ssa/
TARGLIBEXEC=	${PREFIX}/libexec/gcc/${CONFIGURE_TARGET}/3.5-tree-ssa/
PLIST_SUB=	GCC_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-gmp=${LOCALBASE} \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-suffix=tree-ssa \
		--disable-libmudflap \
		--enable-languages=c,f95
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib ${TARGLIB}
EXTRA_SHLIB=	libgcc_s
.else
CONFIGURE_ARGS+=	--disable-shared
.endif
.if defined(WANT_THREADS_SUPPORT)
CONFIGURE_ARGS+=	--enable-threads
#	?is this an ObjC only thing?
CONFIGURE_ARGS+=	--enable-threads=posix
.endif
ALL_TARGET=	bootstrap-lean
MAN1=		cpptree-ssa.1   gcctree-ssa.1   gcovtree-ssa.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp gcc gccint cppinternals gccinstall

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL} ${PORTOBJFORMAT}	target ${CONFIGURE_TARGET}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_MSG} "Consider running 'make check' before 'make install',"
	@${ECHO_MSG} "especially if you have not built port on -STABLE or -CURRENT."
	@${ECHO_MSG} "This assumes that you have the dejagnu port installed."

check: build
	cd ${WRKSRC}; export RUNTESTFLAGS='--target_board ''unix{-pthread}'''; ${GMAKE} -sk check

post-install:
	${LN} ${PREFIX}/bin/gfortrantree-ssa ${PREFIX}/bin/gfortran
	${LN} ${PREFIX}/bin/gfortrantree-ssa ${PREFIX}/bin/g95

.for f in gcc cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++ gcj gcjh gij jv-scan jcf-dump jv-convert jar grepjar rmic rmiregistry
	if [ -e ${PREFIX}/bin/${f}tree-ssa ]; then \
	  ${STRIP_CMD} ${PREFIX}/bin/${f}tree-ssa; \
	  ( ${TEST} ! -e ${PREFIX}/man/man1/${f}.1 \
		|| ${MV} -f ${PREFIX}/man/man1/${f}.1 \
		${PREFIX}/man/man1/${f}tree-ssa.1 ); \
	fi
.endfor

.for f in libgfortran libgfortranbegin libmudflap libmudflapth libiberty ${EXTRA_SHLIB}
	${MV} -f ${PREFIX}/lib/${f}.* ${TARGLIB}
.endfor
	${RM} -f ${PREFIX}/lib/libiberty.a
	${RM} -f ${TARGLIB}/*.la
# I am sick and tired of the anonyance that man pages can only be generated if
# perl 5.6 is installed.  This is becoming a royal PITA on non-5-CURRENT systems
.for mp in ${_MANPAGES}
	( ${TEST} -e ${mp} || ${TOUCH} ${TOUCH_FLAGS} ${mp} )
.endfor
	# Handle target libraries and GCJ include files.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${TARGLIBEXEC:S/^${PREFIX}\///} include/gcj include/gnu include/java include/javax
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	(${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc 2>&1 || true") >> ${WRKDIR}/PLIST.lib
	(${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc/${CONFIGURE_TARGET} 2>&1 || true" ; ${ECHO_CMD} "@unexec ${RMDIR} %D/libexec/gcc 2>&1 || true") >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.lib"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre
	cd ${WRKDIR} ; ex < ex.script

cklatest:

.include <bsd.port.post.mk>
