# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	dissy
PORTVERSION=	10
PORTREVISION=	4
CATEGORIES=	devel

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Graphical frontend to the objdump disassembler

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gtk2>0:x11-toolkits/py-gtk2@${FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}webkitgtk>0:www/py-webkitgtk@${FLAVOR}
LIB_DEPENDS=	librsvg-2.so:graphics/librsvg2

USES=		python:2.7
USE_PYTHON=	distutils
USE_GITHUB=	yes
GH_ACCOUNT=	SimonKagstrom
GH_TAGNAME=	2f1005e

PORTDOCS=	COPYING ChangeLog README UPGRADE

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
