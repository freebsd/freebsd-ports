# New ports collection makefile for:	gkrellmss
# Date Created:				Tue Feb  4 13:24:50 PST 2003
# Whom:					Lars Eggert <larse@isi.edu>
#
# $FreeBSD$
#

PORTNAME=	gkrellmss
PORTVERSION=	2.3
CATEGORIES=	audio
MASTER_SITES=	http://web.wt.net/~billw/gkrellmss/

MAINTAINER=	lars.eggert@gmx.net
COMMENT=	A plugin for GKrellM with a VU meter showing left/right channel audio

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
LIB_DEPENDS=	gdk_pixbuf_xlib.2:${PORTSDIR}/graphics/gdk-pixbuf
LIB_DEPENDS=	fftw.2:${PORTSDIR}/math/fftw
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

LATEST_LINK=	gkrellmss2
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	esound imlib
USE_XPM=	yes

DOC_FILES=	Changelog README Themes

MAKE_ENV+=	PLUGIN_INSTALLDIR=${PREFIX}/libexec/gkrellm2/plugins \
		INSTALLDIR=${PREFIX}/libexec/gkrellm2/plugins \
		LOCALEDIR=${PREFIX}/share/locale \
		FFTW_LIB_DIR=-L${LOCALBASE}/lib \
		enable_nls=1

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
