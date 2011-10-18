# New ports collection makefile for:	superswitcher
# Date Created:				02 Jan 2006
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	superswitcher
PORTVERSION=	0.6
CATEGORIES=	deskutils gnome
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alt-Tab replacement

LICENSE=	GPLv2

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_GNOME=	gconf2 libwnck
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/superswitcher \
		share/dbus-1/services/superswitcher.SuperSwitcher.service

post-patch:
	@${REINPLACE_CMD} -e \
		's/x11//g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/_DISABLE_DEPRECATED/d' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
