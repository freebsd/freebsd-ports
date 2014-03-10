# Created by: Matthew Hunt <mph@FreeBSD.org>
# $FreeBSD$

PORTNAME=	inform
PORTVERSION=	6.32
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/source/ \
		ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/library/:lib \
		ftp://ftp.ifarchive.org/if-archive/infocom/compilers/inform6/manuals/:doc
DISTFILES=	inform${PORTVERSION:S/.//}_source.zip inform_library611.zip:lib \
		designers_manual_4.zip:doc
DIST_SUBDIR=	inform
EXTRACT_ONLY=	inform${PORTVERSION:S/.//}_source.zip

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compiler for producing text adventure games

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

NO_WRKSUBDIR=	yes

USES=		zip:infozip
MAKEFILE=	${FILESDIR}/Makefile.inform

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR}${DATADIR} && \
		${UNZIP_CMD} -qq -o ${DISTDIR}/${DIST_SUBDIR}/inform_library611.zip)
.for file in English.h Grammar.h Parser.h VerbLib.h infix.h linklpa.h \
		linklv.h parserm.h verblibm.h
	${CHMOD} ${SHAREMODE} ${STAGEDIR}${DATADIR}/${file}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(umask 222 && ${UNZIP_CMD} -qq -o -d ${STAGEDIR}${DOCSDIR} \
		${DISTDIR}/${DIST_SUBDIR}/designers_manual_4.zip)
	@${MV} ${STAGEDIR}${DATADIR}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
