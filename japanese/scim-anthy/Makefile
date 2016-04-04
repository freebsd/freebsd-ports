# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-anthy
PORTVERSION=	1.2.7
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	SFJP/scim-imengine/37309

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using Anthy

BUILD_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libanthy.so:japanese/anthy
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		kasumi:japanese/kasumi

USES=		gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
