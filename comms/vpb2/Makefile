# New ports collection makefile for:	vpb2
# Date created:				07 Sept 2000
# Whom:					David Sugar <dyfet@gnu.org>
#
# $FreeBSD$
#

PORTNAME=	vpb2
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	ftp://www.voxilla.org/pub/vpb/

MAINTAINER=	dyfet@gnu.org
COMMENT=	User mode API for Voicetronix 4 port analog DSP telephony cards

USE_GMAKE=	yes
USE_INC_LIBTOOL_VER=	13
USE_AUTOCONF_VER=	213
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib \
		LDFLAGS=${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

post-extract:
	@${FIND} ${WRKSRC} -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -e 's|-release \$$\(LT_RELEASE\)||g'

post-patch:
	${REINPLACE_CMD} -e "s|PREFIX|${PREFIX}|" ${WRKSRC}/vpbreg.cpp

.include <bsd.port.post.mk>
