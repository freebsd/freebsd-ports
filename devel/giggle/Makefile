# New ports collection makefile for:	giggle
# Date created:		2008-10-01
# Whom:			Ashish Shukla <wahjava@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	giggle
PORTVERSION=	0.4.91
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	GNOME

MAINTAINER=	wahjava@gmail.com
COMMENT=	GTK+ frontend for git version control system

BUILD_DEPENDS=	git:${PORTSDIR}/devel/git \
		${SITE_PERL}/mach/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	git:${PORTSDIR}/devel/git
OPTIONS=	EDS	"Evolution Data Server support"	on

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20 gtksourceview2 libglade2
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		does not build
.endif

.if defined(WITHOUT_EDS)
CONFIGURE_ARGS+=	--disable-evolution-data-server
.elif defined(WITH_EDS)
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/libebook-1.2.pc:${PORTSDIR}/databases/evolution-data-server
.endif

.include <bsd.port.post.mk>
