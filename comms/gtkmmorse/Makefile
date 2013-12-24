# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	gtkmmorse
PORTVERSION=	0.9.27
CATEGORIES=	comms hamradio
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	shurd@sasktel.net
COMMENT=	Graphical Morse Code Trainer

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao \
		libgtkmm-2.4.so:${PORTSDIR}/x11-toolkits/gtkmm24 \
		libgconfmm-2.6.so:${PORTSDIR}/devel/gconfmm26

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig

PLIST_FILES=	bin/gtkmmorse
MAN1=		gtkmmorse.1

post-patch:
	@${REINPLACE_CMD} -e 's|-ansi||g' -e 's|-pedantic||g' \
		${WRKSRC}/src/Makefile.in

NO_STAGE=	yes
.include <bsd.port.mk>
