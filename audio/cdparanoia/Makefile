# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	cdparanoia
PORTVERSION=	3.9.8
PORTREVISION=	9
CATEGORIES=	audio sysutils
MASTER_SITES=	http://www.xiph.org/paranoia/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^3\./III-alpha/}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	CDDA extraction tool (also known as ripper)

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/\(^ *default:\)/\1break;/' \
		${WRKSRC}/interface/utils.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdda_*

.include <bsd.port.mk>
