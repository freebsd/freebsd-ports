# New ports collection makefile for:	mono-addins
# Date created:				Aug 25 2008
# Whom:					Florent Thoumie <flz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mono-addins
PORTVERSION=	0.3.1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.novell.com/pub/mono/sources/${PORTNAME}/

MAINTAINER=	flz@FreeBSD.org
COMMENT=	Mono framework to create extensible applications

LIB_PC_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/mono.pc:${PORTSDIR}/lang/mono

BUILD_DEPENDS+=	${LIB_PC_DEPENDS}
RUN_DEPENDS+=	${LIB_PC_DEPENDS}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomehack pkgconfig

OPTIONS=	GTK2 "Enable GTK support" on

.include <bsd.port.pre.mk>
.include "${.CURDIR}/../../lang/mono/bsd.mono.mk"

.if !defined(WITHOUT_GTK2) && !defined(WITHOUT_GUI) && !defined(WITHOUT_X11)
USE_GNOME+=	gtksharp20
CONFIGURE_ARGS+=	--enable-gui
PLIST_SUB=	OPT_GTK2=""
.else
CONFIGURE_ARGS+=	--disable-gui
PLIST_SUB=	OPT_GTK2="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} 's|Exception ex|System.Exception ex|' \
		${WRKSRC}/Mono.Addins.Gui/Mono.Addins.Gui/ManageSitesDialog.cs

.include <bsd.port.post.mk>
