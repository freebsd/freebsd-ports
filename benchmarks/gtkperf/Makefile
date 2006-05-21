# Ports collection makefile for:	gtkperf
# Date created:				2006-04-22
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		gtkperf
PORTVERSION=		0.40
CATEGORIES=		benchmarks
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=		${PORTNAME}_${PORTVERSION}

MAINTAINER=		andreas@syndrom23.de
COMMENT=		Measure your system's GTK+ performance

WRKSRC=			${WRKDIR}/${PORTNAME}
USE_GMAKE=		yes
GNU_CONFIGURE=		yes
USE_GNOME=		gtk20 gnomeprefix
USE_X_PREFIX=		yes
USE_GETOPT_LONG=	yes

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
USE_ICONV=		yes
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.mk>
