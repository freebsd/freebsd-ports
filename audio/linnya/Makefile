# New ports collection makefile for:	linnya
# Date created:				1 Sep 2012
# Whom:					XiaoQI Ge <ghw@7axu.com>
# $FreeBSD$

PORTNAME=	linnya
PORTVERSION=	2.2.0
CATEGORIES=	audio

MAINTAINER=	ghw@7axu.com
COMMENT=	A Linnya Audio Player

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	herenvarno
GH_COMMIT=	6724a9b

USE_AUTOTOOLS=	aclocal automake
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk30
USE_SQLITE=	3
USE_GETTEXT=	yes
USE_GSTREAMER=	good mp3 ogg
MAKE_JOBS_SAFE=	yes
USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
WANT_GNOME=	yes

BUILD_DEPENDS+=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS+=	curl:${PORTSDIR}/ftp/curl

.include <bsd.port.mk>
