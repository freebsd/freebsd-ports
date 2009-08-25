# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	3.11
PORTREVISION=	3
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/fldigi-distro/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

BUILD_DEPENDS=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2 \
		fltk-threads>=0:${PORTSDIR}/x11-toolkits/fltk-threads
LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib \
		sndfile:${PORTSDIR}/audio/libsndfile \
		boost_wave:${PORTSDIR}/devel/boost-libs \
		pulse:${PORTSDIR}/audio/pulseaudio

USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes

MAN1=		fldigi.1

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Fails to install
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|^CPPFLAGS|#CPPFLAGS|' \
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
