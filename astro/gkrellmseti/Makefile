# New ports collection makefile for:	gkrellmseti
# Date created:		Sat Oct 13 01:27:47 BRT 2001
# Whom:         Hammurabi Mendes <hmendes@brturbo.com> et al
#
# $FreeBSD$
#

PORTNAME=       seti
PORTVERSION=    0.7.0
CATEGORIES=     astro
MASTER_SITES=   http://xavier.serpaggi.free.fr/seti/
PKGNAMEPREFIX=	gkrellm
DISTNAME=	${PORTNAME}-${PORTVERSION}b

MAINTAINER=     hmendes@brturbo.com

BUILD_DEPENDS=  ${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	imlib
USE_XPM=	yes

DOC_FILES=	AUTHORS README TODO

post-patch:
	@${PERL} -pi -e "s|gtk-config|${GTK_CONFIG}|; s|imlib-config|${IMLIB_CONFIG}|; \
		s|DBGFLAGS= -O3||; s|gcc|${CC}|; s|(CFLAGS)=|\1+=|; \
		s|(LDFLAGS)=|\1+=|; s|/usr/X11R6|${PREFIX}|" \
		${WRKSRC}/Makefile
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/seti.c

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
