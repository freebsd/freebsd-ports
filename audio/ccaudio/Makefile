# New ports collection makefile for:	ccaudio
# Date created:				26 July 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	ccaudio
PORTVERSION=	0.2.4
CATEGORIES=	audio
# Mastersite is broken regarding anonymous FTP, mirror is unreachable.
# I have informed the webmaster regarding this, hope to get an answer
# soon - edwin@freebsd.org 20021226
MASTER_SITES=	ftp://www.voxilla.org/pub/ccaudio/ \
		ftp://ftp.teklab.com/voxilla/pub/ccaudio/

MAINTAINER=	dyfet@gnu.org

USE_GMAKE=	yes
USE_LIBTOOL=	yes
USE_AUTOCONF=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include"

post-extract:
	@find ${WRKSRC} -name "Makefile.in" | \
		xargs ${REINPLACE_CMD} -e 's|-release \@LT_RELEASE\@||g'

.include <bsd.port.mk>
