PORTNAME=	scim-pinyin
PORTVERSION=	0.5.92
PORTREVISION=	4
CATEGORIES=	chinese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SCIM Chinese Smart Pinyin input method
WWW=		https://github.com/scim-im/scim

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	scim>=1.2.0:textproc/scim
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake iconv libtool:keepla localbase:ldflags pkgconfig
USE_CXXSTD=	c++14

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-skim-support

INSTALL_TARGET=	install-strip

CPPFLAGS+=	-D__STDC_ISO_10646__
LDFLAGS+=	-lintl

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
