# New ports collection makefile for:	blokish
# Date created:				18 Jan 2006
# Whom:					Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	blokish
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}_v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the strategy board game 'Blokus'

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GL=		gl
USE_WX=		2.6+

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib" \
		CPPFLAGS="-I${LOCALBASE}/include"

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/blokish

PLIST_FILES=	bin/blokish

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' ${WRKSRC}/makefile.in ${WRKSRC}/configure

.include <bsd.port.mk>
