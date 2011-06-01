# New ports collection makefile for:	fldigi
# Date created:				December 20 2006
# Whom:					Diane Bruce <db@db.net>
#
# $FreeBSD$
#

PORTNAME=	fldigi
PORTVERSION=	3.21.10
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/fldigi/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	db@FreeBSD.org
COMMENT=	Digital decoder for psk, cw, psk31, olivia

BUILD_DEPENDS=	${LOCALBASE}/lib/portaudio2/libportaudio.so:${PORTSDIR}/audio/portaudio2
LIB_DEPENDS=	hamlib:${PORTSDIR}/comms/hamlib \
		sndfile:${PORTSDIR}/audio/libsndfile \
		boost_wave:${PORTSDIR}/devel/boost-libs \
		pulse:${PORTSDIR}/audio/pulseaudio \
		fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
LICENSE=	GPLv3

MAN1=		fldigi.1 flarq.1

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 700000
USE_GCC=	4.2+
.endif
.if ${ARCH} == "sparc64"
BROKEN=		Fails to install
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|png_infopp_NULL|NULL|' \
		 ${WRKSRC}/src/widgets/picture.cxx

post-configure:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|' \
		-e 's|^CPPFLAGS|#CPPFLAGS|' \
		${WRKSRC}/src/Makefile

do-build:
	(cd ${WRKSRC}/src;gmake)

post-install:
.if	!defined(NOPORTDOCS)
	@${ECHO} ""
	${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${ECHO} "fldigi docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif

.include <bsd.port.post.mk>
