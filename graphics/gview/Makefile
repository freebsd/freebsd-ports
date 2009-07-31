# New ports collection makefile for:	gview
# Date created:				30 April 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gview
PORTVERSION=	0.1.15
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://homepages.petech.ac.za/~bruces/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Image viewer for X Window System with interface similar to ACDSee

USE_GNOME=	gnomehack imlib
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS BUGS ChangeLog NEWS README TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
