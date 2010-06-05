# New ports collection makefile for:	giggle
# Date created:		2008-10-01
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	giggle
PORTVERSION=	0.5
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	wahjava@gmail.com
COMMENT=	GTK+ frontend for git version control system

BUILD_DEPENDS=	git:${PORTSDIR}/devel/git \
		${SITE_PERL}/mach/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	git:${PORTSDIR}/devel/git
OPTIONS=	EDS	"Evolution Data Server support"	On \
		VTE	"Terminal Widget" On

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_GNOME=	glib20 gtk20 gtksourceview2 libglade2
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl"
PLIST_SUB+=	GIGGLE_VER=${PORTVERSION}

.include <bsd.port.options.mk>

.if defined(WITHOUT_EDS)
CONFIGURE_ARGS+=	--disable-evolution-data-server
.elif defined(WITH_EDS)
USE_GNOME+=	evolutiondataserver
.endif

.if defined(WITH_VTE)
USE_GNOME+=	vte
PLIST_SUB+=	VTE=""
.elif defined(WITHOUT_VTE)
CONFIGURE_ARGS+=	--disable-terminal
PLIST_SUB+=	VTE="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build
.endif

post-install:
	@-update-desktop-database

.include <bsd.port.post.mk>
