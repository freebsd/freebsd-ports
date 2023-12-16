PORTNAME=	liblcf
PORTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Library to handle RPG Maker 2000/2003 and EasyRPG projects
WWW=		https://easyrpg.org/ \
		https://github.com/EasyRPG/liblcf

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libicui18n.so:devel/icu \
		libexpat.so:textproc/expat2

USE_GITHUB=	yes
GH_ACCOUNT=	EasyRPG

USES=		cmake compiler:c++14-lang pkgconfig shared-mime-info
USE_LDCONFIG=	yes
CMAKE_OFF=	LIBLCF_UPDATE_MIMEDB

PORTDOCS=	AUTHORS.md README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
