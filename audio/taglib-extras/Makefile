# New ports collection makefile for:	taglib-extras
# Date created:			Thu Aug 14 12:50:02 EDT 2008
# Whom:				Matt Tosto <datahead4@gmail.com>
#
# $FreeBSD$

PORTNAME=	taglib-extras
PORTVERSION=	0.1.6
CATEGORIES=	audio
MASTER_SITES=	http://www.kollide.net/~jefferai/

MAINTAINER=	datahead4@gmail.com
COMMENT=	Extra taglib features for Amarok 2.1

LIB_DEPENDS=	tag.6:${PORTSDIR}/audio/taglib

USE_KDE4=	automoc4 kdehier
USE_QT_VER=	4
QT_COMPONENTS=	corelib qmake_build moc_build rcc_build uic_build phonon
USE_CMAKE=	yes

OPTIONS=	KDE4_MIME "Resolve file types with KMimeTypeResolve" ON

.include <bsd.port.pre.mk>

.if defined(WITHOUT_KDE4_MIME)
CMAKE_ARGS+=	-DWITH_KDE:BOOL=Off
.else
USE_KDE4+=		kdelibs
CMAKE_ARGS+=	-DWITH_KDE:BOOL=On
.endif

post-extract:
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt

.include <bsd.port.post.mk>
