# New ports collection makefile for:	seti_applet
# Date Created:		1 Jul 2000
# Whom:			HIYAMA Takeshi <th@cis.ibaraki.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	seti_applet
PORTVERSION=	0.4.1
CATEGORIES=	astro gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:S/_/-/}

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

LIB_DEPENDS=	gtop.1:${PORTSDIR}/devel/libgtop \
		intl.1:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	${LOCALBASE}/sbin/setiathome:${PORTSDIR}/astro/setiathome

USE_X_PREFIX=	yes
USE_GNOME=	yes
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

post-patch: patch-configure patch-makefiles-in \
	    patch-seti_applet patch-message

patch-configure:
	@${PERL} -pi.fbsd -e 's|-lpthread|${PTHREAD_LIBS}|g; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

patch-makefiles-in:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${PERL} -pi.fbsd -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g;\
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

patch-seti_applet:
	@${PERL} -pi.fbsd -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/src/seti_applet.c

patch-message:
	@${SED} 's|%%LOCALBASE%%|${LOCALBASE}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Post-install
#

post-install: display-message

display-message:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
