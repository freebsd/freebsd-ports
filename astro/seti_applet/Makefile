# New ports collection makefile for:	seti_applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti_applet
PORTVERSION=	0.4.1
PORTREVISION=	1
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop
RUN_DEPENDS=	${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack libpanel gnomecanvas
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

# Local variables
#

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

FIND?=		find
XARGS?=		xargs

# Post-patch
#

post-patch: patch-configure patch-seti_applet \
	patch-pkgmessage

patch-configure:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g;\
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

patch-seti_applet:
	@${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/seti_applet.c

patch-pkgmessage:
	@${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Post-install
#

post-install: display-message

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
