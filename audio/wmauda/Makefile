# $FreeBSD$

PORTNAME=	wmauda
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://www.netswarm.net/misc/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Port of wmxmms to GTK 2.x and Audacious

LICENSE=	GPLv2

BUILD_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
RUN_DEPENDS=	audacious:${PORTSDIR}/multimedia/audacious
LIB_DEPENDS=	libmowgli.so:${PORTSDIR}/devel/libmowgli

BROKEN=		Does not work with audacious 3.5 or later
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-01-26

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
