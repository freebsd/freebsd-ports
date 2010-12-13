# New ports collection makefile for:	gtkguitune
# Date created:				12 Feb 2005
# Whom:					Eric Anholt <anholt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkguitune
PORTVERSION=	0.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.oocities.com/harpin_floh/mysoft/
DISTNAME=	${PORTNAME}-gtk2-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A guitar (and other instruments) tuner for GTK

LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24

WRKSRC=		${WRKDIR}/${PORTNAME}

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
