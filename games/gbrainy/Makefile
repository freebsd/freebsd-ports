# New ports collection makefile for:	gbrainy
# Date created:		29 April 2010
# Whom:			Kevin Lo <kevlo@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gbrainy
PORTVERSION=	1.41
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://gent.softcatala.org/jmas/gbrainy/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	A brain teaser game and trainer

BUILD_DEPENDS=	mautil:${PORTSDIR}/devel/mono-addins \
		${LOCALBASE}/bin/bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	desktopfileutils gnometarget gnomehack gtksharp20 gnomesharp20
USE_GMAKE=	yes
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
                LDFLAGS="-L${LOCALBASE}/lib"

MAN6=		gbrainy.6
INSTALLS_ICONS=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/src/Clients/Classical/gbrainy.in

post-install:
	@-update-desktop-database

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.post.mk>
