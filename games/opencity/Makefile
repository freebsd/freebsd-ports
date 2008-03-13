# New ports collection makefile for:	opencity
# Date created:		07 Jan 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	opencity
PORTVERSION=	0.0.5.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}stable

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Free 3D city simulator

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_SDL=	sdl mixer image net
USE_GL=		yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

WRKSRC=		${WRKDIR}/${PORTNAME}-0.0.5stable

PORTDOCS=	*

MAN6=		opencity.6

post-patch:
	@${REINPLACE_CMD} -e 's|\(defined(__WIN32__) && \)\(!defined(log2)\)|\2|' \
		${WRKSRC}/src/mapgen/mapmaker.cpp
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's|docs||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
