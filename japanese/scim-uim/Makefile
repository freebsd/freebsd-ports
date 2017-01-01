# Created by: Seiya Yanagita <s_yanagita@ybb.ne.jp>
# $FreeBSD$

PORTNAME=	scim-uim
PORTVERSION=	0.2.0
PORTREVISION=	11
CATEGORIES=	japanese
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION} \
		http://freedesktop.org/~suzhe/sources/

MAINTAINER=	s_yanagita@ybb.ne.jp
COMMENT=	SCIM IMEngine module using UIM input method library

BUILD_DEPENDS=	scim:textproc/scim
LIB_DEPENDS=	libuim.so:textproc/uim
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gmake iconv libtool:keepla pkgconfig
GNU_CONFIGURE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
