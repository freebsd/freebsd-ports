# New ports collection makefile for:	gkrellsun
# Date Created:				14.August 2002
# Whom:					Steffen Vogelreuter
#
# $FreeBSD$
#

PORTNAME=	gkrellsun
PORTVERSION=	0.2
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://nwalsh.com/hacks/gkrellsun/

MAINTAINER=	steffen@vogelreuter.de
COMMENT=	A Gkrellm-Plugin that displays the local sun rise and sun set times

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}
USE_X_PREFIX=	yes
USE_GNOME=	imlib

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkrellsun.so \
		${PREFIX}/libexec/gkrellm/plugins

.include <bsd.port.mk>
