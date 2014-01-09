# Created by: Jie Gao <gaoj@cpsc.ucalgary.ca>
# $FreeBSD$

PORTNAME=	scim-pinyin
PORTVERSION=	0.5.92
CATEGORIES=	chinese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	pclin@FreeBSD.org
COMMENT=	SCIM Chinese Smart Pinyin input method

BUILD_DEPENDS=	scim>=1.2.0:${PORTSDIR}/textproc/scim
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GNOME=	lthack
USES=		pathfix iconv gmake pkgconfig
USE_AUTOTOOLS=	libtool

CONFIGURE_ARGS+=	--disable-skim-support

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib -lintl

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
