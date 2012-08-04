# New ports collection makefile for:	tux-aqfh
# Date created:				10 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tux_aqfh
PORTVERSION=	1.0.14
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/tuxaqfh/tuxaqfh/${PORTVERSION}-classic

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL adventure game

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_GL=		glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib -lusbhid ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lplibsl -lplibssg|-lplibsl -lplibjs -lplibssg|g ; \
		 s|-O6||g ; \
		 s|-lpthread||g ; \
		 s|datadir/games|datadir|g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(prefix)/games|@bindir@|g ; \
		 s|$$(datadir)/games|$$(datadir)|g'

.include <bsd.port.post.mk>
