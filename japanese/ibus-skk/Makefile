# New ports collection makefile for:	ibus-skk
# Date created:	4 January 2010
# Whom:		Hiroto Kagotani <hiroto.kagotani@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ibus-skk
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/ibus-skk/

MAINTAINER=	hiroto.kagotani@gmail.com
COMMENT=	A Japanese SKK input engine for IBus

RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:${PORTSDIR}/japanese/skk-jisyo
LIB_DEPENDS=	skk:${PORTSDIR}/japanese/libskk \
		ibus-1.0:${PORTSDIR}/textproc/ibus

USE_PYTHON=	yes
USE_GETTEXT=	yes

USE_GMAKE=	yes
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/skk/SKK-JISYO.L|${LOCALBASE}/share/skk/SKK-JISYO.L|' ${WRKSRC}/src/preferences.c

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO} To display this message again, type ${PKG_INFO} -D ${PKGNAME}

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
