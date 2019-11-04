# Created by: trevor
# $FreeBSD$

PORTNAME=	xmixer
PORTVERSION=	0.9.4
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://mpx.freeshell.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio mixer (gtk and Xlib) for X11R6

WRKSRC=		${WRKDIR}/${PORTNAME}

GNU_CONFIGURE=	yes
ALL_TARGET=	xmixer

PLIST_FILES=	bin/xmixer \
		man/man1/xmixer.1.gz

USES=		xorg
USE_XORG=	x11 xt ice xaw xmu sm
LDFLAGS+=	-L${LOCALBASE}/lib -lX11

post-patch:
	@${GREP} -lR "rxvt -e" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|rxvt -e|xterm -e|g'
	@${REINPLACE_CMD} -e 's|-O -Wall||g ; \
		 s|^%\.o:.*$$|.c.o:|g ; \
		 s|gtk-config|pkg-config gtk+|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|<getopt\.h>|<unistd.h>|g' ${WRKSRC}/main.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xmixer ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xmixer.man ${STAGEDIR}${MAN1PREFIX}/man/man1/xmixer.1

.include <bsd.port.mk>
