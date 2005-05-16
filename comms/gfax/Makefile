# New ports collection makefile for:	gfax
# Date created:			20 January 2002
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	gfax
PORTVERSION=	0.7.3
CATEGORIES=	comms print gnome
MASTER_SITES=	http://gfax.cowlug.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	A GNOME-2.x C# pop-up fax manager

BUILD_DEPENDS=	${X11BASE}/lib/mono/gtk-sharp/gtk-sharp.dll:${PORTSDIR}/x11-toolkits/gtk-sharp \
		bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehier libgnomeprint
STRIP=

GCONF_SCHEMAS=gfax.schema

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/gfax.in \
		${WRKSRC}/gfaxlpr.in \
		${WRKSRC}/scripts/printer-setup.sh
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/scripts/printer-setup.sh

.include <bsd.port.mk>
