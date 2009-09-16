# New ports collection makefile for:	xmountains
# Date created:		16 November 1996
# Whom:			proff@iq.org
#
# $FreeBSD$
#

PORTNAME=	xmountains
PORTVERSION=	2.8
CATEGORIES=	graphics
MASTER_SITES=	http://www2.epcc.ed.ac.uk/~spb/xmountains/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 based fractal landscape generator

NO_WRKSUBDIR=	yes

USE_XORG=	xbitmaps x11
MAKEFILE=	Makefile.alt
ALL_TARGET=	${PORTNAME}
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		${PORTNAME}.6
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
