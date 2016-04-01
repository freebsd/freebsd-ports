# Created by: Masashi CHIBA
# $FreeBSD$

PORTNAME=	scim-honoka-plugin-wnn
PORTVERSION=	0.9.0
PORTREVISION=	13
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-plugin-wnn-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	Honoka plugin for using wnn7

BUILD_DEPENDS=	scim:textproc/scim \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/honoka.so:japanese/scim-honoka
LIB_DEPENDS=	libwnn7.so:japanese/Wnn7-lib
RUN_DEPENDS=	scim:textproc/scim \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/honoka.so:japanese/scim-honoka \
		${LOCALBASE}/lib/scim-1.0/1.4.0/honoka/plugin-romkan.so:japanese/scim-honoka-plugin-romkan

GNU_CONFIGURE=	yes
USES=		gettext gmake iconv libtool:keepla pathfix pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
