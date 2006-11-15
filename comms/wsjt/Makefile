# New ports collection makefile for:	wsjt
# Date created:				3rd August 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	wsjt
PORTVERSION=	5.9.6
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_BERLIOS}
MASTER_SITE_SUBDIR=	wsjt
DISTNAME=	wsjt-5.9.6.r309
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@db.net
COMMENT=	Weak signal ham radio communication pakage

BUILD_DEPENDS=	gfortran41:${PORTSDIR}/lang/gfortran \
		${PYTHON_SITELIBDIR}/scipy:${PORTSDIR}/science/py-scipy03 \
		${PYTHON_SITELIBDIR}/f2py2e:${PORTSDIR}/lang/f2py
#		${PYTHON_SITELIBDIR}/_tkinter.so:${PORTSIDR}/x11-toolkits/py-tkinter
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	WIP for amd64 and perhaps others

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	2.4+
PYNUMERIC=	yes
USE_AUTOTOOLS=	libtool:15

#
# This until Joe renames the tarball properly --db
#
post-extract:
	@${MV} ${WRKDIR}/wsjt596r309 ${WRKDIR}/wsjt-5.9.6.r309

pre-configure:
	@${CP} ${FILESDIR}/portaudio-v19-Makefile ${WRKSRC}/portaudio-v19/Makefile
	@${CP} ${FILESDIR}/portaudio-v19-config.status ${WRKSRC}/portaudio-v19/config.status

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
