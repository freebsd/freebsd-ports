# New ports collection makefile for:	gIDE
# Date created:				29 Jul 1998
# Whom:					rom
#
# $FreeBSD$
#

PORTNAME=	gide
PORTVERSION=	0.3.5
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/gide/0.3

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GTK-based IDE for the C programming Language

BUILD_DEPENDS=	xml-i18n-update:${PORTSDIR}/textproc/xml-i18n-tools
LIB_DEPENDS=	gdl.0:${PORTSDIR}/x11-toolkits/gdl \
		gbf.0:${PORTSDIR}/devel/gnomebuild \
		gdf.0:${PORTSDIR}/devel/gnomedebug

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnomeprefix gnomevfs bonobo
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

MAN1=		gide.1

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g; \
		s|%%X11BASE%%|${X11BASE}|g" ${WRKSRC}/src/*.c

pre-configure:
	@${LN} -sf ${LOCALBASE}/share/xml-i18n-tools/*.in ${WRKSRC}

.include <bsd.port.mk>
