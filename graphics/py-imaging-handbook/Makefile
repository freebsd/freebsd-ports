# New ports collection makefile for:	PIL handbook
# Date created:		18th October 1999
# Whom:			Jose Marques
#
# $FreeBSD$
#

PORTNAME=	imaging-handbook
PORTVERSION=	1.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.pythonware.com/library/pil/handbook/ \
		http://www.pythonware.com/images/ \
		http://www.pythonware.com/
PKGNAMEPREFIX=	py-
DISTFILES=	appendices.htm blank.gif blurb-works-1.2.gif concepts.htm \
		concept1.gif getting-support.htm icon-works.gif \
		image-file-formats.htm image.htm imagechops.htm \
		imagecrackcode.htm imagedraw.htm imageenhance.htm \
		imagefile.htm imagefileio.htm imagefilter.htm imagefont.htm \
		imagepath.htm imagesequence.htm imagestat.htm imagetk.htm \
		imagewin.htm index.htm introducing-pil.htm mailto-light.gif \
		module-reference.htm pilconvert.htm pildriver.htm pilfile.htm \
		pilfont.htm pilprint.htm preface.htm psdraw.htm pythonware.css \
		remote-light.gif software-license.htm tools-reference.htm \
		tutorial.htm writing-your-own-file-decoder.htm

MAINTAINER=	ports@FreeBSD.org

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
