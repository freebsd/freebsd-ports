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

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Practical Extraction and Report Language

PERL_VER=	5.8.5
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
	-Dcc="${CC}" -Doptimize="${CFLAGS}" -Duseshrplib \
	-Dccflags=-DAPPLLIB_EXP=\"${BSDPAN_DEST}\"

INCLUDEDIR=	/usr/include

.include "Makefile.man"
.include <bsd.port.pre.mk>

.if defined(ENABLE_SUIDPERL)
CONFIGURE_ARGS+=	-Dd_dosuid=define
PLIST_SUB+=		ENABLE_SUIDPERL=""
.else
CONFIGURE_ARGS+=	-Ud_dosuid
PLIST_SUB+=		ENABLE_SUIDPERL="@comment "
.endif
# INSTALLS_SHLIB=	yes

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

.if !defined(WITHOUT_PERL_64BITINT)
CONFIGURE_ARGS+=	-Duse64bitint
.endif

.if ${OSVERSION} < 502100
LATEST_LINK=	perl5.8
.else
PKGMESSAGE=	${PKGDIR}/.not-here
.endif

.if defined(WITH_GDBM)
MAN3+=	GDBM_File.3
.endif
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}/perl

test:
	@(cd ${WRKSRC}; make test)

BSDPAN_DEST=	${PREFIX}/lib/perl5/${PERL_VER}/BSDPAN
BSDPAN_FILES=	BSDPAN.pm BSDPAN/Override.pm Config.pm \
		ExtUtils/MM_Unix.pm ExtUtils/Packlist.pm
BSDPAN_WRKSRC=	${WRKDIR}/BSDPAN-5.8.5

post-patch:
	${SED} -e 's|%%PREFIX%%|${PREFIX}|g;' \
		-e 's|%%PERL_VER%%|${PERL_VER}|g;' \
		-e 's|%%PERL_VERSION%%|${PERL_VERSION}|g;' \
		-e 's|%%PERL_ARCH%%|${PERL_ARCH}|g;' \
		${FILESDIR}/use.perl \
		> ${WRKDIR}/use.perl

pre-install:
	@${RM} -f ${PREFIX}/bin/perl${PERL_VER}
	@${RM} -f ${PREFIX}/bin/perl

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/perl${PERL_VER}
	@${STRIP_CMD} ${PREFIX}/bin/perl
	@${LN} -sf ${PREFIX}/bin/perl${PERL_VER} ${PREFIX}/bin/perl5
	${INSTALL_SCRIPT} ${WRKDIR}/use.perl ${PREFIX}/bin/use.perl
.for files in ${BSDPAN_FILES}
	${MKDIR} ${BSDPAN_DEST}/${files:H}
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${NOBINMODE} \
		${BSDPAN_WRKSRC}/${files} ${BSDPAN_DEST}/${files}
.endfor
	@(cd ${INCLUDEDIR} && ${PREFIX}/bin/h2ph *.h machine/*.h sys/*.h)
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/auto
	${MKDIR} ${PREFIX}/${SITE_PERL_REL}/${PERL_ARCH}/auto
	${MKDIR} ${PREFIX}/lib/perl5/${PERL_VER}/man/man3
.if ${OSVERSION} < 502100
	@fmt ${PKGMESSAGE}
.else
	@${PREFIX}/bin/use.perl port
.endif

.include <bsd.port.post.mk>
