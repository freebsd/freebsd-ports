# New ports collection makefile for:	wsjt
# Date created:				3rd August 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	wsjt
PORTVERSION=	5.9.6
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	wsjt
DISTNAME=	wsjt-5.9.6.r309
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Weak signal ham radio communication pakage

BUILD_DEPENDS=	gfortran42:${PORTSDIR}/lang/gcc42 \
		${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		${PYNUMPY}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter/ \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate

WANT_FORTRAN=	yes	#dummy
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.4+
USE_AUTOTOOLS=	libtool:15

post-extract:
	@${MV} ${WRKDIR}/wsjt596r309 ${WRKDIR}/wsjt-5.9.6.r309

post-patch:
	${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
	-e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
	${WRKSRC}/configure

do-install:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/CALL3.TXT ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/wsjt.py ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/wsjt ${PREFIX}/bin
.for d in ${WRKSRC}/Audio.so ${WRKSRC}/Pmw.py \
	${WRKSRC}/PmwBlt.py ${WRKSRC}/palettes.py \
	${WRKSRC}/PmwColor.py ${WRKSRC}/go.py \
	${WRKSRC}/specjt.py ${WRKSRC}/astro.py \
	${WRKSRC}/options.py ${WRKSRC}/smeter.py ${WRKSRC}/g.py
	@${INSTALL_DATA} ${WRKSRC}/${d} ${PYTHON_SITELIBDIR}
.endfor
.if	!defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for d in ${WRKSRC}/Announce.txt ${WRKSRC}/UpdateHistory.txt\
	${WRKSRC}/LICENSE.TXT WSJT_Source_Code.txt
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
