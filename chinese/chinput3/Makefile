# Ports collection makefile for:  chinput3
# Date created:                          03/31/2002
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#    $MCom: ports/chinese/chinput3/Makefile,v 1.1 2006/10/04 13:15:20 ahze Exp $

PORTNAME=	chinput
PORTVERSION=	3.0.2.5
PORTREVISION=	11
CATEGORIES=	chinese x11
MASTER_SITES=	http://ftp.jaist.ac.jp/pub/FreeBSD/distfiles/ \
		http://www.gtlib.gatech.edu/pub/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Chinese GB2312,BIG5 code input server

BROKEN=		does not build

LATEST_LINK=	zh-chinput3
USE_XORG=	x11 xt
USE_GETTEXT=	yes
USE_GNOME=	gtk12 imlib
USE_LDCONFIG=	${PREFIX}/lib/Chinput/im/

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		Does not compile on !i386
.endif

post-patch:
	@${REINPLACE_CMD} -e '/extern int ForwardEvent();/d' \
		${WRKSRC}/src/Chinput-*/src/*.c
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} ${REINPLACE_CMD} -e 's,/usr/local,${PREFIX},g'
	@${REINPLACE_CMD} -e 's|XLIB)|XLIB) -L${LOCALBASE}/lib -lintl|' \
		${WRKSRC}/src/ZWinControl/Makefile

pre-build:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e 's|-lc_r|${PTHREAD_CFLAGS} ${PTHREAD_LIBS}|; \
		    s|-I/usr/include|-I${LOCALBASE}/include|; \
		    s|-L/usr/lib|-L${LOCALBASE}/lib|; \
		    s|-L/usr/X11R6|-L${LOCALBASE}/lib -L/usr/X11R6|; \
		    s|/usr/X11R6|${LOCALBASE}|'

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
