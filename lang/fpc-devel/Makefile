# New ports collection makefile for:	Free Pascal Compiler
# Date created:				28 November 2001
# Whom:					John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	fpc
PORTVERSION=	1.0.6
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.freepascal.org/pub/fpc/dist/freebsd-${PORTVERSION}/ \
		ftp://ftp.epix.net/pub/languages/pascal/dist/freebsd-${PORTVERSION}/ \
		http://gd.tuwien.ac.at/languages/pascal/dist/freebsd-${PORTVERSION}/ \
		http://www.zeus.rug.ac.be/freepascal/files/dist/freebsd-${PORTVERSION}/ \
		ftp://ftp.darklands.cx/pub/fpc/dist/freebsd-${PORTVERSION}/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/freebsd-${PORTVERSION}/ \
		ftp://deadlock.et.tudelft.nl/pub/fpc/dist/freebsd-${PORTVERSION}/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/freebsd-${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}.ELF.FreeBSD

EXTRACT_SUFX=	.tar

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Free Pascal compiler with Turbo, Delphi and other extensions

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	c_r.4:${PORTSDIR}/misc/compat4x
.endif

.if ${OSVERSION} < 470000
EXTRACT_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar
TAR=		${LOCALBASE}/bin/gtar
.endif

RUN_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes
PKGDEINSTALL=	${PKGINSTALL}

PLIST_SUB+=	PORTVERSION=${PORTVERSION}

MAN1=		delp.1 fpc.1 fpcmake.1 h2pas.1 plex.1 ppc386.1 ppdep.1 \
		ppudump.1 ppufiles.1 ppumove.1 ptop.1 pyacc.1 rstconv.1
MAN5=		fpc.cfg.5 fpcmake.5 ptop.cfg.5

# programs
SORT?=		/usr/bin/sort
# macro for creating directory with DATA perms
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0755


LIBDIR=		${PREFIX}/lib/fpc/${PORTVERSION}
TEMP_PREFIX=	${WRKSRC}/temp

# install staging area
post-extract:
	@${TAR} xf ${WRKSRC}/binary.tar --directory ${WRKSRC}
	@${TAR} xf ${WRKSRC}/sources.tar --directory ${WRKSRC}
	@${MKDIR} ${TEMP_PREFIX}
#unpack base system
	@${TAR} zxf ${WRKSRC}/basefreebsd.tar.gz \
		--directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/utilfreebsd.tar.gz \
		--directory ${TEMP_PREFIX}
#unpack units
	@${TAR} zxf ${WRKSRC}/unitsfclfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsbfdfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitscmemfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsformsfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsfpasyncfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgdbintfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgdbmfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsggifreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgtkfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsibasefreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsinetfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitslibasyncfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitslibgdfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitslibpngfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsmysqlfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsncursesfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsopenglfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsoraclefreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitspaszlibfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitspostgresfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsregexprfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitssvgalibfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitssyslogfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsuncgifreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsunzipfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsutmpfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsx11freebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitszlibfreebsd.tar.gz --directory ${TEMP_PREFIX}
#unpack ide
	@${TAR} zxf ${WRKSRC}/idefreebsd.tar.gz --directory ${TEMP_PREFIX}
.ifndef(NOPORTDOCS)
#unpack documentation, examples, and sources
	@${TAR} zxf ${WRKSRC}/basesrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/compilersrc.tar.gz \
		--directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/rtlsrc.tar.gz \
		--directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/fclsrc.tar.gz \
		--directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/idesrc.tar.gz \
		--directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/installersrc.tar.gz \
		--directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsbfdsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitscmemsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsformssrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsfpasyncsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgdbintsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgdbmsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsggisrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgtksrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsibasesrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsinetsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitslibasyncsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitslibgdsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitslibpngsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsmysqlsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsncursessrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsopenglsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsoraclesrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitspaszlibsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitspostgressrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsregexprsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitssvgalibsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitssyslogsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsuncgisrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsunzipsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsutmpsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsx11src.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitszlibsrc.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/docs.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/demo.tar.gz --directory ${TEMP_PREFIX}
.endif

do-install: install-parse-plist install-run-scripts run-pkg-install-script

# Contributed by <lioux@FreeBSD.org>
install-parse-plist: generate-plist
	@${PERL} -e 'open(FHANDLER,"${TMPPLIST}");' \
		-e 'open(FDIR,">${WRKDIR}/dirs.sh.tmp");' \
		-e 'open(FFILES,">${WRKDIR}/files.sh");' \
		-e 'while (!eof(FHANDLER)) {' \
			-e 'chop($$file = <FHANDLER>);' \
			-e '$$dir = $$file_partial = $$file;' \
			-e '$$file_partial =~ s!^${HLDSDIR:S!^/!!}!!;' \
			-e 'if ($$dir =~ s!(^\@dirrm\s+)!!) {' \
				-e 'print FDIR "${INSTALL_DATA_DIR}", \
					" ", "\"${PREFIX}/$$dir\"", \
					"\n";' \
			-e '} elsif ($$file !~ m!^\@!) {' \
				-e 'if ($$dir =~ m!^bin!) {' \
					-e 'print FFILES "${INSTALL_PROGRAM}";' \
				-e '} elsif ($$dir =~ m!^(lib|share)!) {' \
					-e 'print FFILES "${INSTALL_DATA}";' \
				-e '} elsif ($$dir =~ m!^man!) {' \
					-e 'print FFILES "${INSTALL_MAN}";' \
					-e '($$file_partial =~ s!${MANEXT}$$!!);' \
					-e '($$file =~ s!${MANEXT}$$!!);' \
				-e '}' \
				-e 'print FFILES " ", "\"${TEMP_PREFIX}/$$file_partial\"", \
					" ", "\"${PREFIX}/$$file\"", \
					"\n";' \
			-e '}' \
		-e '}' \
		-e 'close(FFILES);' \
		-e 'close(FDIR);' \
		-e 'close(FHANDLER);'
	@${SORT} ${WRKDIR}/dirs.sh.tmp > ${WRKDIR}/dirs.sh

install-run-scripts:
.for script in dirs files
	@${SH} ${WRKDIR}/${script}.sh
.endfor

run-pkg-install-script:
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} \
		${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
