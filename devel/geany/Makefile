# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	geany
PORTVERSION=	1.23.1
CATEGORIES=	devel editors
MASTER_SITES=	http://download.geany.org/ SF

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Fast and lightweight GTK+ IDE

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
USES=		gmake pathfix pkgconfig
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	VTE NLS DOCS
OPTIONS_DEFAULT=	${OPTIONS_DEFINE}
VTE_DESC=	Embedded virtual terminal

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MVTE}
USE_GNOME+=	vte
CONFIGURE_ARGS+=--enable-vte
.else
CONFIGURE_ARGS+=--disable-vte
.endif

post-patch:
.if !${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|doc||' ${WRKSRC}/Makefile.in
.endif
.if !${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|po||' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
