# New ports collection makefile for:	ccaudio
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccaudio
PORTVERSION=	1.1.1
PORTREVISION=	0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNU:S/$/:gnu/} \
		${MASTER_SITE_SOURCEFORGE:S/$/:sf/}
MASTER_SITE_SUBDIR=	ccaudio/:gnu \
			bayonne/:sf
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:gnu \
		${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:sf

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

BUILD_DEPENDS=	ccgnu2-config:${PORTSDIR}/devel/commoncpp

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN3=		Audio.3cc AudioCodec.3cc AudioCopy.3cc AudioFile.3cc \
		AudioSample.3cc AudioTone.3cc CDAudio.3cc DTMFDetect.3cc \
		LinearSample.3cc

post-install:
.for m in ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/doc/man3/${m} ${MAN3PREFIX}/man/man3
.endfor

.include <bsd.port.mk>
