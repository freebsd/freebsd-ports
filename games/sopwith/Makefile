# New ports collection makefile for:	sopwith
# Date created:			1 July 2002
# Whom:				Edwin Groothuis <edwin@mavetju.org>
#
# $FreeBSD$
#

PORTNAME=	sopwith
PORTVERSION=	1.4.0
CATEGORIES=	games
MASTER_SITES=	http://fraggle.despayre.org:81/stuffage/sopwith/
DISTNAME=	sdl_${PORTNAME}-${PORTVERSION}

MAINTAINER=	edwin@mavetju.org

BUILD_DEPENDS=	${LOCALBASE}/bin/sdl11-config:${PORTSDIR}/devel/sdl12

USE_GTK=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${PREFIX}/bin/sdl11-config
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/^extern void getmode.*//' \
		${WRKSRC}/src/swtitle.h

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for F in FAQ doc/license.txt doc/keys.txt doc/origdoc.txt
	${INSTALL_DATA} ${WRKSRC}/${F} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
