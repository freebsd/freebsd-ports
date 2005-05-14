# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc-ooo
PORTVERSION=	3.4.1
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC} \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	releases/gcc-${PORTVERSION}
DISTFILES=	\
		gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-testsuite-${PORTVERSION}${EXTRACT_SUFX}

PATCH_SITES+=	http://www.nedprod.com/TnFOX/patches/
PATCHFILES+=	GCC3.4.0VisibilityPatch2.diff
PATCH_DIST_STRIP=	-p1

MAINTAINER?=	openoffice@FreeBSD.org
COMMENT?=	GNU Compiler Collection for OpenOffice.org

NO_LATEST_LINK=	yes

USE_BISON=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes
USE_REINPLACE=	yes

CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${PORTVERSION}
PATCH_WRKSRC=	${SRCDIR}
WRKSRC=		${WRKDIR}/build
SUFFIX=		-ooo
TARGLIB=	${PREFIX}/gcc-ooo/${CONFIGURE_TARGET}/${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-nls \
		--with-system-zlib \
		--with-libiconv-prefix=${LOCALBASE} \
		--program-suffix=${SUFFIX} \
		--libdir=${TARGLIB}/lib \
		--libexecdir=${TARGLIB}/libexec \
		--with-gxx-include-dir=${TARGLIB}/include/c++/
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
.if defined(WANT_SHAREDLIBS)
CONFIGURE_ARGS+=	--enable-shared
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib ${TARGLIB}
EXTRA_SHLIB=	libgcc_s
.else
CONFIGURE_ARGS+=	--disable-shared
.endif
ALL_TARGET=	bootstrap-lean
PLIST_SUB=	GCC_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1
MAN7=		fsf-funding.7 gfdl.7 gpl.7
INFO=		cpp cppinternals gcc gccinstall gccint

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL}  target=${CONFIGURE_TARGET}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-build:
	@${ECHO_MSG} "Consider running 'make check' before 'make install', especially"
	@${ECHO_MSG} "if you have not performed this build on -STABLE or -CURRENT."
	@${ECHO_MSG} "This assumes that you have the dejagnu port installed."

check: build
	cd ${WRKSRC}; export RUNTESTFLAGS='--target_board ''unix{-pthread}'''; ${GMAKE} -sk check

post-install: fake-manpages
.for f in c++ gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++
	if [ -e ${PREFIX}/bin/${f}${SUFFIX} ]; then \
	  ${STRIP_CMD} ${PREFIX}/bin/${f}${SUFFIX}; \
	fi
	if [ -e ${PREFIX}/man/man1/${f}.1 ]; then \
	  ${MV} -f ${PREFIX}/man/man1/${f}.1 \
	           ${PREFIX}/man/man1/${f}${SUFFIX}.1; \
	fi
.endfor
.for d in gcc-ooo
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	${ECHO_CMD} "r ${TMPPLIST}"		> ${WRKDIR}/ex.script
	${ECHO_CMD} "/Insert PLIST.lib"		>> ${WRKDIR}/ex.script
	${ECHO_CMD} "d"				>> ${WRKDIR}/ex.script
	${ECHO_CMD} "r ${WRKDIR}/PLIST.lib"	>> ${WRKDIR}/ex.script
	${ECHO_CMD} "x!"			>> ${WRKDIR}/ex.script
	${CP} -p ${TMPPLIST} ${TMPPLIST}.pre
	cd ${WRKDIR} ; ex < ex.script

fake-manpages:
	# man pages can only be generated if Perl >= 5.6 is installed, so
	# fake them on 4.x systems.
.for mp in ${_MANPAGES}
	( ${TEST} -e ${mp} || ${TOUCH} ${TOUCH_FLAGS} ${mp} )
.endfor

.include <bsd.port.post.mk>
