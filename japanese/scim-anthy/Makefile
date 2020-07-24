# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-anthy
PORTVERSION=	1.2.7
PORTREVISION=	6
CATEGORIES=	japanese
MASTER_SITES=	OSDN/scim-imengine

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using Anthy

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libanthy.so:japanese/anthy
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		kasumi:japanese/kasumi

USES=		gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
