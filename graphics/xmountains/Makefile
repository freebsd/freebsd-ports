# New ports collection makefile for:	xmountains
# Date created:		16 November 1996
# Whom:			proff@iq.org
#
# $FreeBSD$
#

PORTNAME=	xmountains
PORTVERSION=	2.9
CATEGORIES=	graphics
MASTER_SITES=	http://www2.epcc.ed.ac.uk/~spb/xmountains/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11 based fractal landscape generator

NO_WRKSUBDIR=	yes

USE_XORG=	xbitmaps x11

MAN6=		${PORTNAME}.6
PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${LN} -sf ${PORTNAME}.man ${WRKSRC}/${PORTNAME}.6

do-build:
	cd ${BUILD_WRKSRC} && ${CC} ${CFLAGS} -I${LOCALBASE}/include *.c \
		-o ${PORTNAME} -L${LOCALBASE}/lib -lX11 -lm

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.mk>
