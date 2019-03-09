# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	focuswriter
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.2
CATEGORIES=	editors

MAINTAINER=	lightside@gmx.com
COMMENT=	Simple, distraction-free writing environment

LICENSE=	GPLv3+ LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3+ =	${WRKSRC}/resources/images/icons/oxygen/COPYING

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell

USES=		compiler:c++11-lib desktop-file-utils gl pkgconfig qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	gottcode
USE_GL=		gl
USE_QT=		concurrent core gui multimedia network printsupport widgets \
		buildtools_build linguisttools_build

PORTDATA=	*
PORTDOCS=	ChangeLog CREDITS README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/INSTALLS/s/man //' \
		${WRKSRC}/focuswriter.pro

post-install:
	${INSTALL_MAN} ${WRKSRC}/resources/unix/focuswriter.1 \
		${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
