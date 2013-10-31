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

LICENSE=	GPLv2

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
RUN_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	libmowgli.so:${PORTSDIR}/devel/libmowgli

USES=		gmake pkgconfig
USE_GNOME=	gnomeprefix gtk20

PLIST_FILES=	bin/wmauda \
		man/man1/wmauda.1.gz \
		share/pixmaps/wmauda.xpm

post-patch:
	@${REINPLACE_CMD} -e "/^MANPAGE_DIR.*:=/s,:=.*,:= ${MAN1PREFIX}/man/man1," \
			  -e 's,audacious,& audclient dbus-glib-1,' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
