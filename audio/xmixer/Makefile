# Created by: trevor
# $FreeBSD$

PORTNAME=	xmixer
PORTVERSION=	0.9.4
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://mpx.freeshell.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio mixer (gtk and Xlib) for X11R6

WRKSRC=		${WRKDIR}/${PORTNAME}

WANT_GNOME=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	${PROGRAMS}

PLIST_FILES=	bin/xmixer \
		man/man1/xmixer.1.gz

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk12}!=""
USE_GNOME+=	gtk12
PROGRAMS=	xmixer xgmixer
MLINKS+=	xmixer.1 xgmixer.1
PLIST_FILES+=	bin/xgmixer
.else
USE_XORG=	x11 xt ice xaw
PROGRAMS=	xmixer
LDFLAGS+=	-L${LOCALBASE}/lib -lX11
.endif

post-patch:
	@${GREP} -lR "rxvt -e" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|rxvt -e|xterm -e|g'
	@${REINPLACE_CMD} -e 's|-O -Wall||g ; \
		 s|^%\.o:.*$$|.c.o:|g ; \
		 s|gtk-config|pkg-config gtk+|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|<getopt\.h>|<unistd.h>|g' ${WRKSRC}/main.c

do-install:
.for file in ${PROGRAMS}
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin/${file}
.endfor
	${INSTALL_MAN} ${WRKSRC}/xmixer.man ${STAGEDIR}${MAN1PREFIX}/man/man1/xmixer.1

.include <bsd.port.post.mk>
