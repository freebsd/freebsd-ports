# New ports collection makefile for:	ibus-hangul
# Date created:				August 8, 2011
# Whom:					Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-hangul
PORTVERSION=	1.3.1
CATEGORIES=	korean
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus

LICENSE=	GPLv2

LIB_DEPENDS=	hangul.1:${PORTSDIR}/korean/libhangul \
		ibus.2:${PORTSDIR}/textproc/ibus

PROJECTHOST=	ibus

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_GNOME=	intltool pkgconfig
USE_PYTHON=	yes

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
