# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim-pinyin
PORTVERSION=	0.5.92
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM Chinese Smart Pinyin input method

BUILD_DEPENDS=	scim>=1.2.0:textproc/scim
RUN_DEPENDS:=	${BUILD_DEPENDS}

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake iconv libtool:keepla pathfix pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-skim-support
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
