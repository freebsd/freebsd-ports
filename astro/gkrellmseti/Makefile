# New ports collection makefile for:	gkrellmseti
# Date created:		Sat Oct 13 01:27:47 BRT 2001
# Whom:         Hammurabi Mendes <hmendes_br@yahoo.com> et al
#
# $FreeBSD$
#

PORTNAME=       seti
PORTVERSION=    0.6.5
CATEGORIES=     astro
MASTER_SITES=   http://xavier.serpaggi.free.fr/seti/
PKGNAMEPREFIX=	gkrellm

MAINTAINER=     hmendes_br@yahoo.com

BUILD_DEPENDS=  ${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

USE_BZIP2=      yes
USE_X_PREFIX=   yes
USE_GTK=        yes
USE_IMLIB=      yes
USE_XPM=	yes

DOC_FILES=	AUTHORS README TODO

post-patch:
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
