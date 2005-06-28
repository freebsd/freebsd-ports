# New ports collection makefile for:	perl5
# Date created:		16 April 1995
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	${PERL_VER}
CATEGORIES=	lang devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://www.tobez.org/download/port-mirrors/lang/perl58/:local
MASTER_SITE_SUBDIR=	../../src \
			tobez/:local ./:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		BSDPAN-${PERL_VER}${EXTRACT_SUFX}:local

PATCH_SITES=	${MASTER_SITE_LOCAL:S/$/tobez\//} \
		http://www.tobez.org/download/port-mirrors/lang/perl58/
PATCHFILES=	defined-or-5.8.7.bz2

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

PERL_VER=	5.8.7
PERL_ARCH=	mach
PERL_VERSION=	${PERL_VER}

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=Configure
CONFIGURE_ARGS=	-sde -Dprefix=${PREFIX} \
	-Darchlib=${PREFIX}/lib/perl5/${PERL_VER}/${PERL_ARCH} \
	-Dprivlib=${PREFIX}/lib/perl5/${PERL_VER} \
	-Dman3dir=${PREFIX}/lib/perl5/${PERL_VER}/perl/man/man3 \
	-Dman1dir=${PREFIX}/man/man1 \
	-Dsitearch=${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH} \
	-Dsitelib=${PREFIX}/${SITE_PERL_REL} -Dscriptdir=${PREFIX}/bin \
	-Dsiteman3dir=${PREFIX}/lib/perl5/${PERL_VER}/man/man3 \
	-Dsiteman1dir=${PREFIX}/man/man1 \
	-Ui_malloc -Ui_iconv -Uinstallusrbinperl \
	-Dcc="${CC}" -Duseshrplib \
	-Dccflags=-DAPPLLIB_EXP=\"${BSDPAN_DEST}\"
LOCALE_CLEANUP=	LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV+=	${LOCALE_CLEANUP}
MAKE_ENV+=	${LOCALE_CLEANUP}

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(WITH_DEBUGGING)
CONFIGURE_ARGS+=	-Doptimize="-g" -DDEBUGGING
.else
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
.endif

.if defined(ENABLE_SUIDPERL)
CONFIGURE_ARGS+=	-Dd_dosuid=define
PLIST_SUB+=		ENABLE_SUIDPERL=""
.else
CONFIGURE_ARGS+=	-Ud_dosuid
PLIST_SUB+=		ENABLE_SUIDPERL="@comment "
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
.if ${OSVERSION} < 492000
CONFIGURE_ARGS+=	-Ud_gethostbyaddr_r
.endif
.else
CONFIGURE_ARGS+=	-Dusethreads=n
.endif

.if defined(WITH_PERL_MALLOC)
CONFIGURE_ARGS+=	-Dusemymalloc=y
.else
CONFIGURE_ARGS+=	-Dusemymalloc=n
.endif

.if !defined(WITHOUT_PERL_64BITINT)
CONFIGURE_ARGS+=	-Duse64bitint
.endif

LATEST_LINK=	perl

.if ${OSVERSION} < 500036
PLIST_SUB+=		NEED_USE_PERL=""
.else
PKGMESSAGE=	${PKGDIR}/.not-here
PLIST_SUB+=		NEED_USE_PERL="@comment "
.endif

.if defined(WITH_GDBM)
MAN3+=	GDBM_File.3
.endif
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}/perl

test:
	@(cd ${WRKSRC}; make test)

BSDPAN_DEST=	${PREFIX}/lib/perl5/${PERL_VER}/BSDPAN
BSDPAN_FILES=	BSDPAN.pm BSDPAN/Override.pm Config.pm \
		ExtUtils/MM_Unix.pm \
		ExtUtils/MakeMaker.pm \
		ExtUtils/Packlist.pm
BSDPAN_WRKSRC=	${WRKDIR}/BSDPAN-${PORTVERSION}

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall
USE_REINPLACE=	yes

pre-fetch:
	@${ECHO} ""
	@${ECHO} "You may use the following build options:"
	@${ECHO} ""
	@${ECHO} "	WITH_DEBUGGING=yes	  Build perl with debugging support."
	@${ECHO} "	WITH_GDBM=yes		  Build GDBM_File extension."
	@${ECHO} "	WITHOUT_PERL_MALLOC=yes	  Use FreeBSD system malloc"
	@${ECHO} "				  (uses less memory, but slower)."
	@${ECHO} "	WITHOUT_PERL_64BITINT=yes Disable 64 bit integers"
	@${ECHO} "				  (affects only 32-bit platforms)."
	@${ECHO} "	WITH_THREADS=yes	  Build threaded perl."
	@${ECHO} "	ENABLE_SUIDPERL=yes	  Also build set-user-id suidperl binary."
	@${ECHO} ""

post-patch:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g;' \
		-e 's|%%PERL_VER%%|${PERL_VER}|g;' \
		-e 's|%%PERL_VERSION%%|${PERL_VERSION}|g;' \
		-e 's|%%PERL_ARCH%%|${PERL_ARCH}|g;' \
		-e 's|%%MAKE_CONF%%|${__MAKE_CONF}|g;' \
		${FILESDIR}/use.perl \
		> ${WRKDIR}/use.perl
	${SED} -e 's|%%PERL%%|${PERL}|g;' \
		${FILESDIR}/perl-after-upgrade \
		> ${WRKDIR}/perl-after-upgrade
	${CP} ${WRKDIR}/use.perl ${PKGINSTALL}
	${CP} ${WRKDIR}/use.perl ${PKGDEINSTALL}
	${REINPLACE_CMD} -e 's|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g;' \
		-e 's|%%PTHREAD_CFLAGS%%|${PTHREAD_CFLAGS}|g;' \
		${WRKSRC}/hints/freebsd.sh

pre-install:
	@${RM} -f ${PREFIX}/bin/perl${PERL_VER}
	@${RM} -f ${PREFIX}/bin/perl

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/perl${PERL_VER}
	@${STRIP_CMD} ${PREFIX}/bin/perl
	@${PREFIX}/bin/pod2man ${WRKDIR}/perl-after-upgrade >${WRKDIR}/perl-after-upgrade.1
	@${INSTALL_SCRIPT} ${WRKDIR}/perl-after-upgrade ${PREFIX}/bin/perl-after-upgrade
	@${INSTALL_MAN} ${WRKDIR}/perl-after-upgrade.1 ${MAN1PREFIX}/man/man1/perl-after-upgrade.1
	@${LN} -sf ${PREFIX}/bin/perl${PERL_VER} ${PREFIX}/bin/perl5
.for files in ${BSDPAN_FILES}
	${MKDIR} ${BSDPAN_DEST}/${files:H}
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${NOBINMODE} \
		${BSDPAN_WRKSRC}/${files} ${BSDPAN_DEST}/${files}
.endfor
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if ${OSVERSION} < 500036
	${INSTALL_SCRIPT} ${WRKDIR}/use.perl ${PREFIX}/bin/use.perl
	@fmt ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>
