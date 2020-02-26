# $FreeBSD$

PORTNAME=	perl
DISTVERSION=	${PERL_VERSION}
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN/../../src/5.0/
DIST_SUBDIR=	perl

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/Copying

# Uncomment when the default Perl is switched to 5.28
DEPRECATED=	Support ends three years after .0 release, please upgrade to a more recent version of Perl
EXPIRATION_DATE=2020-05-31

TEST_TARGET=	test_harness
TEST_ENV=	${MAKE_ENV} TEST_JOBS=${MAKE_JOBS_NUMBER} \
		LD_LIBRARY_PATH=${WRKSRC}

OPTIONS_DEFINE=	DEBUG GDBM PERL_64BITINT MULTIPLICITY SITECUSTOMIZE \
		THREADS PERL_MALLOC DTRACE DOT_INC
OPTIONS_DEFAULT=	PERL_64BITINT THREADS MULTIPLICITY DTRACE

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE+=	DTRACE
.endif
.for a in aarch64 arm armv6 armv7 \
	mips mips64 mips64el mips64elhf mips64hf mipsel mipselhf mipshf mipsn32 \
	powerpc powerpc64 powerpcspe \
	riscv64 riscv64sf sparc64
OPTIONS_EXCLUDE_${a}=	DTRACE
.endfor

EXCLUSIVE_DESC=	Exclusive OPTIONS
GDBM_DESC=	GDBM_File extension
PERL_MALLOC_DESC=	Use Perl malloc
PERL_64BITINT_DESC=	Use 64 bit integers (on i386)
THREADS_DESC=		Build threaded perl
MULTIPLICITY_DESC=	Use multiplicity
SITECUSTOMIZE_DESC=	Run-time customization of @INC
DOT_INC_DESC=		Add '.' to @INC (unsafe)

OPTIONS_SUB=		yes
DEBUG_CONFIGURE_ON=	-Doptimize="-g" -DDEBUGGING
DEBUG_CONFIGURE_OFF=	-Doptimize="${CFLAGS}"
DTRACE_CONFIGURE_ON=	-Dusedtrace
DTRACE_CONFIGURE_OFF=	-Uusedtrace
GDBM_CONFIGURE_ON=	-Di_gdbm
GDBM_CONFIGURE_OFF=	-Ui_gdbm
GDBM_LIB_DEPENDS=	libgdbm.so:databases/gdbm
PERL_64BITINT_CONFIGURE_ON=	-Duse64bitint
MULTIPLICITY_CONFIGURE_ON=	-Dusemultiplicity=y
MULTIPLICITY_CONFIGURE_OFF=	-Dusemultiplicity=n
SITECUSTOMIZE_CONFIGURE_ON=	-Dusesitecustomize
THREADS_CONFIGURE_ON=	-Dusethreads=y
THREADS_CONFIGURE_OFF=	-Dusethreads=n
PERL_MALLOC_CONFIGURE_ON=	-Dusemymalloc=y
PERL_MALLOC_CONFIGURE_OFF=	-Dusemymalloc=n
DOT_INC_CONFIGURE_ON=		-Ddefault_inc_excludes_dot=n

PORTSCOUT=	limit:^${PERL_VER}.

.include "version.mk"
PERL_VER?=	${PERL_VERSION:C/\.[0-9]+$//}
PERL_ARCH=	mach
SITE_PERL_REL?=	lib/perl5/site_perl
SITE_PERL?=	${PREFIX}/${SITE_PERL_REL}
SITE_ARCH_REL?=	${SITE_PERL_REL}/${PERL_ARCH}/${PERL_VER}
SITE_ARCH?=	${PREFIX}/${SITE_ARCH_REL}
SITE_MAN_PREFIX=	${SITE_PERL_REL}
SITE_MAN3_REL?=	${SITE_MAN_PREFIX}/man/man3
SITE_MAN3?=	${PREFIX}/${SITE_MAN3_REL}
SITE_MAN1_REL?=	${SITE_MAN_PREFIX}/man/man1
SITE_MAN1?=	${PREFIX}/${SITE_MAN1_REL}

_PRIV_LIB=	lib/perl5/${PERL_VER}
_ARCH_LIB=	${_PRIV_LIB}/${PERL_ARCH}

USES=	cpe tar:xz

HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Dlibperl=libperl.so.${PERL_VERSION} \
	-Darchlib=${PREFIX}/${_ARCH_LIB} \
	-Dprivlib=${PREFIX}/${_PRIV_LIB} \
	-Dman3dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man3 \
	-Dman1dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man1 \
	-Dsitearch=${SITE_ARCH} \
	-Dsitelib=${SITE_PERL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${SITE_MAN3} \
	-Dsiteman1dir=${SITE_MAN1} \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl -Dusenm=n \
	-Dcc="${CC}" -Duseshrplib -Dinc_version_list=none \
	-Dcf_by=${MAINTAINER:C,@.*,,} -Dcf_email=${MAINTAINER} \
	-Dcf_time="`${STAT} -t \"%a %b %d %T %Z %Y\" -f %Sm ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}`"
# Keep the following two in sync.
# lddlflags is used for all .so linking
# shrpldflags is used for libperl.so, so remove all the extra bits inherited from lddlflags.
CONFIGURE_ARGS+=	\
	-Alddlflags='-L${WRKSRC} -L${PREFIX}/${_ARCH_LIB}/CORE -lperl' \
	-Dshrpldflags='$$(LDDLFLAGS:N-L${WRKSRC}:N-L${PREFIX}/${_ARCH_LIB}/CORE:N-lperl) -Wl,-soname,$$(LIBPERL:R)'

# Give a hint of where libperl.so can be found.
USE_LDCONFIG=	${PREFIX}/${_ARCH_LIB}/CORE

CONFIGURE_ENV+=	UNAME_v="$$(uname -v | sed 'y/=/ /')"

SUB_LIST+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		SITE_PERL=${SITE_PERL_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		PERLMANPREFIX=${PERLMANPREFIX_REL} \
		SITEMANPREFIX=${SITE_MAN_PREFIX} \
		PERL_ARCH=${PERL_ARCH}

SUB_FILES=	perl-man.conf

INSTALL_TARGET=	install-strip

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

PERLMANPREFIX_REL=	${_PRIV_LIB}/perl
PERLMANPREFIX=	${PREFIX}/${PERLMANPREFIX_REL}
MANDIRS+=	${PERLMANPREFIX}/man

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VER} \
		PERL_ARCH=${PERL_ARCH} \
		PERL_ARCH_regex=\b${PERL_ARCH}\b \
		MAN1=${PERLMANPREFIX_REL}/man/man1 \
		MAN3=${PERLMANPREFIX_REL}/man/man3 \
		PERLMANPREFIX=${PERLMANPREFIX_REL} \
		PERLMANPREFIX_regex=${PERLMANPREFIX_REL}\b \
		SITEMANPREFIX=${SITE_MAN_PREFIX} \
		SITE_PERL=${SITE_PERL_REL} \
		SITE_ARCH=${SITE_ARCH_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		PKGNAMESUFFIX=${PKGNAMESUFFIX} \
		ARCH_LIB=${_ARCH_LIB}

# Why this is required is explained in:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227356#c5
_PERL5_DEFAULT_FILE=	/tmp/PERL5_DEFAULT

# Get the default version, and possibly, overwrite it.
.include <bsd.port.options.mk>
.sinclude "${_PERL5_DEFAULT_FILE}"

# if this port is default due PERL5_DEFAULT
# change PKGNAME to reflect this
.if ${PERL_VER} == ${PERL5_DEFAULT}
PKGNAMESUFFIX=	5
IAMDEFAULTPERL=	yes
.else
# make PKGNAME unique among other lang/perl5.x
PKGNAMESUFFIX=	${PERL_VER}
.endif

# Am I building the default Perl ?
.if defined(IAMDEFAULTPERL)
PLIST_SUB+=	DEFAULT="" BINSUFFIX=""
.else
BINSUFFIX=	${PERL_VERSION}
PLIST_SUB+=	DEFAULT="@comment " BINSUFFIX=${PERL_VERSION}
CONFIGURE_ARGS+=-Dversiononly
.endif

.if !defined(IAMDEFAULTPERL)
pre-everything::
	@${ECHO_MSG} "##################################################"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "      This is *NOT* the DEFAULT perl version"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "It will *NOT* install ${PREFIX}/bin/perl"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "It will *ONLY* install ${PREFIX}/bin/perl${PERL_VERSION}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The default Perl version currently is ${PERL5_DEFAULT}."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you want to use this version as the default,"
	@${ECHO_MSG} "stop the build now, add this line to your"
	@${ECHO_MSG} "/etc/make.conf, and then restart the build."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "DEFAULT_VERSIONS+=perl5=${PERL_VER}"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "##################################################"
.  if !(defined(PACKAGE_BUILDING) || defined(BATCH))
	@sleep 30
.  endif
.endif

# Put a symlink to the future libperl.so.x.yy so that -lperl works.
# Also, save PERL5_DEFAULT in case someone is not using the default Perl
# version whilst not having set DEFAULT_VERSIONS=perl5=blah.  While upgrading,
# portmaster/portupgrade will remove the installed Perl version, and it will
# remove any way to guess what the default Perl version is needed.
post-extract:
	${LN} -s libperl.so.${PERL_VERSION} ${WRKSRC}/libperl.so
	${LN} -s libperl.so.${PERL_VERSION} ${WRKSRC}/libperl.so.${PERL_VER}
.if !defined(PACKAGE_BUILDING)
	@${ECHO_CMD} "PERL5_DEFAULT=${PERL5_DEFAULT}" > ${_PERL5_DEFAULT_FILE}
.endif

.if !defined(PACKAGE_BUILDING)
post-clean:
	@${RM} ${_PERL5_DEFAULT_FILE}
.endif

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Configure ${WRKSRC}/hints/freebsd.sh
.if !defined(IAMDEFAULTPERL)
	${REINPLACE_CMD} -e '/do_installprivlib = 0 if .versiononly/d; \
		/^if.*nopods.*versiononly || /s/.*/if (1) {/' \
		${WRKSRC}/installperl
.endif

post-install:
	@${REINPLACE_CMD} -e '/^lddlflags/s|-L${WRKSRC} ||' \
		${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl
	@${TOUCH} -r ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl.bak ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl
	@${RM} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl.bak
.if ${CC} == /nxb-bin/usr/bin/cc
	@${REINPLACE_CMD} -e 's=/nxb-bin==' \
		${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config.pm ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl
# Restore Config.pm's timestamp so that Perl's build system does not think it
# needs to rebuild everything.
	@${TOUCH} -r ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config.pm.bak ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config.pm
	@${TOUCH} -r ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl.bak ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl
	@${RM} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config.pm.bak ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/Config_heavy.pl.bak
.endif

	${MKDIR} ${STAGEDIR}${SITE_MAN1} ${STAGEDIR}${SITE_MAN3}
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/auto
	${MKDIR} ${STAGEDIR}${SITE_PERL}/auto
.if defined(IAMDEFAULTPERL)
	${LN} -sf perl ${STAGEDIR}${PREFIX}/bin/perl5
	${LN} -sf perl ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
.endif
	${LN} -sf libperl.so.${PERL_VERSION} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so
	${LN} -sf libperl.so.${PERL_VERSION} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so.${PERL_VER}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/machine
	${MKDIR} ${STAGEDIR}${SITE_ARCH}/sys
	# h2ph needs perl, but perl is not installed, it's only
	# staged, so, use the one in WRKDIR
	(cd /usr/include && ${SETENV} LD_LIBRARY_PATH=${WRKSRC} \
		${WRKSRC}/perl -I ${WRKSRC}/lib ${STAGEDIR}${PREFIX}/bin/h2ph${BINSUFFIX} \
		-d ${STAGEDIR}${SITE_ARCH} *.h machine/*.h sys/*.h >/dev/null)
	@${FIND} ${STAGEDIR}${SITE_ARCH} -name '*.ph' | sed -e 's|${STAGEDIR}||' >> ${TMPPLIST}
	${FIND} ${STAGEDIR} -name '*.so*' -type f | while read f; \
		do \
			${CHMOD} 644 $$f; \
			${STRIP_CMD} $$f; \
			${CHMOD} 444 $$f; \
		done
	${INSTALL_DATA} ${WRKDIR}/perl-man.conf ${STAGEDIR}${PREFIX}/etc/man.d/perl${PKGNAMESUFFIX}.conf

.include <bsd.port.mk>
