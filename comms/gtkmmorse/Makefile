# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	gtkmmorse
PORTVERSION=	0.9.27
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Graphical Morse Code Trainer

LIB_DEPENDS=	ao:${PORTSDIR}/audio/libao \
		gtkmm-2.4:${PORTSDIR}/x11-toolkits/gtkmm24 \
		gconfmm-2.6.1:${PORTSDIR}/devel/gconfmm26

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig

PLIST_FILES=	bin/gtkmmorse
MAN1=		gtkmmorse.1

.include <bsd.port.mk>
