# New ports collection makefile for:	seti-applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti-applet
PORTVERSION=	2.1.3
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An applet that displays current status of seti@home client

LIB_DEPENDS=	gtop-2.0:${PORTSDIR}/devel/libgtop2
RUN_DEPENDS=	${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomepanel
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

# Local variables
#

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

REINPLACE_SUB=	LOCALBASE=${LOCALBASE}
PKGMESSAGE_SUB=	LOCALBASE=${LOCALBASE}

# Post-patch
#

post-patch: patch-seti_applet patch-pkgmessage

patch-seti_applet:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/src/seti_applet.schemas

patch-pkgmessage:
	@${SED} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${MSG_FILE} > ${PKGMESSAGE}

# Post-install
#

post-install: display-message

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
