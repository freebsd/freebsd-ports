# New ports collection makefile for:	glunarclock
# Date created:		9 December 2003
# Whom:			Vincent Tantardini <vinc@freebsd-fr.org>
#
# $FreeBSD$
#

PORTNAME=	glunarclock
PORTVERSION=	0.32.2
PORTREVISION=	2
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNOME applet that displays the current phase of the Moon

LIB_DEPENDS=	xklavier.10:${PORTSDIR}/x11/libxklavier

USE_X_PREFIX=	yes
USE_GNOME=	gail gnomehack gnomepanel gnomeprefix gnometarget intlhack
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes

PLIST_SUB=	VERSION="${PORTVERSION:R}"

GCONF_SCHEMAS=	glunarclock.schemas

post-patch:
	@${REINPLACE_CMD} -e \
		's|$${prefix}/share|$${datadir}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
