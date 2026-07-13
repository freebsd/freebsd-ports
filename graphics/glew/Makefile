PORTNAME=	glew
PORTVERSION=	2.3.1
PORTREVISION?=	0
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER?=	x11@FreeBSD.org
COMMENT=	OpenGL Extension Wrangler Library
WWW=		https://glew.sourceforge.net/

LICENSE=	MIT BSD3CLAUSE
LICENSE_COMB=	dual

USES=		gmake gl tar:tgz xorg
USE_XORG?=	x11
USE_GL?=	gl glu
USE_LDCONFIG=	yes

MAKE_ENV=	GLEW_DEST=${PREFIX} GLEW_PREFIX=${PREFIX}
INSTALL_TARGET?=install.all

OPTIONS_DEFINE?=DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|CFLAGS =|CFLAGS +=|' \
		-e 's|^LIBDIR|GLEW_LIBDIR|' \
		-e 's|$$(LIBDIR)|$$(GLEW_LIBDIR)|' \
		${WRKSRC}/Makefile

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in css html jpg png
	${INSTALL_DATA} ${WRKSRC}/doc/*.${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
