# New ports collection makefile for:	gcal
# Date created:				12 October 2000
# Whom:					Cyrille Lefevre <clefevre@citeweb.net>
#
# $FreeBSD$
#

PORTNAME=		gcal
PORTVERSION=		3.01
CATEGORIES=		deskutils
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	gcal

MAINTAINER=	ports@freebsd.org

LIB_DEPENDS=	intl.1:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes

MAN1=		gcal.1 gcal2txt.1 tcal.1 txt2gcal.1

post-install:
	install-info ${PREFIX}/info/gcal.info ${PREFIX}/info/dir

.include <bsd.port.mk>
