# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inform
PORTVERSION=	6.32
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/source/ \
		ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/library/:lib
DIST_SUBDIR=	inform
DISTFILES=	inform${PORTVERSION:S/.//}_source.zip inform_library611.zip:lib
.if !defined(NOPORTDOCS)
MASTER_SITES+=	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/:doc
DISTFILES+=	designers_manual_4.zip:doc
.endif
EXTRACT_ONLY=	inform${PORTVERSION:S/.//}_source.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for producing text adventure games

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes

USE_ZIP=	yes
MAKEFILE=	${FILESDIR}/Makefile.inform

# Install the library files in ${PREFIX}/share/inform, and install
# documentation if appropriate.

NO_STAGE=	yes
post-install:
	@${MKDIR} ${DATADIR}
	(cd ${DATADIR} && \
		${UNZIP_CMD} -qq -o ${DISTDIR}/${DIST_SUBDIR}/inform_library611.zip)
.for file in English.h Grammar.h Parser.h VerbLib.h infix.h linklpa.h \
		linklv.h parserm.h verblibm.h
	${CHMOD} ${SHAREMODE} ${DATADIR}/${file}
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${DATADIR}/${file}
.endfor
.if defined(NOPORTDOCS)
	@${RM} ${DATADIR}/readme.txt
.else
	@${MKDIR} ${DOCSDIR}
	(umask 222 && ${UNZIP_CMD} -qq -o -d ${DOCSDIR} \
		${DISTDIR}/${DIST_SUBDIR}/designers_manual_4.zip)
	@${MV} ${DATADIR}/readme.txt ${DOCSDIR}
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
