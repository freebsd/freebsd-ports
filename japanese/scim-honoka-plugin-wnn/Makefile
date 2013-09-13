# Created by: Masashi CHIBA 
# $FreeBSD$

PORTNAME=	scim-honoka-plugin-wnn
PORTVERSION=	0.9.0
PORTREVISION=	10
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-plugin-wnn-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	Honoka plugin for using wnn7

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/honoka.so:${PORTSDIR}/japanese/scim-honoka
LIB_DEPENDS=	wnn7.1:${PORTSDIR}/japanese/Wnn7-lib
RUN_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/honoka.so:${PORTSDIR}/japanese/scim-honoka \
		${LOCALBASE}/lib/scim-1.0/1.4.0/honoka/plugin-romkan.so:${PORTSDIR}/japanese/scim-honoka-plugin-romkan

USES=		gettext gmake iconv pathfix pkgconfig
USE_GNOME=	lthack
USE_AUTOTOOLS=	libtool

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

CPPFLAGS+=	-I${LOCALBASE}/include -D__STDC_ISO_10646__
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
