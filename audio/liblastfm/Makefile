# New ports collection makefile for:	liblastfm
# Date created:				Jun 7 2009
# Whom:					Matt Tosto <datahead4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	liblastfm
PORTVERSION=	0.2.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cdn.last.fm/src/

MAINTAINER=	datahead4@gmail.com
COMMENT=	Collection of libraries to help integrate Last.fm services

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fftw3f.5:${PORTSDIR}/math/fftw3-float \
		mad.2:${PORTSDIR}/audio/libmad
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BZIP2=	yes
USE_RUBY=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib xml network sql gui qtestlib \
		qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

post-extract:
	${REINPLACE_CMD} -e 's|#!/bin/bash|#!${LOCALBASE}/bin/bash|' ${WRKSRC}/configure
	${FIND} ${WRKSRC}/admin -type f | ${XARGS} \
		 ${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${LOCALBASE}/bin/ruby|'

.include <bsd.port.mk>
