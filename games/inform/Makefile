# New ports collection makefile for:	inform
# Date created:				28 June 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inform
PORTVERSION=	6.21
CATEGORIES=	games
MASTER_SITES=  	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/source/ \
		ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/library/
DISTFILES=	inform621_source.zip inform_library610.zip

MAINTAINER=	mph@freebsd.org
COMMENT=	Compiler for producing text adventure games

.if !defined(NOPORTDOCS)
MASTER_SITES+=	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/old/
DISTFILES+=	designers_manual_html.zip
.endif

DIST_SUBDIR=	inform
NO_WRKSUBDIR=	yes

EXTRACT_ONLY=	inform621_source.zip
USE_ZIP=	yes
BUILD_DEPENDS=	unzip:/usr/ports/archivers/unzip

# I can hardly believe it, but the ".c" and ".h" extensions are
# not present on the source files.
post-extract:
	@${MV} ${WRKSRC}/header ${WRKSRC}/header.h
.for file in arrays asm bpatch chars directs errors expressc expressp \
	files inform lexer linker memory objects states symbols syntax \
	tables text veneer verbs
	@${MV} ${WRKSRC}/${file} ${WRKSRC}/${file}.c
.endfor
	@${CP} ${FILESDIR}/Makefile.inform ${WRKSRC}/Makefile

# Install the library files in ${PREFIX}/share/inform.  The compiler
# is configured to use extensions under Unix, so we need to tack ".h"
# onto each filename.  Set perms and ownership, because they're odd in
# the archive.  Many games include "VerbLib" instead of "Verblib" so
# make a symlink.  Finally, install documentation if appropriate.

post-install:
	@${MKDIR} ${PREFIX}/share/inform
	@(cd ${PREFIX}/share/inform && \
		unzip -qq -o ${DISTDIR}/${DIST_SUBDIR}/inform_library610.zip)
.for file in English Grammar Parser Verblib infix linklpa linklv parserm \
		verblibm
	@${MV} ${PREFIX}/share/inform/${file} ${PREFIX}/share/inform/${file}.h
	@ ${CHMOD} ${SHAREMODE} ${PREFIX}/share/inform/${file}.h
	@ ${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/inform/${file}.h
.endfor
	@${LN} -fs Verblib.h ${PREFIX}/share/inform/VerbLib.h
	@ ${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/inform/VerbLib.h
.if defined(NOPORTDOCS)
	@${RM} ${PREFIX}/share/inform/Relnote ${PREFIX}/share/inform/Relnote2
.else
	@ (umask 222 && unzip -qq -o -d ${PREFIX}/share/doc \
		${DISTDIR}/${DIST_SUBDIR}/designers_manual_html.zip)
	@${MKDIR} ${PREFIX}/share/doc/inform
	@${MV} ${PREFIX}/share/doc/dman/* ${PREFIX}/share/doc/inform
	@${RMDIR} ${PREFIX}/share/doc/dman
	@${MV} ${PREFIX}/share/inform/Relnote ${PREFIX}/share/inform/Relnote2 ${PREFIX}/share/doc/inform
	@ ${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/inform
	
.endif

.include <bsd.port.mk>
