# $FreeBSD$

PORTNAME=	wmauda
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.netswarm.net/misc/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	garga@FreeBSD.org
COMMENT=	A port of wmxmms to GTK 2.x and Audacious

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
RUN_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	mowgli:${PORTSDIR}/devel/libmowgli

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gtk20
CFLAGS+=	`pkg-config --cflags gtk+-2.0`
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

.include <bsd.port.mk>
