# New ports collection makefile for:	dia
# Date created:        21 December 1999
# Whom:                saper@system.pl
#
# $FreeBSD$
#

PORTNAME=	dia
PORTVERSION=	0.88.1
PORTREVISION=	1
CATEGORIES+=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	stable/sources/dia

MAINTAINER?=	gnome@FreeBSD.org

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		gdk_pixbuf.2:${PORTSDIR}/graphics/gdk-pixbuf

USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOMELIBS=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"

MAN1=		dia.1

.include <bsd.port.pre.mk>

.if exists(${X11BASE}/bin/panel) || defined(WITH_GNOME) || defined(PACKAGE_BUILDING)
.undef WITHOUT_GNOME
USE_GNOME=	yes
PKGNAMESUFFIX=	-gnome
CONFIGURE_ARGS=	--enable-gnome \
		--enable-gnome-print
PLIST_SUB+=	DIAHELP="help/dia" \
		GNOME:=""
MAKE_ENV=	HAVE_GNOME="yes"
.else
CONFIGURE_ARGS=	--disable-gnome
PLIST_SUB+=	DIAHELP="dia/help" \
		GNOME:="@comment "
.endif

pre-patch:
	@${PERL} -pi -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${PERL} -pi -e \
		's|\$\(datadir\)/gnome/|\$\(datadir\)/|g ; \
		 s|\$\(datadir\)/locale|\$\(prefix\)/share/locale|g'

post-install:
	${SED} "s|%%PREFIX%%|${PREFIX}|g" ${FILESDIR}/dia.sh > ${WRKDIR}/dia.sh
	${INSTALL_SCRIPT} ${WRKDIR}/dia.sh ${PREFIX}/bin/dia

.include <bsd.port.post.mk>
