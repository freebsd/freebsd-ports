# New ports collection makefile for:	epdfview
# Date created:				2006/06/01
# Whom:					chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	epdfview
PORTVERSION=	0.1.7
PORTREVISION=	6
CATEGORIES=	graphics print gnome
MASTER_SITES=	http://trac.emma-soft.com/epdfview/chrome/site/releases/ \
		http://mirror.slitaz.org/sources/packages/e/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A lightweight PDF document viewer

BUILD_DEPENDS=	cppunit-config:${PORTSDIR}/devel/cppunit
LIB_DEPENDS=	poppler-glib.4:${PORTSDIR}/graphics/poppler-gtk

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20 intlhack
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	CUPS	"Use cups printing system"		off \
		NLS	"Native language support"		on

.include <bsd.port.pre.mk>

.if defined(WITH_CUPS)
CONFIGURE_ARGS+=--with-cups
LIB_DEPENDS+=	cups.2:${PORTSDIR}/print/cups-base
.else
CONFIGURE_ARGS+=--without-cups
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-install:
	${MKDIR} ${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/data/${PORTNAME}.desktop ${PREFIX}/share/applications/
	@-update-desktop-database

.include <bsd.port.post.mk>
