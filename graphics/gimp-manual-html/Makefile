# New ports collection makefile for:	gimp-manual-1.0.0
# Version required:	1.0.0
# Date created:		5 June 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.7 1998/12/04 22:10:57 billf Exp $
#

DISTNAME=	GimpUserManual-1.0.0
PKGNAME=	GimpUserManual-${DOCFORMAT}-1.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://manual.gimp.org/pub/manual/

MAINTAINER=	brett@peloton.physics.montana.edu

.if !defined(DOCFORMAT)
DOCFORMAT=HTML
.else
.if ${DOCFORMAT} != "HTML" && ${DOCFORMAT} != "PDF" && ${DOCFORMAT} != "PS"
.BEGIN:
	@${ECHO} "ERROR: invalid value for DOCFORMAT: \"${DOCFORMAT}\""
	@${ECHO} "Possible values are:  HTML, PDF, PS."
	@${FALSE}
.endif
.endif

PLIST=		${PKGDIR}/PLIST_${DOCFORMAT}

pre-fetch:
	@${ECHO} "This manual is available in three formats: HTML, PDF, and"
	@${ECHO} "PS (PostScript).  Note that the manual is pretty darn big."
	@${ECHO} "The gzip'ed PS version is 44 MB (unpacks to 173 MB),"
	@${ECHO} "the PDF version is 14 MB and the HTML tar-bzip'ed"
	@${ECHO} "version is 16 MB (unpacks to 18.7 MB)."

.if ${DOCFORMAT} == "HTML"
EXTRACT_SUFX=	-html.tar.bz2
WRKSRC=		${WRKDIR}/GimpUserManaul_v1.0.0

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

USE_X_PREFIX=	yes
NO_BUILD=	yes

EXTRACT_CMD=	bzip2
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= | tar -xf -

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gimp
	@${CP} ${WRKSRC}/* ${PREFIX}/share/doc/gimp
.endif

.if ${DOCFORMAT} == "PDF"
DISTFILES=	GimpUserManual-1.0.0-pdf

EXTRACT_ONLY=	#empty
NO_BUILD=	yes
USE_X_PREFIX=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gimp
	@${CP} ${DISTDIR}/GimpUserManual-1.0.0-pdf ${PREFIX}/share/doc/gimp
.endif

.if ${DOCFORMAT} == "PS"
DISTNAME=	GimpUserManual-1.0.0-ps
EXTRACT_SUFX=	.gz
EXTRACT_CMD=	${GZIP_CMD}
EXTRACT_BEFORE_ARGS= -cd
EXTRACT_AFTER_ARGS= > ${DISTNAME}

NO_BUILD=	yes
USE_X_PREFIX=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gimp
	@${CP} ${WRKDIR}/GimpUserManual-1.0.0-ps ${PREFIX}/share/doc/gimp
.endif

.include <bsd.port.mk>
