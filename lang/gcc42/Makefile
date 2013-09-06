# Created by: Gerald Pfeifer <gerald@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gcc
PORTVERSION=	4.2.5.20090325
PORTREVISION=	5
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GCC}
MASTER_SITE_SUBDIR=	snapshots/${VERSIONSTRING}
DISTFILES=	gcc-core-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-g++-${VERSIONSTRING}${EXTRACT_SUFX} \
		gcc-objc-${VERSIONSTRING}${EXTRACT_SUFX}

MAINTAINER=	gerald@FreeBSD.org
COMMENT=	GNU Compiler Collection 4.2

LIB_DEPENDS=	gmp:${PORTSDIR}/math/gmp \
		mpfr:${PORTSDIR}/math/mpfr

DEPRECATED=	Superseded by GCC 4.6

VERSIONSTRING=	${PORTVERSION:C/([0-9]+\.[0-9]+).*\.([0-9]+)/\1-\2/}
SUFFIX=		${PORTVERSION:C/([0-9]+).([0-9]+).*/\1\2/}
LATEST_LINK=	gcc${SUFFIX}${PKGNAMESUFFIX}
NOT_FOR_ARCHS=	arm powerpc
USES=		bison gmake iconv perl5
USE_BZIP2=	yes
USE_CSTD=	gnu89
USE_PERL5=	build

PATCH_WRKSRC=	${SRCDIR}
CONFIGURE_SCRIPT=	../${SRCDIR:S/${WRKDIR}\///}/configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CONFIGURE_TARGET=	x86_64-portbld-freebsd${OSREL}
.else
CONFIGURE_TARGET=	${ARCH}-portbld-freebsd${OSREL}
.endif

SRCDIR=		${WRKDIR}/gcc-${VERSIONSTRING}
WRKSRC=		${WRKDIR}/build
TARGLIB=	${PREFIX}/lib/gcc${SUFFIX}
LIBEXEC=	${PREFIX}/libexec/gcc${SUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--disable-bootstrap \
		--disable-nls \
		--libdir=${TARGLIB} \
		--libexecdir=${LIBEXEC} \
		--program-suffix=${SUFFIX} \
		--with-as=/usr/bin/as \
		--with-gmp=${LOCALBASE} \
		--with-gxx-include-dir=${TARGLIB}/include/c++/ \
		--with-ld=/usr/bin/ld \
		${ICONV_CONFIGURE_ARG} \
		--with-pkgversion="FreeBSD Ports Collection" \
		--with-system-zlib
MAKE_ARGS+=	MAKEINFOFLAGS="--no-split"
USE_LDCONFIG=	${TARGLIB}
PLIST_SUB=	GCC_VER=${PORTVERSION:C/(.+)\.[0-9]+/\1/} \
		GNU_HOST=${CONFIGURE_TARGET} \
		SUFFIX=${SUFFIX}
MAN1=		cpp${SUFFIX}.1 \
		g++${SUFFIX}.1 \
		gcc${SUFFIX}.1 \
		gcov${SUFFIX}.1
INFO=		gcc${SUFFIX}/cpp \
		gcc${SUFFIX}/cppinternals \
		gcc${SUFFIX}/gcc \
		gcc${SUFFIX}/gccinstall \
		gcc${SUFFIX}/gccint \
		gcc${SUFFIX}/libgomp

pre-everything::
	@${ECHO_MSG} "Making GCC ${PORTVERSION} for ${OPSYS} ${OSREL}  target=${CONFIGURE_TARGET}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(#define VERSUFFIX.*\)"|\1 [FreeBSD Ports Collection]"|' \
	    ${SRCDIR}/gcc/version.c

pre-configure:
	cd ${SRCDIR} ; contrib/gcc_update --touch
	@${RM} -f ${SRCDIR}/gcc/*/*.info*
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
	${RM} -f ${PREFIX}/man/man7/fsf-funding.7 \
	         ${PREFIX}/man/man7/gfdl.7 ${PREFIX}/man/man7/gpl.7
	${RM} -f ${TARGLIB}/*.la
	# Add target libraries and include files to packaging list.
	${RM} -f ${WRKDIR}/PLIST.lib
.for d in ${TARGLIB:S/^${PREFIX}\///} ${LIBEXEC:S/^${PREFIX}\///}
	cd ${PREFIX} ; if [ -d $d ]; then \
	    ${FIND} $d -type f -o -type l >>${WRKDIR}/PLIST.lib ;\
	    ${FIND} $d -type d | ${SORT} -r \
	        | ${SED} -e 's/^/@dirrm /g' >>${WRKDIR}/PLIST.lib ;\
	fi
.endfor
	cd ${WRKDIR} ; ${SED} -i -e "/PLIST.lib/ r PLIST.lib" ${TMPPLIST}

.include <bsd.port.post.mk>
