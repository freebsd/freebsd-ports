# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-skk
PORTVERSION=	1.4.1
PORTREVISION=	3
CATEGORIES=	japanese
MASTER_SITES=	http://cloud.github.com/downloads/ueno/ibus-skk/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese SKK input engine for IBus

RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:${PORTSDIR}/japanese/skk-jisyo
LIB_DEPENDS=	libskk.so:${PORTSDIR}/japanese/libskk \
		libibus-1.0.so:${PORTSDIR}/textproc/ibus

USE_PYTHON=	yes
USES=		gettext gmake pkgconfig
USE_GNOME=	intltool
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	DATADIRNAME=share

CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	NLS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/share/skk/SKK-JISYO.L|${LOCALBASE}/share/skk/SKK-JISYO.L|' ${WRKSRC}/src/preferences.c

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
