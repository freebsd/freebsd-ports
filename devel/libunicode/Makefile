# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/devel/libunicode/Makefile,v 1.4 2007/09/10 05:27:38 mezz Exp $

PORTNAME=	libunicode
PORTVERSION=	0.4
PORTREVISION=	11
CATEGORIES=	devel gnome
MASTER_SITES=	GNOME/sources/libunicode/0.4
DISTNAME=	${PORTNAME}-${PORTVERSION}.gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Library for manipulating Unicode characters and strings

USES=		gmake iconv libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share \
		--datadir=${PREFIX}/share
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>
