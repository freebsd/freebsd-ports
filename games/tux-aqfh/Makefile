# New ports collection makefile for:	tux-aqfh
# Date created:				10 Jun 2001
# Whom:					Alexander Langer <alex@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tux_aqfh
PORTVERSION=	1.0.14
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://tuxaqfh.sourceforge.net/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL adventure game

BUILD_DEPENDS=	${LOCALBASE}/lib/libplibsl.a:${PORTSDIR}/x11-toolkits/plib

USE_GL=		glut
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--with-plib=${LOCALBASE}

CPPFLAGS=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -lusbhid ${PTHREAD_LIBS}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800000
BROKEN=		does not compile: error: plib/js.h: No such file or directory
.endif

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
