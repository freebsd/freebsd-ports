# New ports collection makefile for:	fishsupper
# Date created:		25 Mar 2006
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	fishsupper
PORTVERSION=	0.1.6
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Guide a cat across a series of rivers, jumping from log to log

BUILD_DEPENDS=	${LOCALBASE}/include/boost/bind.hpp:${PORTSDIR}/devel/boost-libs

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl image mixer
USE_GL=		gl
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PORTDOCS=	README

DESKTOP_ENTRIES="Fish Supper" \
		"Guide a cat across a series of rivers, jumping from log to log" \
		"${DATADIR}/images/fs_image_30.png" \
		"fishsupper" \
		"Game;ArcadeGame;" \
		false

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
