# ex:ts=8
# Ports collection makefile for:	vorbisgain
# Date created:			Jan 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vorbisgain
PORTVERSION=	0.34
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://users.pandora.be/sjeng/ftp/vorbis/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Calculates the perceived sound level of an Ogg Vorbis file

LIB_DEPENDS=	vorbis.3:${PORTSDIR}/audio/libvorbis

USE_ZIP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		vorbisgain.1
PLIST_FILES=	bin/vorbisgain

pre-configure:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
