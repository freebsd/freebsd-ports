# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.86
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/dia

MAINTAINER=	saper@system.pl

LIB_DEPENDS=	gnome.4:${PORTSDIR}/x11/gnomelibs \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12  \
		xml.5:${PORTSDIR}/textproc/libxml	\
		gdk_imlib.5:${PORTSDIR}/graphics/imlib \
		popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	panel:${PORTSDIR}/x11/gnomecore

GLIB_CONFIG?=	${LOCALBASE}/bin/glib12-config
GTK_CONFIG?=    ${X11BASE}/bin/gtk12-config

USE_X_PREFIX=   yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome \
		--enable-gnome
CONFIGURE_ENV=  CPPFLAGS="-I${LOCALBASE}/include" \
		GTK_CONFIG="${GTK_CONFIG}" \
		GLIB_CONFIG="${GLIB_CONFIG}" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		dia.1

pre-patch:
	@${PERL} -pi -e 's|-lpthread|-pthread|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	${SED} "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/dia.sh > ${WRKDIR}/dia.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dia.sh ${PREFIX}/bin/dia

.include <bsd.port.mk>
