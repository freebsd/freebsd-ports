# New ports collection makefile for:	gimp-manual-1.0.0
# Version required:	1.0.0
# Date created:		5 June 1998
# Whom:			Brett Taylor
#
# $Id: Makefile,v 1.2 1998/06/16 11:29:35 asami Exp $
#

DISTNAME=	GimpUserManual-1.0.0
PKGNAME=	GimpUserManual-${DOCFORMAT}-1.0.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://manual.gimp.org/pub/manual/

MAINTAINER=	brett@peloton.physics.montana.edu

MANUAL_PACKAGE_BUILD=\
		"User must choose which version of the manual to install."

.if !defined(DOCFORMAT)
DOCFORMAT=HTML
DOCFORMAT_UNSPECIFIED=YES
.else
.if ${DOCFORMAT} != "HTML" && ${DOCFORMAT} != "PDF" && ${DOCFORMAT} != "PS"
DOCFORMAT_INVALID=YES
.endif
.endif

pre-fetch:
	@${ECHO} "This manual is available in three formats: HTML, PDF, and"
	@${ECHO} "PS (PostScript).  To choose the one you want, type:"
	@${ECHO} "     make DOCFORMAT={HTML,PDF,PS} [install]"
	@${ECHO} "Also please note that the manual is pretty darn big."
	@${ECHO} "The gzip'ed PS version is 44 MB (unpacks to 173 MB),"
	@${ECHO} "the PDF version is 14 MB and the HTML tar-bzip'ed"
	@${ECHO} "version is 16 MB (unpacks to 18.7 MB)."

.if defined(DOCFORMAT_UNSPECIFIED)
	@${ECHO} "(DOCFORMAT not specified: defaulting to HTML format.)"
.elif defined(DOCFORMAT_INVALID)
	@echo "ERROR: invalid value for DOCFORMAT: \"${DOCFORMAT}\""
	@echo "Possible values are:  HTML (default), PDF, PS."
	@${FALSE}
.endif

.if ${DOCFORMAT} == "HTML"
EXTRACT_SUFX=	-html.tar.bz2
WRKSRC=		${WRKDIR}/GimpUserManaul_v1.0.0

BUILD_DEPENDS=	bzip2:${PORTSDIR}/archivers/bzip2

USE_X_PREFIX=	yes

NO_BUILD=	yes

pre-extract:
	@${CP} ${PKGDIR}/PLIST_${DOCFORMAT} ${PKGDIR}/PLIST

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

post-fetch:
	@${MKDIR} ${WRKDIR}

pre-install:
	@${CP} ${PKGDIR}/PLIST_PDF ${PKGDIR}/PLIST

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

pre-extract:
	@${CP} ${PKGDIR}/PLIST_PS ${PKGDIR}/PLIST

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gimp
	@${CP} ${WRKDIR}/GimpUserManual-1.0.0-ps ${PREFIX}/share/doc/gimp
.endif

.include <bsd.port.mk>
