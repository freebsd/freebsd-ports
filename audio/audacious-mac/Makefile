# New ports collection makefile for:    audacious-mac
# Date created:                         23 June 2007
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	audacious-mac
PORTVERSION=	0.3.10
CATEGORIES=	audio
MASTER_SITES=	http://www.netswarm.net/misc/

MAINTAINER=	buganini@gmail.com
COMMENT=	Audacious plugin that support the Monkey's Audio lossless formats

LIB_DEPENDS=	audclient.1:${PORTSDIR}/multimedia/audacious \
		mac.2:${PORTSDIR}/audio/mac

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include/"

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS = @CXXFLAGS@|CXXFLAGS = @CXXFLAGS@ -lmac|' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
