# Ports collection Makefile for:	gtm
# Date created:				05/28/1999
# Whom:					nectar@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	gtm
PORTVERSION=	0.4.12
CATEGORIES=	ftp gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	gtm \
		stable/sources/gtm
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org

BUILD_DEPENDS=	wget:${PORTSDIR}/ftp/wget
RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs oaf
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gtm.1 gtm_applet.1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>
