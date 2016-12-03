# Created by: lightside <lightside@gmx.com>
# $FreeBSD$

PORTNAME=	focuswriter
PORTVERSION=	1.5.7
DISTVERSIONPREFIX=	v
PORTREVISION=	1
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

USES=		desktop-file-utils pkgconfig qmake
INSTALLS_ICONS=	yes

LIBS+=		-lz

PORTDATA=	*
PORTDOCS=	CREDITS NEWS README

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	QT5
OPTIONS_SINGLE=		QT
OPTIONS_SINGLE_QT=	QT4 QT5
QT_DESC=		Qt toolkit

QT4_RUN_DEPENDS=	${LOCALBASE}/lib/libSDL2_mixer.so:audio/sdl2_mixer
QT4_USE=	QT4=corelib,gui,network,moc_build,rcc_build
QT5_USE=	QT5=concurrent,core,gui,multimedia,network,printsupport,widgets,buildtools_build
QT5_USE+=	GL=gl

post-patch:
	@${REINPLACE_CMD} -e '/PKGCONFIG/s/ zlib// ; \
		/INSTALLS/s/man //' \
		${WRKSRC}/focuswriter.pro

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

post-install:
	${INSTALL_MAN} ${WRKSRC}/resources/unix/focuswriter.1 \
		${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
