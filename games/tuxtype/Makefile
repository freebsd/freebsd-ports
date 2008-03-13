# New ports collection makefile for:	tuxtype
# Date created:				Mon Aug  6 21:53:03 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	tuxtype
PORTVERSION=	1.5.16
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://alioth.debian.org/frs/download.php/2209/
DISTNAME=	${PORTNAME}_w_fonts-${PORTVERSION}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	An educational typing tutor starring Tux the Linux Penguin

USE_GMAKE=	yes
USE_SDL=	image mixer sdl ttf pango
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-transform-name=""
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" LIBS="-pthread"

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/doc/$$(PACKAGE)|$$(docdir)|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/tuxtype/docs/en/Makefile.in

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 600000
BROKEN=		Does not build due to undefined reference to 'playsound' in 5.x
.endif

.include <bsd.port.post.mk>
