# New ports collection makefile for:	fusenshi
# Date created:				30 March 2004
# Whom:					Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	fusenshi
PORTVERSION=	0.7.0
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.ongs.co.jp/projects/fusenshi/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	daichi@freebsd.org
COMMENT=	A Post-it(R) like application with network support

USE_XLIB=	yes
USE_GNOME=	libxml2
LIB_DEPENDS=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/fusenshi

.include <bsd.port.mk>
