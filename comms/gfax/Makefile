# New ports collection makefile for:	gfax
# Date created:			20 January 2002
# Whom:				John Merryweather Cooper <jmcoopr@webmail.bmi.net>
#
# $FreeBSD$
#

PORTNAME=	gfax
PORTVERSION=	0.4.2
CATEGORIES=	comms print
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/0.4
DIST_SUBDIR=	gnome

MAINTAINER=	coop9211@uidaho.edu

BUILD_DEPENDS=	${LOCALBASE}/share/automake/install-sh:${PORTSDIR}/devel/automake \
		${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax
RUN_DEPENDS=	${LOCALBASE}/bin/sendfax:${PORTSDIR}/comms/hylafax

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack libpanel libcapplet libglade
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}"

post-extract:
	@${LN} -sf ${LOCALBASE}/share/automake/install-sh ${WRKSRC}/install-sh
	@${LN} -sf ${LOCALBASE}/share/automake/missing ${WRKSRC}/missing
	@${LN} -sf ${LOCALBASE}/share/automake/mkinstalldirs ${WRKSRC}/mkinstalldirs

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' \
			${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in*" | ${XARGS} ${REINPLACE_CMD} -e \
		 's|[(]gnomedatadir[)]/gnome|(gnomedatadir)|g'

pre-install:
	@${MV} ${WRKSRC}/gfax.install-lpr ${WRKSRC}/gfax.install-lpr.orig
	@${SED} \
		-e 's#%%PREFIX%%#${PREFIX}/#' \
		${WRKSRC}/gfax.install-lpr.orig > ${WRKSRC}/gfax.install-lpr
	@${MV} ${WRKSRC}/lpr.gfax ${WRKSRC}/lpr.gfax.orig
	@${SED} \
		-e 's#%%PREFIX%%#${PREFIX}/#' \
		${WRKSRC}/lpr.gfax.orig > ${WRKSRC}/lpr.gfax

post-install:
	@${SH} ${PREFIX}/bin/gfax.install-lpr

.include <bsd.port.mk>
