# New ports collection makefile for:	gkrellmoon2
# Date Created:				Wed Aug 25 13:18:39 CEST 2004
# Whom:					Jan Srzednicki <w@wrzask.pl>
#
# $FreeBSD$
#

PORTNAME=	gkrellmoon2
PORTVERSION=	0.6
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gkrellmoon
DISTNAME=	gkrellmoon-${PORTVERSION}

MAINTAINER=	w@wrzask.pl
COMMENT=	A moon clock plugin for Gkrellm2

BUILD_DEPENDS=	${X11BASE}/include/gkrellm2/gkrellm.h:${PORTSDIR}/sysutils/gkrellm2
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm2

USE_X_PREFIX=	yes
USE_GNOME=	gtk20

ALL_TARGET=	gkrellmoon.so

do-install:
	${INSTALL_DATA} ${WRKSRC}/gkrellmoon.so \
		${PREFIX}/libexec/gkrellm2/plugins
.ifndef(NOPORTDOCS)
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE} \
		${PREFIX}/share/doc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/${PORTNAME}
.endif #NOPORTDOCS

.include <bsd.port.mk>
