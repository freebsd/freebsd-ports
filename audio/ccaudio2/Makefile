# New ports collection makefile for:	ccaudio
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccaudio
PORTVERSION=	0.2.3
CATEGORIES=	audio
MASTER_SITES=	ftp://www.voxilla.org/pub/ccaudio/

MAINTAINER=	dyfet@gnu.org

LIB_DEPENDS=	ccstd.0:${PORTSDIR}/devel/commoncpp

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
INSTALLS_SHLIB=	yes

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|-release \@LT_RELEASE\@||g'

.include <bsd.port.mk>
