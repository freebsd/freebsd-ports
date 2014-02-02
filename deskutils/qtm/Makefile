# Created by: Yinghong.Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	qtm
PORTVERSION=	1.3.13
CATEGORIES=	deskutils
MASTER_SITES=	SF/catkin/${PORTNAME}-1.3 \
		http://www.c-s.li/ports/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Blog management application based on Qt 4

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_QT4=	corelib dbus gui network xml \
		moc_build qmake_build rcc_build uic_build
USE_OPENSSL=	yes
USES=		cmake desktop-file-utils
CMAKE_ARGS=	-DCMAKE_CXX_FLAGS_RELEASE:STRING="-DNDEBUG" \
		-DMANPAGE_DIRECTORY:STRING="${MANPREFIX}/man/man1" \
		-DMARKDOWN_LOCATION:STRING="${LOCALBASE}/bin/markdown"

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in Changelog INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
