# New ports collection makefile for:	teg
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	teg
PORTVERSION=	0.11.0
PORTREVISION=	1
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn-based strategy game for GNOME

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LDFLAGS="-L${LOCALBASE}/lib -lintl ${PTHREAD_LIBS}"

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" -type f | ${XARGS} \
		${REINPLACE_CMD} -e 's|LIST_NEXT|TEG_LIST_NEXT|g'

.include <bsd.port.mk>
