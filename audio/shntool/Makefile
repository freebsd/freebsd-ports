# New ports collection makefile for:   shntool
# Date created:        2 November 2000
# Whom:                Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	shntool
PORTVERSION=	2.0.3
CATEGORIES=	audio
MASTER_SITES=	http://www.etree.org/shnutils/shntool/source/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner

MAINTAINER=	fenner@FreeBSD.Org
COMMENT=	Multi-purpose .wav/.shn processing utility

RUN_DEPENDS=	shorten:${PORTSDIR}/audio/shorten

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

MAN1=		shntool.1

.include <bsd.port.mk>
