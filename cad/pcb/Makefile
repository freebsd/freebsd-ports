# New ports collection makefile for:	PCB
# Date created:		19 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	pcb
PORTVERSION=	20091103
CATEGORIES=	cad
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	X11 interactive printed circuit board layout system

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd
RUN_DEPENDS=	m4>=1.4.11:${PORTSDIR}/devel/m4
BUILD_DEPENDS=	${RUN_DEPENDS}

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_TK_RUN=	83
INSTALLS_ICONS=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib" \
		INSTALL_DATA="/usr/bin/install ${COPY} ${_SHROWNGRP} -m ${SHAREMODE}"
CONFIGURE_ARGS=	--docdir=${DOCSDIR} --disable-nls
PORTDOCS= pcb.html pcb.ps refcard.ps pcb.pdf refcard.pdf pad.gif	\
	puller.gif thermal.gif pad.png puller.png thermal.png

.if defined(WITHOUT_X11)
CONFIGURE_ARGS+=	--without-gui
CONFIGURE_ENV+=		WISH=${TRUE}
.elif defined(WITH_MOTIF_GUI)
USE_MOTIF=	yes
USE_TK_RUN=	yes
CONFIGURE_ARGS+=	--with-gui=lesstif
CONFIGURE_ENV+=		WISH=${WISH}
.else
USE_GNOME=	gtk20 desktopfileutils
USE_TK_RUN=	yes
CONFIGURE_ARGS+=	--with-gui=gtk
CONFIGURE_ENV+=		WISH=${WISH}
.endif

.if !defined(NOPORTDOCS)
INFO=		pcb
MAN1=		pcb.1
.else
CONFIGURE_ARGS+=	--disable-doc
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
