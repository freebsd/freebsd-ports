# New ports collection makefile for:	inform
# Date created:				28 June 1998
# Whom:					Matthew Hunt <mph@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inform
PORTVERSION=	6.30
CATEGORIES=	games
MASTER_SITES=  	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/source/ \
		ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/library/
DISTFILES=	inform630_source.zip inform_library611.zip

MAINTAINER=	mph@freebsd.org
COMMENT=	Compiler for producing text adventure games

.if !defined(NOPORTDOCS)
MASTER_SITES+=	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/
DISTFILES+=	designers_manual_4.zip
.endif

DIST_SUBDIR=	inform
NO_WRKSUBDIR=	yes

EXTRACT_ONLY=	inform630_source.zip
USE_ZIP=	yes
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

post-extract:
	@${CP} ${FILESDIR}/Makefile.inform ${WRKSRC}/Makefile

# Install the library files in ${PREFIX}/share/inform, and install
# documentation if appropriate.

post-install:
	${MKDIR} ${PREFIX}/share/inform
	(cd ${PREFIX}/share/inform && \
		unzip -qq -o ${DISTDIR}/${DIST_SUBDIR}/inform_library611.zip)
.for file in English.h Grammar.h Parser.h VerbLib.h infix.h linklpa.h \
		linklv.h parserm.h verblibm.h
	${CHMOD} ${SHAREMODE} ${PREFIX}/share/inform/${file}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/inform/${file}
.endfor
.if defined(NOPORTDOCS)
	${RM} ${PREFIX}/share/inform/readme.txt
.else
	${MKDIR} ${PREFIX}/share/doc/inform
	(umask 222 && unzip -qq -o -d ${PREFIX}/share/doc/inform \
		${DISTDIR}/${DIST_SUBDIR}/designers_manual_4.zip)
	${MV} ${PREFIX}/share/inform/readme.txt ${PREFIX}/share/doc/inform
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/doc/inform
.endif


.include <bsd.port.mk>
