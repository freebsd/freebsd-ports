# ports collection makefile for:   fluidsynth
# Date created:        27 Nov 2003
# Whom:                Juha Nygard <juha.nygard1@netikka.fi>
#
# $FreeBSD$
#

PORTNAME=	fluidsynth
PORTVERSION=	1.0.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	fluid

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	Real-time software synthesizer based on the SoundFont 2 specifications

INSTALLS_SHLIB=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETOPT_LONG=	yes
USE_INC_LIBTOOL_VER=	13
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" LIBS="${PTHREAD_LIBS}"

MAN1=		fluidsynth.1

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386 and !amd64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|' ${WRKSRC}/Makefile.in

.include <bsd.port.post.mk>
