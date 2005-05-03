# New ports collection makefile for:	perl5
# Date created:		16 April 1995
# Whom:			markm
#
# $FreeBSD$
#

PORTNAME=	perl
PORTVERSION=	${PERL_VER}
PORTREVISION=	2
CATEGORIES=	lang devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN} \
		${MASTER_SITE_LOCAL:S/$/:local/} \
		http://www.tobez.org/download/port-mirrors/lang/perl56/:local
MASTER_SITE_SUBDIR=	../../src \
			tobez/:local ./:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		BSDPAN-${PERL_VER}${EXTRACT_SUFX}:local

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

PERL_VER=	5.6.2
PERL_ARCH=	mach
PERL_VERSION=	${PERL_VER}

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
	-Dcc="${CC}" -Doptimize="${CFLAGS}" -Duseshrplib \
	-Dccflags=-DAPPLLIB_EXP=\"${BSDPAN_DEST}\"
LOCALE_CLEANUP=	LANG="" LC_ALL="" LC_COLLATE="" LC_CTYPE="" \
		LC_MESSAGES="" LC_MONETARY="" LC_NUMERIC="" \
		LC_TIME=""
CONFIGURE_ENV+=	${LOCALE_CLEANUP}
MAKE_ENV+=	${LOCALE_CLEANUP}

.include "Makefile.man"
.include <bsd.port.pre.mk>

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
IGNORE=	Threads are not very useful in perl ${PERL_VERSION}, please use lang/perl5.8
.endif

.if defined(WITH_PERL_MALLOC)
CONFIGURE_ARGS+=	-Dusemymalloc=y
.else
CONFIGURE_ARGS+=	-Dusemymalloc=n
.endif

.ifdef USE_PERL5
.error You have `USE_PERL5' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

NO_LATEST_LINK=	yes

.if ${OSVERSION} < 500036
PKGMESSAGE=	${PKGDIR}/pkg-message-sysperl
.else
PKGMESSAGE=	${PKGDIR}/pkg-message-prefer58
.endif

PLIST_SUB+=		NEED_USE_PERL=""

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

post-patch:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g;' \
		-e 's|%%PERL_VER%%|${PERL_VER}|g;' \
		-e 's|%%PERL_VERSION%%|${PERL_VERSION}|g;' \
		-e 's|%%PERL_ARCH%%|${PERL_ARCH}|g;' \
		-e 's|%%MAKE_CONF%%|${__MAKE_CONF}|g;' \
		${FILESDIR}/use.perl \
		> ${WRKDIR}/use.perl
	${CP} ${WRKDIR}/use.perl ${PKGINSTALL}
	${CP} ${WRKDIR}/use.perl ${PKGDEINSTALL}

pre-install:
	@${RM} -f ${PREFIX}/bin/perl${PERL_VER}
	@${RM} -f ${PREFIX}/bin/perl

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/perl${PERL_VER}
	@${STRIP_CMD} ${PREFIX}/bin/perl
	@${LN} -sf ${PREFIX}/bin/perl${PERL_VER} ${PREFIX}/bin/perl5
.for file in ${BSDPAN_FILES}
	${MKDIR} ${BSDPAN_DEST}/${file:H}
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${NOBINMODE} \
		${BSDPAN_WRKSRC}/${file} ${BSDPAN_DEST}/${file}
.endfor
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	${INSTALL_SCRIPT} ${WRKDIR}/use.perl ${PREFIX}/bin/use.perl
	@fmt ${PKGMESSAGE}

.include <bsd.port.post.mk>
