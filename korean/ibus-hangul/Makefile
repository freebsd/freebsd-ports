# New ports collection makefile for:	ibus-hangul
# Date created:				August 8, 2011
# Whom:					Jung-uk Kim <jkim@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ibus-hangul
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	korean
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	jkim@FreeBSD.org
COMMENT=	Hangul input engine for IBus

LICENSE=	GPLv2

LIB_DEPENDS=	hangul:${PORTSDIR}/korean/libhangul \
		ibus-1.0:${PORTSDIR}/textproc/ibus

PROJECTHOST=	ibus

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_AUTOTOOLS=	libtool
USE_GMAKE=	yes
USE_GNOME=	gnomehack intltool pkgconfig
USE_PYTHON=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
