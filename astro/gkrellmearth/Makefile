# New ports collection makefile for:	gkrellm-earth
# Date Created:				Thu Jun 28 01:54:57 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
# With help from:	Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	earth
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	astro
MASTER_SITES=	http://www.geocities.com/saintdead/
PKGNAMEPREFIX=	gkrellm
DISTNAME=	${PORTNAME}_anim-${PORTVERSION}

MAINTAINER=	pat@FreeBSD.org
COMMENT=	A plugin for GKrellM that displays a rotating earth

BUILD_DEPENDS=	${X11BASE}/include/gkrellm/gkrellm.h:${PORTSDIR}/sysutils/gkrellm
RUN_DEPENDS=	gkrellm:${PORTSDIR}/sysutils/gkrellm

WRKSRC=		${WRKDIR}/${PORTNAME}_anim
USE_X_PREFIX=	yes
USE_GNOME=	imlib
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}" \
		PTHREAD_CFLAGS="${PTHREAD_CFLAGS}"
ALL_TARGET=	${PORTNAME}_anim.so

.include <bsd.port.mk>
