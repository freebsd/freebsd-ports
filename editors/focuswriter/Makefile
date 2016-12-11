# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	focuswriter
PORTVERSION=	1.6.3
DISTVERSIONPREFIX=	v
CATEGORIES=	editors

MAINTAINER=	lightside@gmx.com
COMMENT=	Simple, distraction-free writing environment

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL3=	${WRKSRC}/resources/images/icons/oxygen/COPYING

LIB_DEPENDS=	libhunspell-1.5.so:textproc/hunspell

USE_GITHUB=	yes
GH_ACCOUNT=	gottcode

USES=		compiler:c++11-lib desktop-file-utils pkgconfig qmake
USE_GL=		gl
USE_QT5=	concurrent core gui multimedia network printsupport widgets \
		buildtools_build linguisttools_build
INSTALLS_ICONS=	yes

LIBS+=		-lz

PORTDATA=	*
PORTDOCS=	CREDITS NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e '/PKGCONFIG/s/ zlib// ; \
		/INSTALLS/s/man //' \
		${WRKSRC}/focuswriter.pro
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000054
	@${REINPLACE_CMD} -e 's/std::lround/lround/g' \
		${WRKSRC}/src/daily_progress_dialog.cpp \
		${WRKSRC}/src/scene_list.cpp \
		${WRKSRC}/src/theme_dialog.cpp \
		${WRKSRC}/src/fileformats/docx_reader.cpp \
		${WRKSRC}/src/fileformats/odt_reader.cpp \
		${WRKSRC}/src/fileformats/rtf_reader.cpp
.endif

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

post-install:
	${INSTALL_MAN} ${WRKSRC}/resources/unix/focuswriter.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.post.mk>
