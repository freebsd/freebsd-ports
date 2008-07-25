# New ports collection makefile for:	gfax
# Date created:			20 January 2002
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#   $Id: Makefile,v 1.16 2007/01/30 00:19:26 tmclau02 Exp $
#

PORTNAME=	gfax
PORTVERSION=	0.7.6
PORTREVISION=	7
CATEGORIES=	comms print gnome
MASTER_SITES=	http://gfax.cowlug.org/

MAINTAINER=	bsd-sharp@googlegroups.com
COMMENT=	A Mono based pop-up fax manager

BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp
RUN_DEPENDS=	${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax \
		bash:${PORTSDIR}/shells/bash \
		${LOCALBASE}/libdata/pkgconfig/evolution-sharp.pc:${PORTSDIR}/mail/evolution-sharp

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gnomeprefix gnomehier libgnomeprint gnomesharp20
STRIP=

GCONF_SCHEMAS=	gfax.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/gfax.in \
		${WRKSRC}/gfaxlpr.in \
		${WRKSRC}/scripts/printer-setup.sh
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/scripts/printer-setup.sh

.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"
.include <bsd.port.mk>
