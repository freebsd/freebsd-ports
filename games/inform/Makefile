# New ports collection makefile for:	inform
# Version required:			6.15 (Library: 6/8)
# Date created:				28 June 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $Id: Makefile,v 1.2 1999/01/08 00:15:21 mph Exp $
#

DISTNAME=	inform-6.15
CATEGORIES=	games
MASTER_SITES=  	ftp://ftp.gmd.de/if-archive/infocom/compilers/inform6/source/ \
		ftp://ftp.gmd.de/if-archive/infocom/compilers/inform6/library/
DISTFILES=	inform615_source.zip inform_library68.zip

.if !defined(NOPORTDOCS)
MASTER_SITES+=	ftp://ftp.gmd.de/if-archive/infocom/compilers/inform6/manuals/
DISTFILES+=	designers_manual_html.zip
.endif

MAINTAINER=	mph@freebsd.org

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

DIST_SUBDIR=	inform
NO_WRKSUBDIR=	yes

EXTRACT_ONLY=		inform615_source.zip
EXTRACT_CMD=		unzip
EXTRACT_BEFORE_ARGS=	-qq
EXTRACT_AFTER_ARGS=	# empty

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
		unzip -qq ${DISTDIR}/${DIST_SUBDIR}/inform_library68.zip)
.for file in English Grammar Parser Verblib linklpa linklv parserm verblibm
	@${MV} ${PREFIX}/share/inform/${file} ${PREFIX}/share/inform/${file}.h
	@ chmod ${SHAREMODE} ${PREFIX}/share/inform/${file}.h
	@ chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/inform/${file}.h
.endfor
	@${LN} -s Verblib.h ${PREFIX}/share/inform/VerbLib.h
	@ chown ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/inform/VerbLib.h \
		${PREFIX}/share/inform/Relnote
	@ chmod ${SHAREMODE} ${PREFIX}/share/inform/Relnote
.if !defined(NOPORTDOCS)
	@ (umask 222 && unzip -qq -d ${PREFIX}/share/doc \
		${DISTDIR}/${DIST_SUBDIR}/designers_manual_html.zip)
	@${MV} ${PREFIX}/share/doc/dman ${PREFIX}/share/doc/inform
	@ chown -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/inform
.endif

.include <bsd.port.mk>
