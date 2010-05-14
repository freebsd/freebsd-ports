# New ports collection makefile for: py-fastaudio
# Date created:		3 March 2007
# Whom:			Pontus Stenetorp <ninjin@kth.se>
#			Carl Johan Gustavsson <cjg@bsdmail.org>
#
# $FreeBSD$
#

PORTNAME=	fastaudio
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio python
MASTER_SITES=	http://www.freenet.org.nz/python/pyPortAudio/:site1 \
		http://www.portaudio.com/archives/:site2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	fastaudio
DISTFILES=	fastaudio.tar.gz:site1 portaudio_v18_1.zip:site2
DIST_SUBDIR=	python

MAINTAINER=	ninjin@kth.se
COMMENT=	Python bindings for the PortAudio multi-platform audio library

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex
LIB_DEPENDS=	portaudio:${PORTSDIR}/audio/portaudio \
		sndfile:${PORTSDIR}/audio/libsndfile

PLIST_FILES=	lib/%%PYTHON_VERSION%%/site-packages/fastaudio.so
PLIST_DIRS=
EXAMPLESDIR=	${LOCALBASE}/share/examples/py-${PORTNAME}

USE_ZIP=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=yes

FASTA_SRCFILE=	fastaudio.tar.gz
PORTA_SRCFILE=	portaudio_v18_1.zip
PORTASRC_DIR=	${WRKDIR}/portaudio_v18_1/

.if !defined(WITHOUT_EXAMPLES)
PLIST_DIRS+=	share/examples/py-${PORTNAME}
PLIST_FILES+=	share/examples/py-${PORTNAME}/demo.py
.endif

do-extract:
	@${MKDIR} ${WRKDIR}
	@${TAR} zxf ${DISTDIR}/${DIST_SUBDIR}/${FASTA_SRCFILE} -C ${WRKDIR}
	@${UNZIP_CMD} -q -d ${WRKDIR}/ \
		${DISTDIR}/${DIST_SUBDIR}/${PORTA_SRCFILE}

post-patch:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/setup.py ${WRKSRC}/mysndfile.h ${WRKSRC}/fastaudio.pyx
# Borrowed from the portaudio port, fixes obsolete path
	@${REINPLACE_CMD} -e 's|machine\/soundcard.h|sys\/soundcard.h|' \
		${PORTASRC_DIR}/pa_unix_oss/pa_unix_oss.c

post-install:
.if !defined(WITHOUT_EXAMPLES)
	( ${MKDIR} ${EXAMPLESDIR} && \
		${INSTALL_DATA} ${WRKSRC}/demo.py ${EXAMPLESDIR}/ )
.endif

.include <bsd.port.mk>
