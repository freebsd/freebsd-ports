# Created by: Martin Wilke (miwi@FreeBSD.org)
# $FreeBSD$

PORTNAME=	xfmpc
PORTVERSION=	0.2.2
PORTREVISION=	6
CATEGORIES=	audio xfce
MASTER_SITES=	XFCE/src/apps/${PORTNAME}/${PORTVERSION:R}
DIST_SUBDIR=	xfce4

MAINTAINER=	xfce@FreeBSD.org
COMMENT=	Graphical MPD client focusing on low footprint

LICENSE=	GPLv2

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libmpd.so:audio/libmpd

INSTALLS_ICONS=	yes
USES=		tar:bzip2 gettext gmake xfce pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 intltool intlhack
USE_XFCE=	libmenu

post-extract:
	${CP} ${FILESDIR}/config.vapi ${WRKSRC}/src

post-patch:
	${FIND} ${WRKSRC} -type f -name 'Makefile.in' | \
		${XARGS} ${REINPLACE_CMD} 's|@VALAC@|${LOCALBASE}/bin/valac|'

.include <bsd.port.mk>
