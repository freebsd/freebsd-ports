# New ports collection makefile for:	toycars
# Date created:		15 Dec 2005
# Whom:			Dmitry Marakasov <amdmi3@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	toycars
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	toycars

MAINTAINER=	amdmi3@mail.ru
COMMENT=	Physics-based 2D racing game

USE_SDL=	mixer image sdl
USE_GL=		yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

USE_AUTOTOOLS=	aclocal:19 autoheader:259 automake:19 autoconf:259
ACLOCAL_ARGS=	-I m4
AUTOMAKE_ARGS=	-a -c

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

PORTDOCS=	README

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
