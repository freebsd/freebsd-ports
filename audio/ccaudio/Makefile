# New ports collection makefile for:	ccaudio
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccaudio
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	ccaudio

MAINTAINER=	ports@FreeBSD.org
COMMENT=	"C++ class framework for manipulating audio files"

BUILD_DEPENDS=	ccgnu2-config:${PORTSDIR}/devel/commoncpp

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"

MAN3=		Audio.3cc AudioCodec.3cc AudioCopy.3cc AudioFile.3cc \
		AudioRegisterCodec.3cc AudioSample.3cc AudioTone.3cc \
		CDAudio.3cc

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -e 's|-release \@LT_RELEASE\@||g'

.include <bsd.port.mk>
