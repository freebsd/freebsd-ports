# New ports collection makefile for:	4va
# Date created:		26 July 1998
# Whom:			Malte Lance <malte.lance@gmx.net>
#
# $FreeBSD$
#

PORTNAME=	4va
PORTVERSION=	1.21
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/hacks/X
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Four-Dimensional graphics tumbler for X11

USE_XLIB=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} -I${X11BASE}/include" \
		CLIBS="-lm -lX11 -L${X11BASE}/lib"

MAN1=		4va.1

4VA_DATA_FILES=		16cell.4vd 24cell.4vd 5cell.4vd 600cell.4vd ctor.4vd \
			ctor2.4vd hcube.4vd hsph.4vd sin.4vd tripris.4vd

post-extract:
	@${CHMOD} -R go-x ${WRKSRC}/

do-install:
.for file in 4va 4vdmake ctorus cutctorus
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
	${MKDIR} ${PREFIX}/share/4va
.for file in ${4VA_DATA_FILES}
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/4va
.endfor
	${INSTALL_MAN} ${WRKSRC}/4va.man ${PREFIX}/man/man1/4va.1

.include <bsd.port.mk>
