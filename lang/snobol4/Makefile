# Created by: Wes Peters <wes@softweyr.com>
# $FreeBSD$

PORTNAME=	snobol4
PORTVERSION=	1.5
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.ultimate.com/snobol/

MAINTAINER=	johans@FreeBSD.org
COMMENT=	A port of Macro SNOBOL4, supports full SNOBOL4 plus SPITBOL

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--snolibdir=${PREFIX}/lib/${PORTNAME}
USES=		gmake
PLIST_SUB+=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} 's:[^=]*\.tmp$$:${WRKSRC}/&:' ${WRKSRC}/configure

.include <bsd.port.mk>
