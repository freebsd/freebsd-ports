# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	giggle
PORTVERSION=	0.5
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GTK+ frontend for git version control system

BUILD_DEPENDS=	git:${PORTSDIR}/devel/git \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	git:${PORTSDIR}/devel/git

OPTIONS_DEFINE=	VTE
OPTIONS_DEFAULT=	VTE
VTE_DESC=	Terminal Widget

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 gtksourceview2 libglade2
USES=		gettext gmake pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl `pkg-config -libs gmodule-2.0`
INSTALL_TARGET=	install-strip
PLIST_SUB+=	GIGGLE_VER=${PORTVERSION}
CONFIGURE_ARGS+=	--disable-evolution-data-server

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVTE}
USE_GNOME+=	vte
PLIST_SUB+=	VTE=""
.else
CONFIGURE_ARGS+=	--disable-terminal
PLIST_SUB+=	VTE="@comment "
.endif

.include <bsd.port.mk>
