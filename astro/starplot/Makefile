# New ports collection makefile for:	starplot
# Date created:				Mon Aug 20 09:08:07 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	starplot
PORTVERSION=	0.95.4
CATEGORIES=	astro
MASTER_SITES=	http://starplot.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-dimensional viewer for star charts

USE_GNOME=	gnometarget gtk20
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
MAKE_ENV=	DOCSDIR="${DOCSDIR}" EXAMPLESDIR="${EXAMPLESDIR}"

MAN1=		starconvert.1 starpkg.1 starplot.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
