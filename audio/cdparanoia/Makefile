PORTNAME=	cdparanoia
PORTVERSION=	3.10.2
CATEGORIES=	audio sysutils
MASTER_SITES=	http://downloads.xiph.org/releases/cdparanoia/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/^3./III-/}
EXTRACT_SUFX=	.src.tgz

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	CDDA extraction tool (also known as ripper)
WWW=		https://www.xiph.org/paranoia/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING-GPL

USES=		gmake
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.mk>
