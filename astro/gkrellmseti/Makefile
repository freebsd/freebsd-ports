# New ports collection makefile for:	gkrellmseti
# Date created:		Sat Oct 13 01:27:47 BRT 2001
# Whom:         Hammurabi Mendes <hmendes@brturbo.com> et al
#
# $FreeBSD$
#

PORTNAME=	seti
PORTVERSION=	0.7.0
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://xavier.serpaggi.free.fr/seti/
PKGNAMEPREFIX=	gkrellm
DISTNAME=	${PORTNAME}-${PORTVERSION}b

MAINTAINER=	hmendes@brturbo.com
COMMENT=	A SETI@home plugin for GKrellM

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_BZIP2=	yes
USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	imlib
USE_XPM=	yes

DOC_FILES=	AUTHORS README TODO

post-patch:
	@${REINPLACE_CMD} -e "s|gtk-config|${GTK_CONFIG}|; s|imlib-config|${IMLIB_CONFIG}|; \
		s|DBGFLAGS= -O3||; s|gcc|${CC}|; s|CFLAGS=|CFLAGS+=|; \
		s|LDFLAGS=|LDFLAGS+=|; s|/usr/X11R6|${PREFIX}|" \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/seti.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/seti.so \
		${PREFIX}/libexec/gkrellm/plugins
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
