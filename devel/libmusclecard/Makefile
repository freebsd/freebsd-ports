# New ports collection makefile for:		libmusclecard
# Date created:					2005-04-15
# Whom:						arved
#
# $FreeBSD$

PORTNAME=	libmusclecard
PORTVERSION=	1.2.9.b.7
CATEGORIES=	devel
MASTER_SITES=	https://alioth.debian.org/download.php/977/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MUSCLE Card Framework

LIB_DEPENDS=	pcsclite.1:${PORTSDIR}/devel/pcsc-lite

WRKSRC=		${WRKDIR}/libmusclecard-${PORTVERSION:S/.b./-beta/}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-muscledropdir=${LOCALBASE}/lib/pcsc/services
USE_REINPLACE=	yes
USE_GNOME=	gnomehack
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=	15

MAN8=		bundleTool.8

post-patch:
	${REINPLACE_CMD} -e "s,LDLIBS,LIBS,g" ${WRKSRC}/configure
	${REINPLACE_CMD} -e "s,SUBDIRS = doc,SUBDIRS =," ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
