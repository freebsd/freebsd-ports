# ports collection makefile for:	echolinux
# Date created:		25 June 2004
# Whom:			db
#
# $FreeBSD$
#

PORTNAME=	echolinux
PORTVERSION=	0.17a
PORTREVISION=	2
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/cqinet/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	db@FreeBSD.org
COMMENT=	Amateur Radio Echolink client for UNIX

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms \
		gsm.1:${PORTSDIR}/audio/gsm

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|$${CC}|' -e 's|/usr/include/X11|$${LOCALBASE}/include|' \
		-e 's|-o echogui -L/usr/X11R6/lib -lX11 -lXpm -lforms -lm -lpthread|$${CFLAGS} -o echogui -L$${LOCALBASE}/lib -lX11 -lXpm -lforms -lm ${PTHREAD_LIBS}|' \
		-e 's|CARGS|CFLAGS|' -e 's|= -DNodeFont=FL_TINY_SIZE|+= ${PTHREAD_CFLAGS} -DNodeFont=FL_TINY_SIZE|' \
		-e 's|/usr/local/bin/|$${PREFIX}/bin/|' \
		${WRKSRC}/echogui/Makefile
	@${REINPLACE_CMD} -e 's|<linux/soundcard.h>|<sys/soundcard.h>|' \
		${WRKSRC}/echogui/testgui_cb.c ${WRKSRC}/echogui/testgui_main.c \
		${WRKSRC}/echolinux/vox.c
	@${REINPLACE_CMD} -e 's|CC = gcc -O3|#CC = gcc -O3|' -e 's|^CFLAGS =|CFLAGS +=|' \
		${WRKSRC}/echolinux/Makefile
	@${REINPLACE_CMD} -e 's|LFLAGS = -lm|LFLAGS = -L${LOCALBASE}/lib -lm -lgsm|' \
		-e 's|libgsm.a||' -e 's|-Igsm/inc|-I${LOCALBASE}/include|' \
		-e 's|/usr/local/bin/|$${PREFIX}/bin/|' \
		${WRKSRC}/echolinux/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/Using_EchoLinux.txt ${DOCSDIR}/Using_EchoLinux.txt
	@${ECHO} ""
	@${ECHO} "echolinux docs installed in ${DOCSDIR}"
	@${ECHO} ""
.endif
	@${MKDIR} ${PREFIX}/share/echolinux
	@${INSTALL_DATA} ${WRKSRC}/echolinux.desktop ${PREFIX}/share/echolinux
	@${MKDIR} ${PREFIX}/share/echolinux/pixmaps
	@${INSTALL_DATA} ${WRKSRC}/pixmaps/echolinux_48x48.png ${PREFIX}/share/echolinux/pixmaps
	@${ECHO} ""
	@${ECHO} "echolinux desktop examples installed in ${PREFIX}/share/echolinux"
	@${ECHO} ""

.include <bsd.port.mk>
