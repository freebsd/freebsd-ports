# Created by: Norikatsu Shigemura <nork@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scim-prime
PORTVERSION=	0.3.0
PORTREVISION=	13
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	scim-imengine/17192

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM IMEngine module using PRIME

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		prime:${PORTSDIR}/japanese/prime
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
