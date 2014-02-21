# Created by: ijliao
# $FreeBSD$

PORTNAME=	awka
PORTVERSION=	0.7.5
CATEGORIES=	lang
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the AWK script to C, then compiles it

GNU_CONFIGURE=	yes

USES=		desthack
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awka

.include <bsd.port.mk>
