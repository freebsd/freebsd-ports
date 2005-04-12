# New ports collection makefile for:	stellarium
# Date created:			26 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		stellarium
PORTVERSION=		0.6.2
CATEGORIES=		astro
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A 3D photo-realistic sky renderer

USE_GCC=		3.4
USE_GL=			yes
USE_SDL=		sdl
USE_X_PREFIX=		yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
CONFIGURE_ENV=		CPPFLAGS="-I${X11BASE}/include" \
			LDFLAGS="-L${X11BASE}/lib"

MAN1=			stellarium.1

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} \
		${WRKSRC}/AUTHORS \
		${WRKSRC}/ChangeLog \
		${WRKSRC}/NEWS \
		${WRKSRC}/README \
		${WRKSRC}/TODO \
		${DOCSDIR}
.endif

.include <bsd.port.mk>
