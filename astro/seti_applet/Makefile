# New ports collection makefile for:	seti-applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti-applet
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An applet that displays current status of seti@home client

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2
RUN_DEPENDS=	${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomepanel gnomeprefix 
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=	15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	seti_applet.schemas

SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/seti_applet.schemas

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
