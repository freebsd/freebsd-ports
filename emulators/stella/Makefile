# New ports collection makefile for:   stella-0.6
# Version required:	0.6
# Date created:		1st May, 1997
# Whom:			Joel Sutton <sutton@aardvark.apana.org.au>
#
# $Id: Makefile,v 1.2 1998/03/22 21:35:23 jseger Exp $
#

DISTNAME=	stella-0.6-src
PKGNAME=	stella-0.6
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.ucpel.tche.br/pub/msdos/emulator/atari/

MAINTAINER=	sutton@aardvark.apana.org.au

MANUAL_PACKAGE_BUILD=	installs bin/elk

DIST_SUBDIR=	atari
WRKSRC=		${WRKDIR}/${PKGNAME}/src
MAKEFILE=	makefile
ALL_TARGET=	freebsd-oss

# Directories and extra files
#
STELLA_DOC=	${PREFIX}/share/doc/stella
STELLA_LIB=	${PREFIX}/lib/stella
STELLA_ROM=	ELK.BIN OKIEDOKE.BIN TEST.BIN
STELLA_SH=	elk okiedoke
SED_CONFIG=	${STELLA_LIB:S/\//\\\//g}
DOC_FILES= 	Announce.txt Stella.txt Todo.txt doc/elk.doc doc/okiedoke.doc

post-configure:
	@${ECHO_MSG} "===>  Processing shell scripts"
	for file in ${STELLA_SH} ; do \
	   ${SED} "s/GUMBY/${SED_CONFIG}/g" < ${FILESDIR}/$$file.sh \
		   > ${WRKSRC}/$$file ;\
	done

do-install:
	@${ECHO_MSG} "===>  Installing binaries"
	${INSTALL_PROGRAM} ${WRKSRC}/xstella ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/sound/stella-sound ${PREFIX}/bin
	@${ECHO_MSG} "===>  Installing ROM files"
	-${MKDIR} ${STELLA_LIB}
	for file in ${STELLA_ROM} ; do \
		${INSTALL_DATA} ${WRKSRC}/../ROMS/$$file ${STELLA_LIB}/ ;\
	done
	@${ECHO_MSG} "===>  Installing vcs files"
	for file in ${WRKSRC}/../vcs/* ; do \
		${INSTALL_DATA} $$file ${STELLA_LIB}/ ;\
	done
	@${ECHO_MSG} "===>  Installing scripts"
	for file in ${STELLA_SH} ; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$file ${PREFIX}/bin ;\
	done
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing distribution document files"
	-${MKDIR} ${STELLA_DOC}
	for file in ${DOC_FILES} ; do \
		${INSTALL_DATA} ${WRKSRC}/../$$file ${STELLA_DOC}/ ;\
	done
	${INSTALL_DATA} ${PKGDIR}/DESCR ${STELLA_DOC}/README.FreeBSD
.endif

.include <bsd.port.mk>
