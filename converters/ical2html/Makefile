# New ports collection makefile for: ical2html
# Date created:		Thu Apr 14 18:08:52 BST 2005
# Whom:			keiichi@iijlab.net
#
# $FreeBSD$
#

PORTNAME=	ical2html
PORTVERSION=	0.4
CATEGORIES=	converters
MASTER_SITES=	http://www.w3.org/Tools/Ical2html/

MAINTAINER=	keiichi@iijlab.net
COMMENT=	Manipulation commands for iCalendar files

LIB_DEPENDS=	ical.0:${PORTSDIR}/devel/libical

GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

USE_GETOPT_LONG=	yes

.include <bsd.port.mk>
