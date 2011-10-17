# New ports collection makefile for:	liblastfm
# Date created:				Jun 7 2009
# Whom:					Matt Tosto <datahead4@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	liblastfm
PORTVERSION=	0.3.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	swills
DISTNAME=	mxcl-${PORTNAME}-${PORTVERSION}-0-gf0b3239

MAINTAINER=	datahead4@gmail.com
COMMENT=	Collection of libraries to help integrate Last.fm services

LIB_DEPENDS=	samplerate.1:${PORTSDIR}/audio/libsamplerate \
		fftw3f:${PORTSDIR}/math/fftw3-float

USE_RUBY=	yes
USE_GMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib xml network sql gui qtestlib \
		qmake_build moc_build rcc_build uic_build
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	-release --prefix ${PREFIX}
MAKE_JOBS_UNSAFE=	yes

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/mxcl-liblastfm-1c739eb

.include <bsd.port.pre.mk>
post-extract:
	${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${RUBY_WITH_SUFFIX}|' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|\`ruby |`${RUBY_WITH_SUFFIX} |' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|__demos __tests||' ${WRKSRC}/admin/Makefile.rb
	${REINPLACE_CMD} -e '/QMAKE_CXXFLAGS_RELEASE.*/d' \
		-e 's|linux:|unix:|'  ${WRKSRC}/.qmake.cache
	${FIND} ${WRKSRC}/admin -type f | ${XARGS} \
		 ${REINPLACE_CMD} -e 's|#!/usr/bin/ruby|#!${RUBY_WITH_SUFFIX}|'

.include <bsd.port.post.mk>
