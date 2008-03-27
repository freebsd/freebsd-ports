# New ports collection makefile for:	audacious-dumb
# Date created:				27 May 2007
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	audacious-dumb
PORTVERSION=	0.57
CATEGORIES=	audio
MASTER_SITES=	http://www.netswarm.net/misc/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Audacious plugin that support the IT, XM, S3M or MOD formats

RUN_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious \
		dumbout:${PORTSDIR}/devel/dumb

USE_GMAKE=	yes
USE_LDCONFIG=	yes

MAKE_ENV+=	CC="${CC}" LOCALBASE="${LOCALBASE}"

ONLY_FOR_ARCHS=	i386

.include <bsd.port.mk>
