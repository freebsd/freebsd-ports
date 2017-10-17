# Created by: admin@mjbrune.org
# $FreeBSD$

PORTNAME=	textroom
PORTVERSION=	0.8.2
PORTREVISION=	11
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Full screen text editor

LICENSE=	GPLv3

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libhunspell-1.6.so:textproc/hunspell \
		libxml++-2.6.so:textproc/libxml++26

USES=		compiler:c++11-lang desktop-file-utils pkgconfig qmake
USE_CXXSTD=	c++11
USE_GL=		gl
USE_SDL=	mixer
USE_QT4=	moc_build rcc_build uic_build \
		corelib gui opengl qt3support svg xml

post-patch:
.for i in getaword.cpp optionsdialog.cpp textroom.cpp
	@${REINPLACE_CMD} -e \
		's|/usr/share|${PREFIX}/share|' ${WRKSRC}/application/src/${i}
.endfor

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/textroom

.include <bsd.port.mk>
