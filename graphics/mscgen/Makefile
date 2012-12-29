# Created by: Romain Tartiere <romain@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mscgen
PORTVERSION=	0.20
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.mcternan.me.uk/mscgen/software/ \
		http://romain.blogreen.org/distfiles/
DISTNAME=	${PORTNAME}-src-${PORTVERSION}

MAINTAINER=	romain@FreeBSD.org
COMMENT=	A Message Sequence Chart Renderer

OPTIONS_DEFINE=	PNG
OPTIONS_DEFAULT=	PNG

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPNG}
CONFIGURE_ARGS+=--with-png
LIB_DEPENDS+=	gd.4:${PORTSDIR}/graphics/gd
.else
CONFIGURE_ARGS+=--without-png
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes

MAN1=		mscgen.1

.include <bsd.port.mk>
