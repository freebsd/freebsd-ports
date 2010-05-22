# New ports collection makefile for: ical2html
# Date created:		Thu Apr 14 18:08:52 BST 2005
# Whom:			keiichi@iijlab.net
#
# $FreeBSD$
#

PORTNAME=	ical2html
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	converters
MASTER_SITES=	http://www.w3.org/Tools/Ical2html/

MAINTAINER=	keiichi@iijlab.net
COMMENT=	Manipulation commands for iCalendar files

LIB_DEPENDS=	ical.44:${PORTSDIR}/devel/libical

GNU_CONFIGURE=	yes

CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include/libical -I${LOCALBASE}/include" \
		LDFLAGS=-L${LOCALBASE}/lib

.include <bsd.port.mk>
