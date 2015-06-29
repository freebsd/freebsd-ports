# Created by: mat
# $FreeBSD$

PORTNAME=	perl
PORTVERSION=	${PERL_VERSION}
PORTREVISION=	15
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN/../../src/5.0
DIST_SUBDIR=	perl

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1=	${WRKSRC}/Copying

DEPRECATED=	Unsupported, please upgrade to a more recent version of Perl
EXPIRATION_DATE=2016-12-31

CONFLICTS_INSTALL=	perl5.*-*

OPTIONS_DEFINE=	DEBUG GDBM PERL_64BITINT PTHREAD \
		MULTIPLICITY SITECUSTOMIZE USE_PERL
# it seems perl malloc has problems with threaded perl on FreeBSD
OPTIONS_RADIO=	EXCLUSIVE
OPTIONS_RADIO_EXCLUSIVE=	THREADS PERL_MALLOC
OPTIONS_DEFAULT=	PERL_64BITINT THREADS PTHREAD USE_PERL MULTIPLICITY

EXCLUSIVE_DESC=	Exclusive OPTIONS
GDBM_DESC=	GDBM_File extension
PERL_MALLOC_DESC=	Use Perl malloc
PERL_64BITINT_DESC=	Use 64 bit integers (on i386)
THREADS_DESC=		Build threaded perl
PTHREAD_DESC=		Build with -lpthread
MULTIPLICITY_DESC=	Use multiplicity
SITECUSTOMIZE_DESC=	Run-time customization of @INC
USE_PERL_DESC=		Rewrite links in /usr/bin

#OPTIONS_EXCLUDE_AMD64=	THREADS
OPTIONS_SUB=		yes
DEBUG_CONFIGURE_ON=	-Doptimize="-g" -DDEBUGGING
DEBUG_CONFIGURE_OFF=	-Doptimize="${CFLAGS}"
GDBM_CONFIGURE_ON=	-Di_gdbm
GDBM_CONFIGURE_OFF=	-Ui_gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm
PERL_64BITINT_CONFIGURE_ON=	-Duse64bitint
MULTIPLICITY_CONFIGURE_ON=	-Dusemultiplicity=y
MULTIPLICITY_CONFIGURE_OFF=	-Dusemultiplicity=n
SITECUSTOMIZE_CONFIGURE_ON=	-Dusesitecustomize
THREADS_CONFIGURE_ON=	-Dusethreads=y
THREADS_CONFIGURE_OFF=	-Dusethreads=n
PERL_MALLOC_CONFIGURE_ON=	-Dusemymalloc=y
PERL_MALLOC_CONFIGURE_OFF=	-Dusemymalloc=n

PORTSCOUT=	limit:^${PERL_VER}.

# Remember to update Mk/Uses/perl5.mk too.
PERL_VERSION=	5.18.4
PERL_VER=	${PERL_VERSION:C/\.[0-9]+$//}
PERL_ARCH=	mach
SITE_PERL_REL?=	lib/perl5/site_perl
SITE_PERL?=	${PREFIX}/${SITE_PERL_REL}
SITE_ARCH_REL?=	${SITE_PERL_REL}/${PERL_ARCH}/${PERL_VER}
SITE_ARCH?=	${PREFIX}/${SITE_ARCH_REL}
SITE_MAN3_PREFIX=	${SITE_PERL_REL}
SITE_MAN3_REL?=	${SITE_MAN3_PREFIX}/man/man3
SITE_MAN3?=	${PREFIX}/${SITE_MAN3_REL}

_PRIV_LIB=	lib/perl5/${PERL_VER}
_ARCH_LIB=	${_PRIV_LIB}/${PERL_ARCH}

USES=	tar:bzip2 cpe
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Dlibperl=libperl.so.${PERL_VERSION} \
	-Darchlib=${PREFIX}/${_ARCH_LIB} \
	-Dprivlib=${PREFIX}/${_PRIV_LIB} \
	-Dman3dir=${PREFIX}/${MAN3PREFIX_REL}/man/man3 \
	-Dman1dir=${PREFIX}/man/man1 \
	-Dsitearch=${SITE_ARCH} \
	-Dsitelib=${SITE_PERL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${SITE_MAN3} \
	-Dsiteman1dir=${PREFIX}/man/man1 \
	-Dotherlibdirs=${PREFIX}/lib/perl5/site_perl/${PERL_VER}:${PREFIX}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH} \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl -Dusenm=n \
	-Dcc="${CC}" -Duseshrplib -Dinc_version_list=none \
	-Dcf_by=${MAINTAINER:C,@.*,,} -Dcf_email=${MAINTAINER} \
	-Dcf_time="`env LANG=C ${STAT} -t \"%a %b %d %T %Z %Y\" -f %Sm ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}`"
# Keep the following two in sync.
# lddlflags is used for all .so linking
# shrpldflags is used for libperl.so, so remove all the extra bits inherited from lddlflags.
CONFIGURE_ARGS+= \
	-Alddlflags='-L${WRKSRC} -L${PREFIX}/${_ARCH_LIB}/CORE -Wl,-rpath=${PREFIX}/${_ARCH_LIB}/CORE -lperl' \
	-Dshrpldflags='$$(LDDLFLAGS:N-L${WRKSRC}:N-L${PREFIX}/${_ARCH_LIB}/CORE:N-Wl,-rpath=${PREFIX}/${_ARCH_LIB}/CORE:N-lperl) -Wl,-soname,$$(LIBPERL:R)'
LOCALE_CLEANUP=	LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV+=	${LOCALE_CLEANUP} UNAME_v="$$(uname -v | sed 'y/=/ /')"
MAKE_ENV+=	${LOCALE_CLEANUP}

SUB_LIST+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		SITE_PERL=${SITE_PERL_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		MAN3PREFIX=${MAN3PREFIX_REL} \
		SITEMAN3PREFIX=${SITE_MAN3_PREFIX} \
		PERL_ARCH=${PERL_ARCH}

SUB_FILES=	perl5_version use.perl perl-man.conf

PKGINSTALL=	${WRKDIR}/use.perl
PKGDEINSTALL=	${WRKDIR}/use.perl
INSTALL_TARGET=	install-strip

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

# if this port is default due PERL5_DEFAULT
# change PKGNAME to reflect this
.if ${PERL_VER} == ${PERL5_DEFAULT}
PKGNAMESUFFIX=	${PERL_VERSION:C/\.[0-9]+\.[0-9]+$//}
.else
# make PKGNAME unique among other lang/perl5.x
PKGNAMESUFFIX=	${PERL_VER}
# always add default perl5 pkgname to conflicts
CONFLICTS_INSTALL+=	perl5-*
.endif

.if defined(PERL_VENDOR_PREFIX)
CONFIGURE_ARGS+=	\
	-Dvendorprefix=${PERL_VENDOR_PREFIX} \
	-Dvendorarch=${PERL_VENDOR_PREFIX}/${_ARCH_LIB} \
	-Dvendorbin=${PERL_VENDOR_PREFIX}/bin \
	-Dvendorlib=${PERL_VENDOR_PREFIX}/${_PRIV_LIB} \
	-Dvendorman3dir=${PERL_VENDOR_PREFIX}/${_PRIV_LIB}/man/man3 \
	-Dvendorman1dir=${PERL_VENDOR_PREFIX}/man/man1
.endif

# http://perl5.git.perl.org/perl.git/commit/b83080de5c4254
# PERLIOBUF_DEFAULT_BUFSIZ size in bytes (default: 8192 bytes)
.if defined(PERLIOBUF_DEFAULT_BUFSIZ)
CONFIGURE_ARGS+=	\
    -Accflags=-DPERLIOBUF_DEFAULT_BUFSIZ=${PERLIOBUF_DEFAULT_BUFSIZ}
.endif

MAN3PREFIX_REL=	${_PRIV_LIB}/perl
MAN3PREFIX=	${PREFIX}/${MAN3PREFIX_REL}
MANDIRS+=	${MAN3PREFIX}/man

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		PERL_ARCH=${PERL_ARCH} \
		MAN3=${MAN3PREFIX_REL}/man/man3 \
		MAN3PREFIX=${MAN3PREFIX_REL} \
		SITEMAN3PREFIX=${SITE_MAN3_PREFIX} \
		SITE_PERL=${SITE_PERL_REL} \
		SITE_ARCH=${SITE_ARCH_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		ARCH_LIB=${_ARCH_LIB}

.if ${PORT_OPTIONS:MDEBUG}
STRIP=
STRIP_CMD=	${TRUE}
.endif

.if ${OSVERSION} >= 900022
PLIST_SUB+=	MANCONF=""
.else
PLIST_SUB+=	MANCONF="@comment "
.endif

.if ${PORT_OPTIONS:MUSE_PERL}
LINK_USRBIN=	yes
.else
LINK_USRBIN=	no
.endif
SUB_LIST+=	LINK_USRBIN=${LINK_USRBIN}

# Put a symlink to the future libperl.so.x.yy so that -lperl works.
post-extract:
	${LN} -s libperl.so.${PERL_VERSION} ${WRKSRC}/libperl.so
	${LN} -s libperl.so.${PERL_VERSION} ${WRKSRC}/libperl.so.${PERL_VER}

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Configure ${WRKSRC}/hints/freebsd.sh
.if ${PORT_OPTIONS:MPTHREAD}
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|-lpthread|g;' \
		${WRKSRC}/hints/freebsd.sh
.else
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%||g;' \
		${WRKSRC}/hints/freebsd.sh
.endif

post-install:
	${MKDIR} ${STAGEDIR}${SITE_MAN3}
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/auto
	${MKDIR} ${STAGEDIR}${SITE_PERL}/auto
	${LN} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION} ${STAGEDIR}${PREFIX}/bin/perl5
	${LN} -sf libperl.so.${PERL_VERSION} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so
	${LN} -sf libperl.so.${PERL_VERSION} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so.${PERL_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
	${INSTALL_DATA} ${WRKDIR}/perl5_version ${STAGEDIR}${PREFIX}/etc
	${FIND} ${STAGEDIR} -name '*.bs' -size 0 -delete
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/machine
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/sys
	# h2ph needs perl, but perl is not installed, it's only
	# staged, so, use the one in WRKDIR 
	(cd /usr/include && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		${WRKSRC}/perl -I ${WRKSRC}/lib ${STAGEDIR}${PREFIX}/bin/h2ph \
		-d ${STAGEDIR}${SITE_ARCH} *.h machine/*.h sys/*.h >/dev/null)
	@${FIND} ${STAGEDIR}${SITE_ARCH} -name '*.ph' | sed -e 's|${STAGEDIR}||' >> ${TMPPLIST}
	${FIND} ${STAGEDIR} -name '*.so*' -type f | while read f; \
		do \
			${CHMOD} 644 $$f; \
			${STRIP_CMD} $$f; \
			${CHMOD} 444 $$f; \
		done
.if ${OSVERSION} >= 900022
	${INSTALL_DATA} ${WRKDIR}/perl-man.conf ${STAGEDIR}${PREFIX}/etc/man.d/perl${PERL_VER}.conf
.endif

test: build
	(cd ${WRKSRC}; TEST_JOBS=${MAKE_JOBS_NUMBER} make test_harness)

regression-test: test

.include <bsd.port.post.mk>
