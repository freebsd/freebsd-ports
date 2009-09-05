# New ports collection makefile for:	liblastfm
# Date created:				Jun 7 2009
# Whom:					Matt Tosto <datahead4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	liblastfm
PORTVERSION=	0.3.0
CATEGORIES=	audio
MASTER_SITES=	http://cdn.last.fm/src/

MAINTAINER=	datahead4@gmail.com
COMMENT=	Collection of libraries to help integrate Last.fm services

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fftw3f.5:${PORTSDIR}/math/fftw3-float

USE_BZIP2=	yes
USE_RUBY=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib xml network sql gui qtestlib \
		qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	-release
MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

post-extract:
	${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${LOCALBASE}/bin/ruby|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|__demos __tests||' ${WRKSRC}/admin/Makefile.rb
	${REINPLACE_CMD} -e '/QMAKE_CXXFLAGS_RELEASE.*/d' \
		-e 's|linux:|unix:|'  ${WRKSRC}/.qmake.cache
	${FIND} ${WRKSRC}/admin -type f | ${XARGS} \
		 ${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${LOCALBASE}/bin/ruby|'

.include <bsd.port.mk>
