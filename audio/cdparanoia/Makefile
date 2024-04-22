PORTNAME=	cdparanoia
PORTVERSION=	3.9.8
PORTREVISION=	10
CATEGORIES=	audio sysutils
MASTER_SITES=	http://www.xiph.org/paranoia/download/
DISTNAME=	${PORTNAME}-${PORTVERSION:C/^3\./III-alpha/}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	CDDA extraction tool (also known as ripper)
WWW=		https://www.xiph.org/paranoia/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

USES=		gmake
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's/\(^ *default:\)/\1break;/' \
		${WRKSRC}/interface/utils.h

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcdda_*.so

.include <bsd.port.mk>
