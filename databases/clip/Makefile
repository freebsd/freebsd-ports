# ex:ts=8
# New ports collection makefile for:	clip
# Date created:			Dec 23, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	clip
PORTVERSION=	0.99
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.lastik.ru/clip/ \
		ftp://ftp.linux.ru.net/mirrors/clip/
DISTNAME=	${PORTNAME}-prg-${PORTVERSION}-3
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	xBase and Clipper language compatible compiler

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gtk12.2:${PORTSDIR}/x11-toolkits/gtk12 \
		gtkextra.17:${PORTSDIR}/x11-toolkits/gtkextra \
		gd.2:${PORTSDIR}/graphics/gd \
		intl.4:${PORTSDIR}/devel/gettext

USE_BISON=	yes
USE_GMAKE=	yes
USE_REINPLACE=  yes
USE_XLIB=	yes
USE_XPM=	yes
ALL_TARGET=	local
MAKE_ENV=	HOME=${WRKDIR}

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		-e "s|%%X11BASE%%|${X11BASE}|g" \
		${WRKSRC}/cliplibs/clip-gd/gd/configure

do-install:
	${CP} -R ${WRKDIR}/cliproot ${LOCALBASE}/clip

.include <bsd.port.mk>
