# ports collection makefile for:	dap
# Date created:				23 August 1998
# Whom:					yoshiaki Uchikawa
#
# $FreeBSD$
#

PORTNAME=	dap
PORTVERSION=	2.1.5
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://cvsup1.theplanet.com/distfiles/ \
		http://www.sourcefiles.org/Multimedia/Soundfile_Editors/
EXTRACT_SUFX=.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio sample editing and processing suite

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

MAKEFILE=	Makefile.linux
USE_XORG=	xpm

MAKE_ENV+=	OTHER_INCLUDE_DIR=. OTHER_LIBRARY_DIR=.

PORTDOCS=	COPYING README THANKS TODO
PORTEXAMPLES=	testautopan.dsp \
		testmodulateddelay.dsp \
		testphaser.dsp \
		teststereoecho.dsp \
		testflanger.dsp \
		testmultitapdelay.dsp \
		testreverb.dsp	\
		weirdflanger.dsp
PLIST_FILES=	bin/DAP

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/DAP ${PREFIX}/bin/

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for _DOC in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${_DOC} ${DOCSDIR}/${_DOC}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for _EXAMPLE in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/main/effects/${_EXAMPLE} ${EXAMPLESDIR}/${_EXAMPLE}
.endfor
.endif

.include <bsd.port.mk>
