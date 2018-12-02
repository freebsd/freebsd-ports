# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qtm
PORTVERSION=	1.3.17
CATEGORIES=	deskutils
MASTER_SITES=	SF/catkin/${PORTNAME}-${PORTVERSION:R}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog management application based on Qt 4

LICENSE=	GPLv2 # only
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		cmake qt:4 tar:bzip2 ssl
USE_QT=		corelib dbus gui network xml \
		moc_build qmake_build rcc_build uic_build
CMAKE_ARGS=	-DCMAKE_CXX_FLAGS_RELEASE:STRING="-DNDEBUG" \
		-DMANPAGE_DIRECTORY:STRING="${MANPREFIX}/man/man1" \
		-DMARKDOWN_LOCATION:STRING="${LOCALBASE}/bin/markdown"

PORTDOCS=	Changelog INSTALL README
PLIST_FILES=	bin/qtm man/man1/qtm.1.gz share/applications/qtm.desktop \
		share/pixmaps/qtm-logo1.png

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|icons|pixmaps|' ${WRKSRC}/CMakeLists.txt
	@${REINPLACE_CMD} -e \
		's|icons|pixmaps| ; \
		 /^Categories/s|;X-.*;|;| ; \
		 /^# /d' ${WRKSRC}/qtm-desktop.sh

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in Changelog INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
