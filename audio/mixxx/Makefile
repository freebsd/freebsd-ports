# New ports collection makefile for:	Mixxx
# Date created:			25 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		mixxx
PORTVERSION=		1.3.2
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@brutele.be
COMMENT=		A DJ mixing application

BUILD_DEPENDS=		bash:${PORTSDIR}/shells/bash2 \
			qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=		samplerate:${PORTSDIR}/audio/libsamplerate \
			portaudio:${PORTSDIR}/audio/portaudio \
			mad:${PORTSDIR}/audio/libmad \
			id3tag:${PORTSDIR}/audio/libid3tag \
			vorbis:${PORTSDIR}/audio/libvorbis \
			sndfile:${PORTSDIR}/audio/libsndfile

USE_X_PREFIX=		yes
USE_QT_VER=		3
USE_REINPLACE=		yes
HAS_CONFIGURE=		yes

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=		${WRKSRC}/src
INSTALL_WRKSRC=		${WRKSRC}/src

CONFIGURE_ENV=		QTDIR="${X11BASE}" \
			QMAKESPEC="freebsd-g++" \
			NOPORTDOCS="${NOPORTDOCS}"
MAKE_ENV=		QTDIR="${X11BASE}"

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=		--prefix=${PREFIX}

.if ${OSVERSION} >= 502126
BROKEN=			"Does not compile on FreeBSD >= 5.x"
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|@LOCALBASE@|${LOCALBASE}|g' \
		-e 's|@X11BASE@|${X11BASE}|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${CONFIGURE_WRKSRC}/check.qbas

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Mixxx-Manual.pdf ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
