# New ports collection makefile for:	imhangul
# Date created:		May 26 2003
# Whom:			CHOI Junho <cjh@kr.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	imhangul
PORTVERSION=	2.0.0
CATEGORIES=	korean
MASTER_SITES=	http://kldp.net/frs/download.php/5924/

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	GTK+-2.0 hangul input module

LICENSE=	GPLv2

LIB_DEPENDS=	hangul.1:${PORTSDIR}/korean/libhangul

USE_AUTOTOOLS=	libtool
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20
GNU_CONFIGURE=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"
CPPFLAGS+=	"-I${LOCALBASE}/include"
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
