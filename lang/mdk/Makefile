# ex:ts=8
# New ports collection makefile for:  mdk
# Date created:			Apr 1, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mdk
PORTVERSION=	1.0
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNU} \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ijliao@FreeBSD.org

USE_X_PREFIX=	yes
USE_GNOME=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -lgnugetopt" \
		MAKEINFO="makeinfo --no-split"

post-extract:
	@${RM} -f ${WRKSRC}/doc/*.info

.include <bsd.port.mk>
