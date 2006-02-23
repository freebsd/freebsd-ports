# New ports collection makefile for:	gfax
# Date created:			20 January 2002
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#   $Id: Makefile,v 1.12 2005/11/10 01:21:02 tmclau02 Exp $
#

PORTNAME=	gfax
PORTVERSION=	0.7.3
PORTREVISION=	4
CATEGORIES=	comms print gnome
MASTER_SITES=	http://gfax.cowlug.org/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	bsd-sharp-list@forge.novell.com
COMMENT=	A Mono based pop-up fax manager

BUILD_DEPENDS=	${X11BASE}/lib/mono/gtk-sharp/gtk-sharp.dll:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		bash:${PORTSDIR}/shells/bash
RUN_DEPENDS=	${X11BASE}/lib/mono/gtk-sharp/gtk-sharp.dll:${PORTSDIR}/x11-toolkits/gtk-sharp10 \
		${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax \
		bash:${PORTSDIR}/shells/bash

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehier libgnomeprint
STRIP=

GCONF_SCHEMAS=gfax.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/gfax.in \
		${WRKSRC}/gfaxlpr.in \
		${WRKSRC}/scripts/printer-setup.sh
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/scripts/printer-setup.sh

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
