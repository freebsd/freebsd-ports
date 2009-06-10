# New ports collection makefile for:	liblastfm
# Date created:				Wed Jan 1 00:48:58 EST 2006
# Whom:					Matt Tosto <datahead4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	liblastfm
PORTVERSION=	0.2.1
CATEGORIES=	audio
MASTER_SITES=	http://cdn.last.fm/src/

MAINTAINER=	datahead4@gmail.com
COMMENT=	Collection of libraries to help integrate Last.fm services

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fftw3f.5:${PORTSDIR}/math/fftw3-float \
		mad.2:${PORTSDIR}/audio/libmad

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
	${FIND} ${WRKSRC}/admin -type f | ${XARGS} \
		 ${REINPLACE_CMD} -e 's|\#\!\/usr\/bin\/ruby|\#\!\/usr\/local\/bin\/ruby|'

.include <bsd.port.mk>
