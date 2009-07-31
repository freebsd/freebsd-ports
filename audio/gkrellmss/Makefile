# New ports collection makefile for:	gkrellmss
# Date Created:			Sun Sep 30 18:24:19 BRT 2001
# Whom:		Hammurabi Mendes <hmendes_br@yahoo.com> et al
#
# $FreeBSD$
#

PORTNAME=	gkrellmss
PORTVERSION=	0.5
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.bsd-geek.de/FreeBSD/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A plugin for GKrellM with a VU meter showing left/right channel audio

BUILD_DEPENDS=	${LOCALBASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
LIB_DEPENDS=	gdk_pixbuf_xlib.2:${PORTSDIR}/graphics/gdk-pixbuf
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

NO_LATEST_LINK=	yes

USE_GMAKE=	yes
USE_GNOME=	esound imlib
USE_XORG=	xpm

DOC_FILES=	Changelog README Themes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/src/gkrellmss.so \
		${PREFIX}/libexec/gkrellm/plugins
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
