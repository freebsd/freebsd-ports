# ex:ts=8
# Ports collection makefile for:	vorbisgain
# Date created:			Jan 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vorbisgain
PORTVERSION=	0.32
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.sourceforge.net/ftp/vorbis/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

USE_ZIP=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lm -logg -lvorbis -lvorbisfile"
USE_GMAKE=	yes

MAN1=	vorbisgain.1

post-patch:
	@${REINPLACE_CMD} -e "s,-ldir,," ${WRKSRC}/configure

.include <bsd.port.mk>
