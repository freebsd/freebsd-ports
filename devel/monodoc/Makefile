# New ports collection makefile for:    MonoDoc
# Date created:         2004-08-13
# Friday the 13th!
# Whom:                 Christopher Nehren
#
# $FreeBSD$
#

PORTNAME=		monodoc
PORTVERSION=		1.0
CATEGORIES=		devel gnome
MASTER_SITES=		http://mono.ximian.com/archive/${PORTVERSION}/

MAINTAINER=		apeiron@comcast.net
COMMENT=		Documentation browser for Mono and Mono libraries

BUILD_DEPENDS=		${LOCALBASE}/bin/mono:${PORTSDIR}/lang/mono \
			${LOCALBASE}/libdata/pkgconfig/gtk-sharp.pc:${PORTSDIR}/x11-toolkits/gtk-sharp \
			${LOCALBASE}/bin/lynx:${PORTSDIR}/www/lynx
RUN_DEPENDS=		${BUILD_DEPENDS}

GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
USE_GNOME=		gnomehack gnometarget
USE_GMAKE=		yes

# Fix 'exec mono' not picking up libmap.conf settings.
post-patch:
	@${REINPLACE_CMD} -e 's|mono |${LOCALBASE}/bin/mono |g' \
		${WRKSRC}/monodoc.in

.include <bsd.port.mk>
