# Created by: Hajimu UMEMOTO <ume@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-anthy
PORTVERSION=	1.2.7
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=scim-imengine/37309

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using Anthy

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim
LIB_DEPENDS=	libanthy.so:${PORTSDIR}/japanese/anthy
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		kasumi:${PORTSDIR}/japanese/kasumi

USES=		gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
