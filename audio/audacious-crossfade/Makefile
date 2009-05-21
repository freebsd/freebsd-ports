# New ports collection makefile for:	audacious-crossfade
# Date created:		16 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

APP=		audacious
LIB_DEPENDS=	audclient.2:${PORTSDIR}/multimedia/audacious
BUILD_DEPENDS=	${LOCALBASE}/lib/audacious/General/alarm.so:${PORTSDIR}/multimedia/audacious-plugins
CPPFLAGS+=	-I${LOCALBASE}/include/glib-2.0 -I${LOCALBASE}/include/gtk-2.0 \
		-I${LOCALBASE}/include/cairo -I${LOCALBASE}/include/pango-1.0 \
		-I${LOCALBASE}/include/atk-1.0
MASTERDIR=	${.CURDIR}/../xmms-crossfade

.include "${MASTERDIR}/Makefile"
