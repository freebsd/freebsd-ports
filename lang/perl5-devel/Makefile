PORTNAME=	perl
DISTVERSION=	${PERL_VERSION}
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN/../../src/5.0 CPAN/../by-authors/id/B/BO/BOOK
DIST_SUBDIR=	perl

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Practical Extraction and Report Language
WWW=		https://www.perl.org/

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE_ART10=	${WRKSRC}/Artistic
LICENSE_FILE_GPLv1+ =	${WRKSRC}/Copying

# Uncomment when the default Perl is switched to 5.4(X+2)+
#DEPRECATED=	Support end three years after .0 release, please upgrade to a more recent version of Perl
#EXPIRATION_DATE=<Release date of .0 + 3 years>

USES=		cpe tar:xz

# Give a hint of where libperl.so can be found.
USE_LDCONFIG=	${PREFIX}/${_ARCH_LIB}/CORE

TEST_TARGET=	test_harness
TEST_ENV=	${MAKE_ENV} \
		LD_LIBRARY_PATH=${WRKSRC} \
		TEST_JOBS=${MAKE_JOBS_NUMBER}

PORTSCOUT=	limit:^${PERL_VER}.

HAS_CONFIGURE=		yes
CONFIGURE_SCRIPT=	Configure
CONFIGURE_ARGS=		-Darchlib=${PREFIX}/${_ARCH_LIB} \
			-Dcc="${CC}" \
			-Dcf_by=${MAINTAINER:C,@.*,,} \
			-Dcf_email=${MAINTAINER} \
			-Dcf_time="`${STAT} -t \"%a %b %d %T %Z %Y\" -f %Sm ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX}`" \
			-Dinc_version_list=none \
			-Dlibperl=libperl.so.${LIBPERL_VER} \
			-Dman1dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man1 \
			-Dman3dir=${PREFIX}/${PERLMANPREFIX_REL}/man/man3 \
			-Dprefix=${PREFIX} \
			-Dprivlib=${PREFIX}/${_PRIV_LIB} \
			-Dscriptdir=${PREFIX}/bin \
			-Dsitearch=${SITE_ARCH} \
			-Dsitelib=${SITE_PERL} \
			-Dsiteman1dir=${SITE_MAN1} \
			-Dsiteman3dir=${SITE_MAN3} \
			-Dusenm=n \
			-Duseshrplib \
			-Dusethreads=y \
			-sde \
			-Ui_iconv \
			-Ui_malloc \
			-Uinstallusrbinperl
# Keep the following two in sync.
# lddlflags is used for all .so linking
# shrpldflags is used for libperl.so, so remove all the extra bits inherited from lddlflags.
# XXX change the soname to $$(LIBPERL:R)
CONFIGURE_ARGS+=	-Alddlflags='-L${WRKSRC} -L${PREFIX}/${_ARCH_LIB}/CORE -lperl' \
			-Dshrpldflags='$$(LDDLFLAGS:N-L${WRKSRC}:N-L${PREFIX}/${_ARCH_LIB}/CORE:N-lperl) -Wl,-soname,$$(LIBPERL)'

# XXX Remove
CONFIGURE_ARGS+=	-Dusedevel \
			-Uversiononly

# When built from a git repository, newvers.sh can put a = in the version.
CONFIGURE_ENV=	UNAME_v="$$(uname -v | sed 'y/=/ /')"

SUB_FILES=	perl-man.conf

INSTALL_TARGET=	install-strip

.if defined(PERL_VENDOR_PREFIX)
CONFIGURE_ARGS+=	-Dvendorarch=${PERL_VENDOR_PREFIX}/${_ARCH_LIB} \
			-Dvendorbin=${PERL_VENDOR_PREFIX}/bin \
			-Dvendorlib=${PERL_VENDOR_PREFIX}/${_PRIV_LIB} \
			-Dvendorman1dir=${PERL_VENDOR_PREFIX}/man/man1 \
			-Dvendorman3dir=${PERL_VENDOR_PREFIX}/${_PRIV_LIB}/man/man3 \
			-Dvendorprefix=${PERL_VENDOR_PREFIX}
.endif

# http://perl5.git.perl.org/perl.git/commit/b83080de5c4254
# PERLIOBUF_DEFAULT_BUFSIZ size in bytes (default: 8192 bytes)
.if defined(PERLIOBUF_DEFAULT_BUFSIZ)
CONFIGURE_ARGS+=	-Accflags=-DPERLIOBUF_DEFAULT_BUFSIZ=${PERLIOBUF_DEFAULT_BUFSIZ}
.endif

PLIST_SUB=	ARCH_LIB=${_ARCH_LIB} \
		MAN1=${PERLMANPREFIX_REL}/man/man1 \
		MAN3=${PERLMANPREFIX_REL}/man/man3 \
		PERL_ARCH=${PERL_ARCH} \
		PERL_ARCH_regex=[[:<:]]${PERL_ARCH}[[:>:]] \
		PERL_VER=${PERL_VER} \
		PERL_VERSION=${PERL_VERSION} \
		PERLMANPREFIX=${PERLMANPREFIX_REL} \
		PERLMANPREFIX_regex=${PERLMANPREFIX_REL}[[:>:]] \
		PKGNAMESUFFIX=${PKGNAMESUFFIX} \
		PRIV_LIB=${_PRIV_LIB} \
		SITE_ARCH=${SITE_ARCH_REL} \
		SITE_PERL=${SITE_PERL_REL} \
		SITEMANPREFIX=${SITE_MAN_PREFIX}
# XXX Remove and change to PERL_VERSION in the plist.
PLIST_SUB+=	LIBPERL_VER=${LIBPERL_VER}

SUB_LIST=	PERL_ARCH=${PERL_ARCH} \
		PERL_VER=${PERL_VER} \
		PERL_VERSION=${PERL_VERSION} \
		PERLMANPREFIX=${PERLMANPREFIX_REL} \
		PRIV_LIB=${_PRIV_LIB} \
		SITE_PERL=${SITE_PERL_REL} \
		SITEMANPREFIX=${SITE_MAN_PREFIX}

.include "version.mk"
PERL_VER?=		${PERL_VERSION:C/\.[0-9]+$//}
PERL_ARCH=		mach
SITE_PERL_REL?=		lib/perl5/site_perl
SITE_PERL?=		${PREFIX}/${SITE_PERL_REL}
SITE_ARCH_REL?=		${SITE_PERL_REL}/${PERL_ARCH}/${PERL_VER}
SITE_ARCH?=		${PREFIX}/${SITE_ARCH_REL}
SITE_MAN_PREFIX=	${SITE_PERL_REL}
SITE_MAN3_REL?=		${SITE_MAN_PREFIX}/man/man3
SITE_MAN3?=		${PREFIX}/${SITE_MAN3_REL}
SITE_MAN1_REL?=		${SITE_MAN_PREFIX}/man/man1
SITE_MAN1?=		${PREFIX}/${SITE_MAN1_REL}

_PRIV_LIB=	lib/perl5/${PERL_VER}
_ARCH_LIB=	${_PRIV_LIB}/${PERL_ARCH}

PERLMANPREFIX_REL=	${_PRIV_LIB}/perl
PERLMANPREFIX=		${PREFIX}/${PERLMANPREFIX_REL}
MANDIRS=		${PERLMANPREFIX}/man

# XXX replace all LIBPERL_VER occurences with PERL_VERSION
LIBPERL_VER=	${PORTVERSION:C/[^0-9.]//}

OPTIONS_DEFINE=		DEBUG DOT_INC DTRACE GDBM MULTIPLICITY PERL_64BITINT \
			PERL_MALLOC SITECUSTOMIZE
OPTIONS_DEFAULT=	DTRACE MULTIPLICITY PERL_64BITINT

.if !exists(/usr/sbin/dtrace)
OPTIONS_EXCLUDE=	DTRACE
.endif
.for a in aarch64 armv6 armv7 \
	mips mips64 mips64el mips64elhf mips64hf mipsel mipselhf mipshf mipsn32 \
	riscv64 riscv64sf
OPTIONS_EXCLUDE_${a}=	DTRACE
.endfor
OPTIONS_SUB=		yes

DOT_INC_DESC=		Add '.' to @INC (unsafe)
GDBM_DESC=		GDBM_File extension
MULTIPLICITY_DESC=	Use multiplicity
PERL_64BITINT_DESC=	Use 64 bit integers (on i386)
PERL_MALLOC_DESC=	Use Perl malloc
SITECUSTOMIZE_DESC=	Run-time customization of @INC

DEBUG_CONFIGURE_ON=		-DDEBUGGING \
				-Doptimize="-g"
DEBUG_CONFIGURE_OFF=		-Doptimize="${CFLAGS}"
DOT_INC_CONFIGURE_ON=		-Ddefault_inc_excludes_dot=n
DTRACE_CONFIGURE_ON=		-Dusedtrace
DTRACE_CONFIGURE_OFF=		-Uusedtrace
GDBM_CONFIGURE_ON=		-Di_gdbm
GDBM_CONFIGURE_OFF=		-Ui_gdbm
GDBM_LIB_DEPENDS=		libgdbm.so:databases/gdbm
MULTIPLICITY_CONFIGURE_ON=	-Dusemultiplicity=y
MULTIPLICITY_CONFIGURE_OFF=	-Dusemultiplicity=n
PERL_64BITINT_CONFIGURE_ON=	-Duse64bitint
PERL_MALLOC_CONFIGURE_ON=	-Dusemymalloc=y
PERL_MALLOC_CONFIGURE_OFF=	-Dusemymalloc=n
SITECUSTOMIZE_CONFIGURE_ON=	-Dusesitecustomize

# Why this is required is explained in:
# https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=227356#c5
_PERL5_DEFAULT_FILE=	/tmp/PERL5_DEFAULT

# Get the default version, and possibly, overwrite it.
.include <bsd.port.options.mk>
.sinclude "${_PERL5_DEFAULT_FILE}"

# if this port is default due PERL5_DEFAULT
# change PKGNAME to reflect this
.if ${PERL_VER} == ${PERL5_DEFAULT} || ${PERL5_DEFAULT} == devel # XXX Remove devel case
PKGNAMESUFFIX=	5
IAMDEFAULTPERL=	yes
.else
# make PKGNAME unique among other lang/perl5.x
PKGNAMESUFFIX=	5-devel
#PKGNAMESUFFIX=	${PERL_VER} # XXX remove the previous, leave only this.
.endif

# Am I building the default Perl ?
.if defined(IAMDEFAULTPERL)
PLIST_SUB+=		BINSUFFIX="" \
			DEFAULT=""
.else
BINSUFFIX=		${PERL_VERSION}
PLIST_SUB+=		BINSUFFIX=${PERL_VERSION} \
			DEFAULT="@comment "
CONFIGURE_ARGS+=	-Dversiononly
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

# XXX Remove this
pre-everything::
	@${ECHO_MSG} "########################################"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This is a DEVELOPER only version of Perl"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "             DO NOT USE IT"
	@${ECHO_MSG} ""
	@${ECHO_MSG} ""
	@${ECHO_MSG} " Things ARE going to be broken with it"
	@${ECHO_MSG} "       and it WILL eat your data"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "         You have been warned !"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "########################################"
# No need to make me, or the package builders, wait
.if !(defined(PACKAGE_BUILDING) || defined(PERL_DEV_SHUT_UP) || defined(BATCH))
	@sleep 30
.endif

# Put a symlink to the future libperl.so.x.yy so that -lperl works.
# Also, save PERL5_DEFAULT in case someone is not using the default Perl
# version whilst not having set DEFAULT_VERSIONS=perl5=blah.  While upgrading,
# portmaster/portupgrade will remove the installed Perl version, and it will
# remove any way to guess what the default Perl version is needed.
post-extract:
	${LN} -s libperl.so.${LIBPERL_VER} ${WRKSRC}/libperl.so
	${LN} -s libperl.so.${LIBPERL_VER} ${WRKSRC}/libperl.so.${PERL_VER}
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
	cd ${PATCHDIR}; for patch in patch-*; do \
		${AWK} -v patch="$$patch" 'seen == 1 && /,NULL/ {print ",\"FreeBSD:" patch "\""} {print} /local_patches\[\]/ { seen=1 }' ${WRKSRC}/patchlevel.h > ${WRKDIR}/patchlevel.h; \
		mv -f ${WRKDIR}/patchlevel.h ${WRKSRC}/patchlevel.h ; \
	done

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
	${LN} -sf perl ${STAGEDIR}${PREFIX}/bin/perl${PERL_VERSION}
.endif
	${LN} -sf libperl.so.${LIBPERL_VER} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so
	${LN} -sf libperl.so.${LIBPERL_VER} ${STAGEDIR}${PREFIX}/${_ARCH_LIB}/CORE/libperl.so.${PERL_VER}
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
