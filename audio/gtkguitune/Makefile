PORTNAME=	gtkguitune
PORTVERSION=	0.8
DISTVERSIONPREFIX=	gtk2-
PORTREVISION=	13
CATEGORIES=	audio
MASTER_SITES=	http://www.oocities.org/harpin_floh/mysoft/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Guitar (and other instruments) tuner for GTK 2
WWW=		http://www.oocities.com/harpin_floh/kguitune_page.html

LICENSE=	GPLv2+

USES=		compiler:c++11-lang gnome pkgconfig
USE_CXXSTD=	c++11
USE_GNOME=	gtkmm24

GNU_CONFIGURE=	yes

DESKTOP_ENTRIES="GtkGuitune" "" "guitune_logo" "${PORTNAME}" "" ""

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/icons/hicolor/scalable/apps/guitune_logo.svg

post-patch:
	@${REINPLACE_CMD} -e \
		's|VERSION=0.7|VERSION=${PORTVERSION}|g' ${WRKSRC}/configure
.for i in guitune.cc main.cc
	@${REINPLACE_CMD} -e \
		's|<linux/soundcard.h>|<sys/soundcard.h>|' ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>
