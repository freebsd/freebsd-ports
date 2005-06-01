# New ports collection makefile for:	teg
# Date created:				31 October 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	teg
PORTVERSION=	0.11.1
PORTREVISION=	4
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A turn-based strategy game for GNOME

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui lthack
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	teg.schemas

post-patch:
	@${GREP} -lR " LIST_NEXT" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's| LIST_NEXT| TEG_LIST_NEXT|g'

.include <bsd.port.mk>
