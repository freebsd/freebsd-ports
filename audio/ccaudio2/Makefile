# New ports collection makefile for:	ccaudio
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccaudio
PORTVERSION=	1.1.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gnutelephony

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ class framework for manipulating audio files

LIB_DEPENDS=	ccgnu2-1.2.1:${PORTSDIR}/devel/commoncpp

USE_GNOME=	gnometarget
USE_REINPLACE=	yes
USE_LIBTOOL_VER=	15
INSTALL_TARGET=	install man
INSTALLS_SHLIB=	yes

MAN3=		Audio.3cc AudioCodec.3cc AudioCopy.3cc AudioFile.3cc \
		AudioSample.3cc AudioTone.3cc CDAudio.3cc DTMFDetect.3cc \
		LinearSample.3cc

post-patch:
	@${REINPLACE_CMD} -e \
		's|<stdint\.h>|<stdlib.h>|g' ${WRKSRC}/src/dtmf.cpp

.include <bsd.port.mk>
