# New ports collection makefile for:	Mixxx
# Date created:			25 Jun 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	mixxx
PORTVERSION=	1.4.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	A DJ mixing application

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	samplerate:${PORTSDIR}/audio/libsamplerate \
		portaudio:${PORTSDIR}/audio/portaudio \
		mad:${PORTSDIR}/audio/libmad \
		id3tag:${PORTSDIR}/audio/libid3tag \
		vorbis:${PORTSDIR}/audio/libvorbis \
		sndfile:${PORTSDIR}/audio/libsndfile

USE_X_PREFIX=	yes
USE_QT_VER=	3
HAS_CONFIGURE=	yes

CONFIGURE_WRKSRC=	${WRKSRC}/src
BUILD_WRKSRC=	${WRKSRC}/src
INSTALL_WRKSRC=	${WRKSRC}/src

CONFIGURE_ENV=	QTDIR="${X11BASE}" QMAKESPEC="freebsd-g++"
CONFIGURE_ARGS=	--prefix=${PREFIX}
MAKE_ENV=	QTDIR="${X11BASE}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	does not compile on FreeBSD 4.x, due to lack of pselect() in libc
.endif

.if ${OSVERSION} < 503001
IGNORE= does not compile on FreeBSD < 5.3, due to lack of round() in libm
.endif

post-patch:
	@${REINPLACE_CMD} \
		-e 's|/bin/bash|${LOCALBASE}&| ; \
		    s|$$QTDIR/bin/qmake|${LOCALBASE}/bin/qmake|g' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${REINPLACE_CMD} \
		-e 's|system( ld|& -shared -L${LOCALBASE}/lib -L${X11BASE}/lib|' \
		${CONFIGURE_WRKSRC}/check.qbas
	@${REINPLACE_CMD} \
		-e 's|/usr/local|${LOCALBASE}|; s|/opt|${X11BASE}|' \
		${CONFIGURE_WRKSRC}/paths.qbas

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Mixxx-Manual.pdf ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
