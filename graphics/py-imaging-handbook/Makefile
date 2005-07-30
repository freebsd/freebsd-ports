# New ports collection makefile for:	PIL handbook
# Date created:		18th October 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	imaging-handbook
PORTVERSION=	1.1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/library/pil/handbook/ \
		http://www.pythonware.com/images/ \
		http://www.pythonware.com/
PKGNAMEPREFIX=	py-
DISTFILES=	blank.gif blurb-works-1.2.gif concepts.htm \
		concept1.gif decoder.htm formats.htm \
		icon-works.gif image.htm imagechops.htm \
		imagecolor.htm imagecrackcode.htm imagedraw.htm \
		imageenhance.htm imagefile.htm imagefileio.htm imagefilter.htm \
		imagefont.htm imagegrab.htm imagemath.htm imageops.htm \
		imagepath.htm imagepalette.htm \
		imagesequence.htm imagestat.htm imagetk.htm \
		imagewin.htm index.htm introduction.htm license.htm \
		mailto-light.gif overview.htm \
		pilconvert.htm pildriver.htm pilfile.htm \
		pilfont.htm pilprint.htm preface.htm psdraw.htm pythonware.css \
		remote-light.gif support.htm tutorial.htm

DEPRECATED=	"unmaintained port mirroring a website, maintenance problems"
EXPIRATION_DATE=2005-08-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Python Imaging Library Handbook

DIST_SUBDIR=	pil
EXTRACT_ONLY=

do-build:
.for file in ${DISTFILES}
	${SED} 's|\.\./\.\./\.\./pythonware\.css|pythonware.css|g ; \
		s|\.\./\.\./\.\./images/||g' \
		${DISTDIR}/${DIST_SUBDIR}/${file} > ${WRKDIR}/${file}
.endfor

do-install:
	@${MKDIR} ${PREFIX}/share/doc/PIL/handbook
	@cd ${WRKDIR} && ${INSTALL_DATA} ${DISTFILES} \
		${PREFIX}/share/doc/PIL/handbook

.include <bsd.port.mk>
