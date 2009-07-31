# New ports collection makefile for:	tuxtype
# Date created:				Mon Aug  6 21:53:03 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	tuxtype
PORTVERSION=	1.5.17
PORTREVISION=	2
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
WRKSRC=		${WRKDIR}/${DISTNAME:S/.17/.16/}

post-patch:
	@${REINPLACE_CMD} -e 's|$$(prefix)/doc/$$(PACKAGE)|$$(docdir)|' \
		${WRKSRC}/Makefile.in ${WRKSRC}/tuxtype/docs/en/Makefile.in

.include <bsd.port.mk>
