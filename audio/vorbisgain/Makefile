# ex:ts=8
# Ports collection makefile for:	vorbisgain
# Date created:			Jan 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	vorbisgain
PORTVERSION=	0.37
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://sjeng.org/ftp/vorbis/

MAINTAINER=	gamato@users.sf.net
COMMENT=	Calculates the perceived sound level of an Ogg Vorbis file

LIB_DEPENDS=	vorbis.4:${PORTSDIR}/audio/libvorbis

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		vorbisgain.1
PLIST_FILES=	bin/vorbisgain

.if defined(WITH_RECURSIVE)
CONFIGURE_ARGS=	--enable-recursive
.endif

pre-configure:
	@${CHMOD} +x ${WRKSRC}/configure

.include <bsd.port.mk>
