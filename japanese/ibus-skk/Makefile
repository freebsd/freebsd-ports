# Created by: Hiroto Kagotani <hiroto.kagotani@gmail.com>
# $FreeBSD$

PORTNAME=	ibus-skk
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	japanese
MASTER_SITES=	GHC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Japanese SKK input engine for IBus

RUN_DEPENDS=	${LOCALBASE}/share/skk/SKK-JISYO.L:japanese/skk-jisyo
LIB_DEPENDS=	libskk.so:japanese/libskk \
		libibus-1.0.so:textproc/ibus

USES=		gettext gmake pkgconfig python
USE_GNOME=	intltool
USE_GITHUB=	yes
GH_ACCOUNT=	ueno
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
