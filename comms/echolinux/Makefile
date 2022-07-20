PORTNAME=	echolinux
PORTVERSION=	0.17a
PORTREVISION=	8
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Amateur Radio Echolink client for UNIX

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/gpl.txt

LIB_DEPENDS=	libforms.so:x11-toolkits/xforms \
		libgsm.so:audio/gsm

USES=		tar:tgz xorg
USE_XORG=	x11 xpm

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}|' -e 's|/usr/include/X11|$${LOCALBASE}/include|' \
		-e 's|-o echogui -L/usr/X11R6/lib|$${CFLAGS} -o echogui -L$${LOCALBASE}/lib|' \
		-e 's|CARGS|CFLAGS|' -e 's|= -DNodeFont=FL_TINY_SIZE|+= -DNodeFont=FL_TINY_SIZE|' \
		-e 's|/usr/local/bin/|${STAGEDIR}${PREFIX}/bin/|' \
		${WRKSRC}/echogui/Makefile
	@${REINPLACE_CMD} -e 's|CC = gcc -O3|#CC = gcc -O3|' -e 's|^CFLAGS =|CFLAGS +=|' \
		${WRKSRC}/echolinux/Makefile
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' \
		${WRKSRC}/echolinux/vox.c ${WRKSRC}/echolinux/control.c
	@${REINPLACE_CMD} -e 's|LFLAGS = -lm|LFLAGS = -L${LOCALBASE}/lib -lm -lgsm|' \
		-e 's|libgsm.a||' -e 's|-Igsm/inc|-I${LOCALBASE}/include|' \
		-e 's|/usr/local/bin/|${STAGEDIR}${PREFIX}/bin/|' \
		${WRKSRC}/echolinux/Makefile

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/echolinux
	${INSTALL_DATA} ${WRKSRC}/echolinux.desktop ${STAGEDIR}${PREFIX}/share/echolinux
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/echolinux/pixmaps
	${INSTALL_DATA} ${WRKSRC}/pixmaps/echolinux_48x48.png ${STAGEDIR}${PREFIX}/share/echolinux/pixmaps
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/echogui
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/echolinux
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/echoaudio

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/Using_EchoLinux.txt ${STAGEDIR}${DOCSDIR}/Using_EchoLinux.txt

.include <bsd.port.mk>
