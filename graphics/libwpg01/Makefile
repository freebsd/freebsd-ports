# Created by: Dima Panov <fluffy@Fluffy.Khv.RU>
# $FreeBSD$

PORTNAME=	libwpg
PORTVERSION=	0.1.3
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	Library for importing and converting Corel WordPerfect(tm) Graphics images

LIB_DEPENDS=	wpd-0.8.8:${PORTSDIR}/textproc/libwpd08

LATEST_LINK=	${PORTNAME}01

LICENSE=	LGPL20

USE_AUTOTOOLS=	libtool
USE_GNOME=	gnomeprefix gnomehack ltverhack
USES=		perl5 pkgconfig
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/docs//g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -E '/^SUBDIRS = /s/conv//g' ${WRKSRC}/src/Makefile.in

.include <bsd.port.mk>
