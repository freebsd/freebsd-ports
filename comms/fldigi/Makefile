# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	2.10.3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/fldigi-distro/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

BUILD_DEPENDS=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	fltk:${PORTSDIR}/x11-toolkits/fltk-threads \
		hamlib:${PORTSDIR}/comms/hamlib \
		sndfile:${PORTSDIR}/audio/libsndfile \
		boost_wave:${PORTSDIR}/devel/boost \
		pulse:${PORTSDIR}/audio/pulseaudio

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64" && ${OSVERSION} < 700000
USE_GCC=	4.1
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Fails to install
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		${WRKSRC}/src/Makefile

post-install:
.if	!defined(NOPORTDOCS)
	@${ECHO} ""
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} "fldigi docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
