# New ports collection makefile for:	perl5
# Date created:		16 April 1995
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	${PERL_VERSION}
PORTREVISION=	3
CATEGORIES=	lang devel perl5
MASTER_SITES=	CPAN \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://protey.ru/freebsd/distfiles/:local
MASTER_SITE_SUBDIR=	../../src \
			skv/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		BSDPAN-${BSDPAN_VERSION}${EXTRACT_SUFX}:local
DIST_SUBDIR=	perl

PATCH_SITES=	${MASTER_SITE_LOCAL:S!$!skv/!} \
		http://protey.ru/freebsd/distfiles/
PATCHFILES=	defined-or-${PERL_VERSION}.bz2

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

CONFLICTS=	perl-5.6.* perl-5.10.* perl-threaded-5.10.*

OPTIONS=	DEBUGGING	"Build with debugging support"		off \
		GDBM		"Build GDBM_File extension"		off \
		PERL_MALLOC	"Use Perl malloc"			on  \
		PERL_64BITINT	"Use 64 bit integers (on i386)"		on  \
		THREADS		"Build threaded perl"			off \
		SUIDPERL	"Build set-user-id suidperl binary"	off \
		SITECUSTOMIZE	"Run-time customization of @INC"	off \
		USE_PERL	"Rewrite links in /usr/bin"		on

PERL_VERSION=	5.8.9
PERL_ARCH=	mach
SITE_PERL_REL?=	lib/perl5/site_perl/${PERL_VERSION}
SITE_PERL?=	${LOCALBASE}/${SITE_PERL_REL}

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Darchlib=${PREFIX}/lib/perl5/${PERL_VERSION}/${PERL_ARCH} \
	-Dprivlib=${PREFIX}/lib/perl5/${PERL_VERSION} \
	-Dman3dir=${PREFIX}/lib/perl5/${PERL_VERSION}/perl/man/man3 \
	-Dman1dir=${PREFIX}/man/man1 \
	-Dsitearch=${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH} \
	-Dsitelib=${PREFIX}/${SITE_PERL_REL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${PREFIX}/lib/perl5/${PERL_VERSION}/man/man3 \
	-Dsiteman1dir=${PREFIX}/man/man1 \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl \
	-Dcc="${CC}" -Duseshrplib -Dinc_version_list=none \
	-Dccflags=-DAPPLLIB_EXP=\"${BSDPAN_DEST}\"
LOCALE_CLEANUP=	LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV+=	${LOCALE_CLEANUP}
MAKE_ENV+=	${LOCALE_CLEANUP}

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(PERL_VENDOR_PREFIX)
CONFIGURE_ARGS+=	\
	-Dvendorprefix=${PERL_VENDOR_PREFIX} \
	-Dvendorarch=${PERL_VENDOR_PREFIX}/lib/perl5/${PERL_VERSION}/${PERL_ARCH} \
	-Dvendorbin=${PERL_VENDOR_PREFIX}/bin \
	-Dvendorlib=${PERL_VENDOR_PREFIX}/lib/perl5/${PERL_VERSION} \
	-Dvendorman3dir=${PERL_VENDOR_PREFIX}/lib/perl5/${PERL_VERSION}/man/man3 \
	-Dvendorman1dir=${PERL_VENDOR_PREFIX}/man/man1
.endif

PLIST_SUB+=	PERL_VERSION=${PERL_VERSION} \
		PERL_VER=${PERL_VERSION} \
		PERL_ARCH=${PERL_ARCH} \
		SITE_PERL=${SITE_PERL:S|^${LOCALBASE}/||}

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	-Doptimize="-g" -DDEBUGGING
STRIP=
STRIP_CMD=	${TRUE}
.else
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
.endif

.if defined(ENABLE_SUIDPERL) || defined(WITH_SUIDPERL)
CONFIGURE_ARGS+=	-Dd_dosuid=define
PLIST_SUB+=		SUIDPERL=""
.else
CONFIGURE_ARGS+=	-Ud_dosuid
PLIST_SUB+=		SUIDPERL="@comment "
.endif

.if defined(WITH_GDBM)
CONFIGURE_ARGS+=	-Di_gdbm
LIB_DEPENDS+=		gdbm.3:${PORTSDIR}/databases/gdbm
PLIST_SUB+=		GDBM=""
.else
CONFIGURE_ARGS+=	-Ui_gdbm
PLIST_SUB+=		GDBM="@comment "
.endif

.if defined(WITHOUT_PERL_MALLOC)
.undef WITH_PERL_MALLOC
.else
WITH_PERL_MALLOC=	yes
.endif

.if defined(WITH_THREADS)
#XXX .if ${ARCH} == "amd64"
#XXX IGNORE=	Threaded perl does not pass tests on ${ARCH}
#XXX .endif
CONFIGURE_ARGS+=	-Dusethreads=y
PKGNAMESUFFIX=		-threaded
# it seems perl malloc has problems with threaded perl on FreeBSD
.undef WITH_PERL_MALLOC
.else
CONFIGURE_ARGS+=	-Dusethreads=n
.endif

.if defined(WITH_PERL_MALLOC)
CONFIGURE_ARGS+=	-Dusemymalloc=y
.else
CONFIGURE_ARGS+=	-Dusemymalloc=n
.endif

.if defined(WITH_PERL_64BITINT)
CONFIGURE_ARGS+=	-Duse64bitint
.endif

.if defined(WITH_SITECUSTOMIZE)
CONFIGURE_ARGS+=	-Dusesitecustomize
.endif

LATEST_LINK=	perl

PLIST_SUB+=		NEED_USE_PERL="@comment "

.if defined(WITH_GDBM)
MAN3+=	GDBM_File.3
.endif
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}/perl

BSDPAN_DEST=	${PREFIX}/lib/perl5/${PERL_VERSION}/BSDPAN
BSDPAN_FILES=	BSDPAN.pm BSDPAN/Override.pm Config.pm \
		ExtUtils/MM_Unix.pm \
		ExtUtils/MakeMaker.pm \
		ExtUtils/Packlist.pm
BSDPAN_VERSION=	${PORTVERSION}_20090303
BSDPAN_WRKSRC=	${WRKDIR}/BSDPAN-${BSDPAN_VERSION}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

post-patch:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g;' \
		-e 's|%%PERL_VERSION%%|${PERL_VERSION}|g;' \
		-e 's|%%PERL_ARCH%%|${PERL_ARCH}|g;' \
		-e 's|%%MAKE_CONF%%|${__MAKE_CONF}|g;' \
		${FILESDIR}/use.perl \
		> ${WRKDIR}/use.perl
	${SED} -e 's|%%PERL%%|${PERL}|g; s|%%PERL_VERSION%%|${PERL_VERSION}|g; s|%%PKGNAME%%|${PKGNAME}|g' \
		${FILESDIR}/perl-after-upgrade \
		> ${WRKDIR}/perl-after-upgrade
	${CP} ${WRKDIR}/use.perl ${PKGINSTALL}
	${CP} ${WRKDIR}/use.perl ${PKGDEINSTALL}
	${SED} -i '' -e 's|%%PERL_PKGNAME%%|${PKGNAME}|g; s|%%PERL_VER%%|5.8|g;' \
		${BSDPAN_WRKSRC}/ExtUtils/*.pm
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/Configure ${WRKSRC}/hints/freebsd.sh
.if defined(WITH_THREADS)
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g;' \
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g;' \
		${WRKSRC}/hints/freebsd.sh
.else
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%||g;' \
		-e 's|%%PTHREAD_CFLAGS%%||g;' \
		${WRKSRC}/hints/freebsd.sh
.endif

pre-su-install:
	@${RM} -f ${PREFIX}/bin/perl${PERL_VERSION}
	@${RM} -f ${PREFIX}/bin/perl

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/perl${PERL_VERSION}
	@${STRIP_CMD} ${PREFIX}/bin/perl
	@${PREFIX}/bin/pod2man ${WRKDIR}/perl-after-upgrade >${WRKDIR}/perl-after-upgrade.1
	@${INSTALL_SCRIPT} ${WRKDIR}/perl-after-upgrade ${PREFIX}/bin/perl-after-upgrade
	@${INSTALL_MAN} ${WRKDIR}/perl-after-upgrade.1 ${MAN1PREFIX}/man/man1/perl-after-upgrade.1
	@${LN} -sf ${PREFIX}/bin/perl${PERL_VERSION} ${PREFIX}/bin/perl5
.for files in ${BSDPAN_FILES}
	${MKDIR} ${BSDPAN_DEST}/${files:H}
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${NOBINMODE} \
		${BSDPAN_WRKSRC}/${files} ${BSDPAN_DEST}/${files}
.endfor
.if defined(WITH_USE_PERL)
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

test: build
	@(cd ${WRKSRC}; make test)

regression-test: test

rebuild-xs:
	${LOCALBASE}/sbin/portupgrade -f `(${FIND} ${PKG_DBDIR}/p5*/+CONTENTS | \
		${XARGS} ${GREP} -El 'site_perl.*\.so' | \
		${SED} -e 's!/var/db/pkg/!!; s!/+CONTENTS!!;')`

.include <bsd.port.post.mk>
