# New ports collection makefile for:	blokish
# Date created:				18 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blokish
PORTVERSION=	0.9.3
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_src_v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	Clone of the strategy board game 'Blokus'

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		yes
USE_WX=		2.6

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include"

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/blokish

PLIST_FILES=	bin/blokish

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' ${WRKSRC}/makefile.in ${WRKSRC}/configure

.include <bsd.port.mk>
