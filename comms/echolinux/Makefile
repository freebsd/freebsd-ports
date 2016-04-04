# Created by: db
# $FreeBSD$

PORTNAME=	echolinux
PORTVERSION=	0.17a
PORTREVISION=	7
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Echolink client for UNIX

LICENSE=	GPLv2

LIB_DEPENDS=	libforms.so:x11-toolkits/xforms \
		libgsm.so:audio/gsm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}|' -e 's|/usr/include/X11|$${LOCALBASE}/include|' \
		-e 's|-o echogui -L/usr/X11R6/lib|$${CFLAGS} -o echogui -L$${LOCALBASE}/lib|' \
		-e 's|CARGS|CFLAGS|' -e 's|= -DNodeFont=FL_TINY_SIZE|+= -DNodeFont=FL_TINY_SIZE|' \
		-e 's|/usr/local/bin/|${STAGEDIR}${PREFIX}/bin/|' \
		${WRKSRC}/echogui/Makefile
	@${REINPLACE_CMD} -e 's|<linux/soundcard.h>|<sys/soundcard.h>|' \
		${WRKSRC}/echogui/testgui_cb.c ${WRKSRC}/echogui/testgui_main.c \
		${WRKSRC}/echolinux/vox.c
	@${REINPLACE_CMD} -e 's|CC = gcc -O3|#CC = gcc -O3|' -e 's|^CFLAGS =|CFLAGS +=|' \
		${WRKSRC}/echolinux/Makefile
	@${REINPLACE_CMD} -e 's|LFLAGS = -lm|LFLAGS = -L${LOCALBASE}/lib -lm -lgsm|' \
		-e 's|libgsm.a||' -e 's|-Igsm/inc|-I${LOCALBASE}/include|' \
		-e 's|/usr/local/bin/|${STAGEDIR}${PREFIX}/bin/|' \
		${WRKSRC}/echolinux/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/Using_EchoLinux.txt ${STAGEDIR}${DOCSDIR}/Using_EchoLinux.txt
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/echolinux
	@${INSTALL_DATA} ${WRKSRC}/echolinux.desktop ${STAGEDIR}${PREFIX}/share/echolinux
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/echolinux/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/echolinux_48x48.png ${STAGEDIR}${PREFIX}/share/echolinux/pixmaps

.include <bsd.port.mk>
