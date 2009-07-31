# New ports collection makefile for:    ja-scim-honoka-plugin-romkan
# Date created:		3 Jun 2006
# Whom:			Masashi CHIBA 
#
# $FreeBSD$
#

PORTNAME=	scim-honoka-plugin-romkan
PORTVERSION=	0.9.0
PORTREVISION=	5
CATEGORIES=	japanese
MASTER_SITES=	http://nop.net-p.org/files/honoka/
DISTNAME=	honoka-plugin-romkan-${PORTVERSION}

MAINTAINER=	chiba.masashi@gmail.com
COMMENT=	Honoka plugin for romaji input

BUILD_DEPENDS=	scim:${PORTSDIR}/textproc/scim \
		${LOCALBASE}/lib/scim-1.0/1.4.0/IMEngine/honoka.so:${PORTSDIR}/japanese/scim-honoka
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GETTEXT=	yes
USE_GNOME=	lthack gnomehack
USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:15

CONFIGURE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		CPPFLAGS="-I${LOCALBASE}/include -D__STDC_ISO_10646__" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.mk>
