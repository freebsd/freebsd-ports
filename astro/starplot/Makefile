# New ports collection makefile for:	starplot
# Date created:				Mon Aug 20 09:08:07 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	starplot
PORTVERSION=	0.95.2
PORTREVISION=	2
CATEGORIES=	astro
MASTER_SITES=	http://starplot.org/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3-dimensional viewer for star charts

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_ICONV=	yes
MAKE_ENV=	DOCSDIR=${DOCSDIR} EXAMPLESDIR=${EXAMPLESDIR}
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE}

MAN1=		starconvert.1 starpkg.1 starplot.1

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.include <bsd.port.mk>
