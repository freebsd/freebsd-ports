# New ports collection makefile for:	gfax
# Date created:			20 January 2002
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	gfax
PORTVERSION=	0.6.4
PORTREVISION=	2
CATEGORIES=	comms print gnome
MASTER_SITES=	http://gfax.cowlug.org/

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	A GNOME-2.x C# pop-up fax manager

BUILD_DEPENDS=	${LOCALBASE}/lib/mono/gtk-sharp/gtk-sharp.dll:${PORTSDIR}/x11-toolkits/gtk-sharp \
		bash:${PORTSDIR}/shells/bash2
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehier libgnomeprint

.include <bsd.port.pre.mk>

MAKE_ENV+=	SETENV="/usr/bin/env" \
		MKDIR="/bin/mkdir -p" \
		CHMOD="/bin/chmod" \
		RM="/bin/rm" \
		SH="${LOCALBASE}/bin/bash"

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash|' \
		${WRKSRC}/gfax \
		${WRKSRC}/gfaxlpr \
		${WRKSRC}/scripts/printer-setup.sh
	@${REINPLACE_CMD} -e 's|/usr/bin|${PREFIX}/bin|g' \
		${WRKSRC}/gfax ${WRKSRC}/gfaxlpr
	@${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' \
		${WRKSRC}/scripts/printer-setup.sh

do-build:
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} all

do-install:
	${SETENV} ${MAKE_ENV} ${GMAKE} -C ${WRKSRC} install

.include <bsd.port.post.mk>
