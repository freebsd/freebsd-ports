# New ports collection makefile for:	gimp-manual
# Date created:		5 June 1998
# Whom:			Brett Taylor
#
# $FreeBSD$
#

PORTNAME=	GimpUserManual
PORTVERSION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://kefk.net/Open_Source/FS/GIMP/Download/GUM/ \
		http://ftp.nluug.nl/ftp/graphics/gimp/manual/
PKGNAMESUFFIX=	-${DOCFORMAT}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The user manual for the GNU Image Manipulation Program (GIMP)

.if !defined(DOCFORMAT)
DOCFORMAT=HTML
.else
.if ${DOCFORMAT} != "HTML" && ${DOCFORMAT} != "PDF"
.BEGIN:
	@${ECHO_MSG} "ERROR: invalid value for DOCFORMAT: \"${DOCFORMAT}\""
	@${ECHO_MSG} "Possible values are:  HTML, PDF."
	@${FALSE}
.endif
.endif

PLIST=		${PKGDIR}/pkg-plist_${DOCFORMAT}

pre-everything::
	@${ECHO_MSG} "This manual is available in two formats: HTML and PDF."
	@${ECHO_MSG} "Note that the manual is pretty darn big."

PREFIX?=	${X11BASE}	# This port itself does not require Xlib
EXTRACT_ONLY=	#empty
NO_BUILD=	yes

.if ${DOCFORMAT} == "HTML"
DISTFILES=	GimpUsersManual_SecondEdition-HTML_Color.tar.gz \
		GimpUsersManual_SecondEdition-HTML_Search.tar.gz

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gimp
	for file in ${DISTFILES} ; do \
		cd ${PREFIX}/share/doc/gimp; \
		${TAR} -zxf ${DISTDIR}/$${file}; \
		${CHOWN} -R root:wheel ${PREFIX}/share/doc/gimp; \
	done
.endif

.if ${DOCFORMAT} == "PDF"
DISTFILES=	GimpUsersManual_SecondEdition-PDF_Color.pdf \
		GimpUsersManual_SecondEdition-PDF.pdf

EXTRACT_ONLY=	#empty
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/gimp
	for file in ${DISTFILES} ; do \
		${INSTALL_DATA} ${DISTDIR}/$${file} ${PREFIX}/share/doc/gimp/ ; \
	done
.endif

.include <bsd.port.mk>
