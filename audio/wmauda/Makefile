# New ports collection makefile for:	wmauda
# Date created:		2007-10-30
# Whom:			Renato Botelho <garga@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wmauda
PORTVERSION=	0.7
PORTREVISION=	9
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.netswarm.net/misc/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A port of wmxmms to GTK 2.x and Audacious

BUILD_DEPENDS=	audacious2:${PORTSDIR}/multimedia/audacious
RUN_DEPENDS=	audacious2:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	mowgli.2:${PORTSDIR}/devel/libmowgli

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes
USE_GNOME=	gnomeprefix gtk20
CFLAGS=		`pkg-config --cflags gtk+-2.0`
MAKE_ENV=	MANPAGE_DIR=${MAN1PREFIX}/man/man1 \
		LIBS="`pkg-config --libs gtk+-2.0`"

PLIST_FILES=	bin/wmauda \
		share/pixmaps/wmauda.xpm
MAN1=	wmauda.1

post-patch:
	@${REINPLACE_CMD} -E 's,^(MANPAGE_DIR.*):=,\1\?=,; \
			      s,^(LIBS.*):=,\1\+=,; \
			      s,audacious,& audclient,' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/share/pixmaps,${PREFIX}/share/pixmaps,g' \
		${WRKSRC}/config.h

.include <bsd.port.mk>
