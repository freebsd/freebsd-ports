# Created by: Ashish Shukla <wahjava@gmail.com>
# $FreeBSD$

PORTNAME=	giggle
PORTVERSION=	0.7
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	GTK+ frontend for git version control system

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	git:${PORTSDIR}/devel/git \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		itstool:${PORTSDIR}/textproc/itstool
RUN_DEPENDS=	git:${PORTSDIR}/devel/git

OPTIONS_DEFINE=	VTE NLS
OPTIONS_DEFAULT=	VTE NLS
VTE_DESC=	Terminal Widget

GNU_CONFIGURE=	yes
USE_XZ=		yes
USE_GNOME=	glib20 gtk30 libglade2 gtksourceview3 gdkpixbuf2
USES=		gmake pkgconfig
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lintl `${LOCALBASE}/bin/pkg-config -libs gmodule-2.0`
INSTALL_TARGET=	install-strip
PLIST_SUB+=	GIGGLE_VER=${PORTVERSION}
CONFIGURE_ARGS+=	--disable-evolution-data-server \
			--with-git-command=${LOCALBASE}/bin/git

OPTIONS_SUB=	VTE

VTE_USE=		GNOME=vte3
VTE_CONFIGURE_ENABLE=	terminal

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

.include <bsd.port.mk>
