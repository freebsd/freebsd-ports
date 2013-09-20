# $FreeBSD$

PORTNAME=	ibus-hangul
PORTVERSION=	1.4.2
CATEGORIES=	korean
MASTER_SITES=	GOOGLE_CODE

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
USE_GNOME=	intltool pygobject3
USE_PYTHON=	yes
USES=		pathfix pkgconfig

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CONFIGURE_ARGS=	--enable-nls
PLIST_SUB=	NLS=""
.else
CONFIGURE_ARGS=	--disable-nls
PLIST_SUB=	NLS="@comment "
.endif

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.mk>
