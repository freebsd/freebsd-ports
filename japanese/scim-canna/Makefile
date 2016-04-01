# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-canna
PORTVERSION=	1.0.0
PORTREVISION=	15
CATEGORIES=	japanese
MASTER_SITES=	SFJP/scim-imengine/18849

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using Canna

BUILD_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libcanna.so:japanese/canna-lib
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
