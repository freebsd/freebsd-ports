# Created by: Eric Anholt <anholt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkguitune
PORTVERSION=	0.8
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.oocities.org/harpin_floh/mysoft/
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Guitar (and other instruments) tuner for GTK+2

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		pkgconfig
NO_STAGE=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/icons/hicolor/scalable/apps/guitune_logo.svg

post-patch:
	@${REINPLACE_CMD} -e \
		's|VERSION=0.7|VERSION=${PORTVERSION}|g' ${WRKSRC}/configure
.for file in guitune.cc main.cc
	@${REINPLACE_CMD} -e \
		's|<linux/soundcard.h>|<sys/soundcard.h>|' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
