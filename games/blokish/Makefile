# Created by: Dmitry Marakasov <amdmi3@amdmi3.ru>
# $FreeBSD$

PORTNAME=	blokish
PORTVERSION=	0.9.4
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}_v${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Clone of the strategy board game 'Blokus'

GNU_CONFIGURE=	yes
USES=		gmake
USE_GL=		gl
USE_WX=		2.8
WX_UNICODE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAKEFILE=	makefile

WRKSRC=		${WRKDIR}/blokish

PLIST_FILES=	bin/blokish

post-patch:
	@${REINPLACE_CMD} -e 's|wx-config|${WX_CONFIG}|' \
		${WRKSRC}/makefile.in ${WRKSRC}/configure

.include <bsd.port.mk>
