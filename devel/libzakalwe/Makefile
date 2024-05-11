PORTNAME=	libzakalwe
DISTVERSION=	1.0.0
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Shared tools library required by UADE
WWW=		https://gitlab.com/hors/libzakalwe

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash

USES=		gmake shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	hors
GL_TAGNAME=	b53b65812353e472588e1b24ead12891f174760a

SHEBANG_FILES=	configure

HAS_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" ${WRKSRC}/configure

.include <bsd.port.mk>
