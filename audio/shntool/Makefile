# New ports collection makefile for:   shntool
# Date created:        2 November 2000
# Whom:                Bill Fenner <fenner@FreeBSD.Org>
#
# $FreeBSD$
#

PORTNAME=	shntool
PORTVERSION=	1.2.0
CATEGORIES=	audio
MASTER_SITES=	http://shnutils.freeshell.org/shntool/source/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	fenner
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	fenner@FreeBSD.Org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

RUN_DEPENDS=	shorten:${PORTSDIR}/audio/shorten

MAN1=		shntool.1

.include <bsd.port.mk>
