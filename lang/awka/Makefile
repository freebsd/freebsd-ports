PORTNAME=	awka
PORTVERSION=	0.7.5
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://awka.sourceforge.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts the AWK script to C, then compiles it
WWW=		https://awka.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/GPL.txt

GNU_CONFIGURE=	yes

USES=		desthack
USE_LDCONFIG=	yes

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/awka \
		${STAGEDIR}${PREFIX}/lib/libawka.so

.include <bsd.port.mk>
