# New ports collection makefile for:	gkrellmss
# Date Created:			Sun Sep 30 18:24:19 BRT 2001
# Whom:		Hammurabi Mendes <hmendes_br@yahoo.com> et al
#
# $FreeBSD$
#

PORTNAME=	gkrellmss
PORTVERSION=	0.3
CATEGORIES=	audio
MASTER_SITES=	http://web.wt.net/~billw/gkrellmss/

MAINTAINER=	hmendes_br@yahoo.com

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
LIB_DEPENDS=	gdk_pixbuf_xlib.2:${PORTSDIR}/graphics/gdk-pixbuf
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_ESOUND=	yes
USE_GTK=	yes
USE_IMLIB=	yes
USE_XPM=	yes

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
