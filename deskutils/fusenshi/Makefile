# New ports collection makefile for:	fusenshi
# Date created:				30 March 2004
# Whom:					Masanori OZAWA (ozawa@ongs.co.jp)
#
# $FreeBSD$
#

PORTNAME=	fusenshi
PORTVERSION=	0.7.5
CATEGORIES=	deskutils
MASTER_SITES=	http://www.ongs.co.jp/projects/fusenshi/
DISTNAME=	${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ozawa@ongs.co.jp
COMMENT=	A Post-it(R) like application with network support

LIB_DEPENDS=	gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gtksourceview-1.0:${PORTSDIR}/x11-toolkits/gtksourceview

USE_GCC=	3.4
USE_GNOME=	libxml2
USE_XLIB=	yes

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/fusenshi

.include <bsd.port.mk>
