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
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/v/vorbisgain
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calculates a percieved sound level of an Ogg Vorbis file

LIB_DEPENDS=	ogg.4:${PORTSDIR}/audio/libogg \
		vorbis.2:${PORTSDIR}/audio/libvorbis

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lm -logg -lvorbis -lvorbisfile"

MAN1=	vorbisgain.1

post-patch:
	@${REINPLACE_CMD} -e "s,-ldir,," ${WRKSRC}/configure

.include <bsd.port.mk>
