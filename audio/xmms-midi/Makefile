# New ports collection makefile for:	xmms-midi
# Date created:		2002-10-14
# Whom:			Hendrik Scholz <hendrik@scholz.net>
#
# $FreeBSD$

PORTNAME=	xmms-midi
PORTVERSION=	0.03
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://dl.fkb.wormulon.net/xmms-midi/ \
		http://dl.kel.wormulon.net/xmms-midi/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS input plugin to play midi files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	timidity:${PORTSDIR}/audio/timidity

USE_GNOME=	gtk12
USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes

PLIST_FILES=	lib/xmms/Input/libmid.a \
		lib/xmms/Input/libmid.la \
		lib/xmms/Input/libmid.so

post-patch:
	${REINPLACE_CMD} -e "s,/xmms/Input,/lib/xmms/Input,; \
	s,_LDFLAGS =,_LDFLAGS = -module -export-dynamic -avoid-version," \
	${WRKSRC}/Makefile.in

.include <bsd.port.mk>
