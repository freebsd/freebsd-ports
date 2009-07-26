# New ports collection makefile for:	audacious-dumb
# Date created:				27 May 2007
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	audacious-dumb
PORTVERSION=	0.57
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://www.netswarm.net/misc/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Audacious plugin that support the IT, XM, S3M or MOD formats

RUN_DEPENDS=	audacious2:${PORTSDIR}/multimedia/audacious
BUILD_DEPENDS=	audacious2:${PORTSDIR}/multimedia/audacious \
		${LOCALBASE}/lib/libdumb.a:${PORTSDIR}/audio/dumb

USE_GMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

.include <bsd.port.mk>
