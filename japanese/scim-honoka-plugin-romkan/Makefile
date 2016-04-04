# Created by: Masashi CHIBA
# $FreeBSD$

PORTNAME=	scim-honoka-plugin-romkan
PORTVERSION=	0.9.0
PORTREVISION=	12
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-plugin-romkan-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	Honoka plugin for romaji input

BUILD_DEPENDS=	scim:textproc/scim \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/honoka.so:japanese/scim-honoka
RUN_DEPENDS:=	${BUILD_DEPENDS}

GNU_CONFIGURE=	yes
USES=		gettext gmake iconv libtool:keepla pathfix pkgconfig

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
