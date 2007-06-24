# New ports collection makefile for:    audacious-audacious
# Date created:                         23 June 2007
# Whom:					buganini@gmail.com
#
# $FreeBSD$
#

PORTNAME=	audacious-mac
PORTVERSION=	0.2.0
CATEGORIES=	audio
MASTER_SITES=	http://www.netswarm.net/misc/

MAINTAINER=	buganini@gmail.com
COMMENT=	Audacious plugin that support the Monkey's Audio lossless formats

LIB_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious \
		mac.2:${PORTSDIR}/audio/mac

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -I${LOCALBASE}/include/"
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|CXXFLAGS = @CXXFLAGS@|CXXFLAGS = @CXXFLAGS@ -lmac|' ${WRKSRC}/src/Makefile.in
	${CP} ${PATCHDIR}/url2filename.cpp ${WRKSRC}/src/

.include <bsd.port.mk>
