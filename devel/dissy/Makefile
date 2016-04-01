# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	dissy
PORTVERSION=	10
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Graphical frontend to the objdump disassembler

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2 \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>0:www/py-webkitgtk
LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2

USES=		python
USE_PYTHON=	distutils

PORTDOCS=	COPYING ChangeLog README UPGRADE

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
