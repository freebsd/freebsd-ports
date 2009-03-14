# ex:ts=8
# Ports collection makefile for:	egcs
# Date created:				9 Jan 1998
# Whom:					John Polstra <jdp@polstra.com>
#
# $FreeBSD$
#

PORTNAME=	gcc
PORTVERSION=	3.3.6
PORTREVISION=	5
PORTEPOCH=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	releases/gcc-${PORTVERSION}
DISTFILES=	gcc-core-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g++-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-g77-${PORTVERSION}${EXTRACT_SUFX} \
		gcc-objc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 3.3

DEPRECATED=	fails to build on FreeBSD 8 and above, not a single complaint when it failed to build for half a year, closed upstream for half a decade
EXPIRATION_DATE=2009-03-03

SUFFIX=		33
LATEST_LINK=	gcc${SUFFIX}${PKGNAMESUFFIX}
NOT_FOR_ARCHS=	amd64 sparc64
USE_BISON=	build
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PERL5_BUILD=yes

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:C/${WRKDIR}//}/configure
NOMANCOMPRESS=	yes	# too hard to deal with differences on 5-cur and releng4

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
IGNORE=		does not support FreeBSD 8 and above
.endif

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${PORTVERSION}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc-lib/${CONFIGURE_TARGET}/${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--host=${CONFIGURE_TARGET} --target=${CONFIGURE_TARGET} \
		--disable-nls \
		--with-system-zlib \
		--program-suffix=${SUFFIX} \
		--libdir=${TARGLIB} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
MAKE_ENV=	LD_LIBRARY_PATH=.:${WRKSRC}/gcc
ALL_TARGET=	bootstrap-lean
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VER=${PORTVERSION} GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		g77-${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/g77 \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccint

pre-everything::
	@${ECHO_MSG} "Making GCC ${DISTNAME:S/^gcc-//} for ${OPSYS} ${OSREL}  target=${CONFIGURE_TARGET}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(const char version_string.*\)";|\1 [FreeBSD]";|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${LN} -sf ${FILESDIR}/freebsd7.h ${SRCDIR}/gcc/config
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
.for f in c++ g77 gcc g++ cpp gcov ${CONFIGURE_TARGET}-gcc ${CONFIGURE_TARGET}-g++
	# gij and jv-convert, for example, are not built on all platforms.
	if [ -e ${PREFIX}/man/man1/${f}.1 ]; then \
	  ${MV} -f ${PREFIX}/man/man1/${f}.1 \
	           ${PREFIX}/man/man1/${f}${SUFFIX}.1; \
	fi
.endfor
	${MV} -f ${PREFIX}/bin/g77${SUFFIX} ${PREFIX}/bin/g77-${SUFFIX}
	-${MV} -f ${PREFIX}/man/man1/g77${SUFFIX}.1 ${PREFIX}/man/man1/g77-${SUFFIX}.1
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	${RM} -f ${TARGLIB}/*.la
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} include/gnu
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc-lib/${CONFIGURE_TARGET} 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	${ECHO_CMD} "@unexec ${RMDIR} %D/lib/gcc-lib 2>&1 || true" >> ${WRKDIR}/PLIST.lib
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
