# New ports collection makefile for: 	gphoto
# Date created:		26 May 1999
# Whom:			Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	gphoto
PORTVERSION=	0.4.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.gphoto.net/dist/
      
MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick

USE_IMLIB=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

MAN1=		gphoto.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gphoto
.for file in ChangeLog FAQ NEWS PROGRAMMERS README THANKS THEMES TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gphoto
.endfor
.endif

.include <bsd.port.mk>
