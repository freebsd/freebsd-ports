# New ports collection makefile for:	PIL handbook
# Date created:		18th October 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	imaging-handbook
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/library/pil/handbook/
PKGNAMEPREFIX=	py-
DISTFILES=	labdoc.css index.htm overview.htm concepts.htm \
		intro01.htm support.htm license.htm image.htm \
		imagechops.htm imagedraw.htm imageenhance.htm \
		imagefilter.htm imagefileio.htm imagefont.htm \
		imagepalette.htm imagesequence.htm imagestat.htm \
		imagetk.htm imagewin.htm psdraw.htm pilconvert.htm \
		pildriver.htm pilfile.htm pilfont.htm pilprint.htm \
		formats.htm decoder.htm

MAINTAINER=	john@coastalgeology.org

DIST_SUBDIR=	pil
EXTRACT_ONLY=
NO_BUILD=	yes

do-install:
	@${MKDIR} ${PREFIX}/share/doc/PIL/handbook
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.css ${PREFIX}/share/doc/PIL/handbook
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.htm ${PREFIX}/share/doc/PIL/handbook

.include <bsd.port.mk>
