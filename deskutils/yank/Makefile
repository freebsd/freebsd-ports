# New ports collection makefile for:	yank
# Date created:				28 November 1999
# Whom:					Chris D. Faulhaber <jedgar@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	yank
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	deskutils gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	yank

MAINTAINER=	jedgar@FreeBSD.org
COMMENT=	A simple notekeeper and todo-list manager for GNOME

PLIST_SUB=	PORTVERSION=${PORTVERSION}

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomelibs gnomehack gnomeprefix
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -E 's^-l(pthread|c_r)^${PTHREAD_LIBS}^g' ${WRKSRC}/configure
	@${FIND} ${WRKSRC}/src/Plugins -name "Makefile.in" | \
		${XARGS} ${REINPLACE_CMD} -e \
		's|_la_LDFLAGS =|& -avoid-version|g'

.include <bsd.port.mk>
