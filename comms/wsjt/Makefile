# New ports collection makefile for:	wsjt
# Date created:				3rd August 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	wsjt
PORTVERSION=	5.9.7
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_BERLIOS:S/%SUBDIR%/wsjt/} \
		${MASTER_SITE_LOCAL:S/%SUBDIR%/db/}
DISTNAME=	wsjt-5.9.7.r386
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Weak signal ham radio communication package

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy \
		${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		${PYNUMPY}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSDIR}/x11-toolkits/py-tkinter/ \
		${PYTHON_SITELIBDIR}/PIL.pth:${PORTSDIR}/graphics/py-imaging
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate

USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-portaudio-include-dir=${LOCALBASE}/include/portaudio2 \
		--with-portaudio-lib-dir=${LOCALBASE}/lib/portaudio2
USE_GMAKE=	yes
USE_PYTHON=	2.4+
USE_AUTOTOOLS=	libtool:22

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
.for d in ${WRKSRC}/WSJT_Quick_Reference.pdf  ${WRKSRC}/WSJT_Source_Code.txt \
	${WRKSRC}/WSJT_User_600.pdf ${WRKSRC}/UpdateHistory.txt \
	${WRKSRC}/WSJT_Source_Code.txt ${WRKSRC}/LICENSE.TXT
	@${INSTALL_DATA} ${WRKSRC}/${d} ${DOCSDIR}
.endfor
	@${ECHO} ""
	@${ECHO} "docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
