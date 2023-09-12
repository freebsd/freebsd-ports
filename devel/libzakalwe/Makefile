PORTNAME=	libzakalwe
DISTVERSION=	g20230909
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
GL_TAGNAME=	521bc3ba81d78859fb3cabae88dae6ebe41f9c03

SHEBANG_FILES=	configure

HAS_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|gcc|${CC}|" ${WRKSRC}/configure

.include <bsd.port.mk>
