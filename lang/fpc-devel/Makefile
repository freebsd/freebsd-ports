# New ports collection makefile for:	Free Pascal Compiler
# Date created:				28 November 2001
# Whom:					John Merryweather Cooper et al
#
# $FreeBSD$
#

PORTNAME=	fpc
PORTVERSION=	1.0.4
CATEGORIES=	lang
MASTER_SITES=   ftp://ftp.freepascal.org/pub/fpc/dist/Freebsd/ \
		ftp://ftp.epix.net/pub/languages/pascal/dist/Freebsd/ \
		http://gd.tuwien.ac.at/languages/pascal/dist/Freebsd/ \
		http://www.zeus.rug.ac.be/freepascal/files/dist/Freebsd/ \
		ftp://ftp.darklands.cx/pub/fpc/dist/Freebsd/ \
		ftp://ftp.jp.freepascal.org/mirror/fpc/dist/Freebsd/ \
		ftp://deadlock.et.tudelft.nl/pub/fpc/dist/Freebsd/ \
		ftp://ftp.no.freepascal.org/pub/fpc/dist/Freebsd/
DISTNAME=	${PORTNAME}-${PORTVERSION}.freebsd4
EXTRACT_SUFX=	.tar

MAINTAINER=	jmcoopr@webmail.bmi.net

BUILD_DEPENDS=	${LOCALBASE}/bin/gtar:${PORTSDIR}/archivers/gtar
RUN_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm
.if !defined(NOPORTDOCS)
RUN_DEPENDS+=	${LOCALBASE}/bin/acroread4:${PORTSDIR}/print/acroread4
.endif

ONLY_FOR_ARCHS=	i386
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
USE_PERL5=	yes
PKGDEINSTALL=	${PKGINSTALL}

MAN1=		delp.1 fpc.1 fpcmake.1 h2pas.1 plex.1 ppc386.1 ppdep.1 \
		ppudump.1 ppufiles.1 ppumove.1 ptop.1 pyacc.1 rstconv.1
MAN5=		fpcmake.5 ppc386.cfg.5 ptop.cfg.5

# programs
SORT?=		/usr/bin/sort
TAR=		${LOCALBASE}/bin/gtar
# macro for creating directory with DATA perms
INSTALL_DATA_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m 0755

.include <bsd.port.pre.mk>

LIBDIR=		${PREFIX}/lib/fpc/${PORTVERSION}
DOCSDIR=	${PREFIX}/share/doc/fpc-${PORTVERSION}
TEMP_PREFIX=	${WRKSRC}/temp
TEMP_DOCSDIR=	${TEMP_PREFIX}/share/doc/fpc-${PORTVERSION}
TEMP_LIBDIR=	${TEMP_PREFIX}/lib/fpc/${PORTVERSION}
TEMP_EXMPDIR=	${TEMP_PREFIX}/share/examples

PLIST_SUB=	LIBDIR=${LIBDIR}

# install staging area
post-extract:
	@${TAR} xf ${WRKSRC}/binary.tar --directory ${WRKSRC}
	@${TAR} xf ${WRKSRC}/sources.tar --directory ${WRKSRC}
	@${MKDIR} ${TEMP_PREFIX}
#unpack base system
	@${TAR} zxf ${WRKSRC}/basefreebsd.tar.gz \
		--exclude-from ${FILESDIR}/tar-xlist \
		--directory ${TEMP_PREFIX}
	@${MKDIR} ${TEMP_DOCSDIR}
	@${TAR} zxf ${WRKSRC}/basefreebsd.tar.gz \
		--files-from ${FILESDIR}/tar-xlist \
		--directory ${TEMP_PREFIX}/share
#unpack units
	@${TAR} zxf ${WRKSRC}/utilfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsfclfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsapifreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsbasefreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsnetfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsdbfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsgfxfreebsd.tar.gz --directory ${TEMP_PREFIX}
	@${TAR} zxf ${WRKSRC}/unitsmiscfreebsd.tar.gz --directory ${TEMP_PREFIX}
.ifndef(NOPORTDOCS)
#unpack documentation, examples, and sources
	@${TAR} zxf ${WRKSRC}/basesrc.tar.gz --directory ${TEMP_PREFIX}/share
	@${TAR} zxf ${WRKSRC}/compilersrc.tar.gz \
		--exclude-from ${FILESDIR}/tar-xlist2 \
		--directory ${TEMP_PREFIX}/share
	@${TAR} zxf ${WRKSRC}/rtlsrc.tar.gz \
		--exclude-from ${FILESDIR}/tar-xlist3 \
		--directory ${TEMP_PREFIX}/share
	@${TAR} zxf ${WRKSRC}/fclsrc.tar.gz \
		--exclude-from ${FILESDIR}/tar-xlist4 \
		--directory ${TEMP_PREFIX}/share
	@${TAR} zxf ${WRKSRC}/apisrc.tar.gz --directory ${TEMP_PREFIX}/share
	@${TAR} zxf ${WRKSRC}/packagessrc.tar.gz --directory ${TEMP_PREFIX}/share
	@${TAR} zxf ${WRKSRC}/utilsrc.tar.gz --directory ${TEMP_PREFIX}/share

	@${TAR} zxf ${WRKSRC}/docs.tar.gz --directory ${TEMP_PREFIX}/share
	@${MKDIR} ${TEMP_EXMPDIR}
	@${TAR} zxf ${WRKSRC}/demo.tar.gz --directory ${TEMP_EXMPDIR}
	@${MV} ${TEMP_EXMPDIR}/src/fpc-${PORTVERSION} \
		${TEMP_PREFIX}/share/examples
.endif

do-patch:
#unpack and patch sample (working) configuration file
	@${PATCH} --dir ${TEMP_LIBDIR} < ${FILESDIR}/fix-samplecfg

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
