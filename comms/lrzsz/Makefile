# Created by: David O'Brien <obrien@cs.ucdavis.edu>
# $FreeBSD$

PORTNAME=	lrzsz
PORTVERSION=	0.12.20
PORTREVISION=	4
CATEGORIES=	comms
MASTER_SITES=	http://ohse.de/uwe/releases/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Receive/Send files via X/Y/ZMODEM protocol.  (unrestrictive)

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
ALL_TARGET=	all # vcheck

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_FILES+=	share/locale/de/LC_MESSAGES/lrzsz.mo
.else
CONFIGURE_ARGS+=	--disable-nls
.endif

.include <bsd.port.mk>
