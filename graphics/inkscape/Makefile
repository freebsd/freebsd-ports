# New ports collection makefile for:	inkscape
# Date created:		17 Nov 2003
# Whom:			Alexander Nedotsukov <bland@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	inkscape
PORTVERSION=	0.36
PORTREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A program seeks to become a full featured open source SVG editor

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt
RUN_DEPENDS=	${SITE_PERL}/XML/XQL.pm:${PORTSDIR}/textproc/p5-XML-XQL

USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libglade2 libartlgpl2 libgnomeprintui
USE_REINPLACE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--with-popt \
		--with-gnome-print
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${LOCALBASE}/include/freetype2 -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

MAN1=		inkscape.1

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc.h>|<stdlib.h>|g' \
		${WRKSRC}/src/helper/action.c \
		${WRKSRC}/src/libarikkei/arikkei-token.c

.include <bsd.port.mk>
