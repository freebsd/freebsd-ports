# ex:ts=8
# Ports collection makefile for:	gl-117
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gl-117
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	erik@smluc.org
COMMENT=	An OpenGL & SDL action flight simulator

WRKSRC=		${WRKDIR}/${DISTNAME}-src
USE_SDL=	mixer sdl
USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-include=${X11BASE}/include \
		--x-libraries=${X11BASE}/lib \
		--with-opengl-dir=${X11BASE}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
