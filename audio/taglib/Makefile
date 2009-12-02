# New ports collection makefile for:	taglib
# Date Created:				06 Nov 2003
# Whom:				 	Frank Laszlo <laszlof@vonostingroup.com>
#
# $FreeBSD$
#

PORTNAME=	taglib
PORTVERSION=	1.6.1
CATEGORIES=	audio
MASTER_SITES=	http://developer.kde.org/~wheeler/files/src/ \
		ftp://ftp.musicbrainz.org/${MASTER_SITE_SUBDIR}/ \
    		http://uk.musicbrainz.org/${MASTER_SITE_SUBDIR}/ \
		ftp://ftp.osuosl.org/pub/${MASTER_SITE_SUBDIR}/
MASTER_SITE_SUBDIR=	pub/musicbrainz/users/luks/${PORTNAME}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Library for manipulating ID3 tags and Ogg comments

USE_CMAKE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

CMAKE_ARGS=	-DWITH_ASF:BOOL=ON \
		-DWITH_MP4:BOOL=ON

OPTIONS=	RCC "Build with RusXMMS librcc patches (experimental)" off

.include <bsd.port.pre.mk>

.if defined(WITH_RCC)
PKGNAMESUFFIX=	-rcc
EXTRA_PATCHES+=	${FILESDIR}/extrapatch-rcc

LIB_DEPENDS+=	rcc.2:${PORTSDIR}/devel/librcc
PLIST_SUB+=	RCC=""
.else
PLIST_SUB+=	RCC="@comment "
.endif

 post-patch:
.if defined(WITH_RCC)
	@${REINPLACE_CMD} -e 's|-ltag|-ltag -lrcc|g' \
		${WRKSRC}/taglib.pc.cmake ${WRKSRC}/taglib-config.cmake \
		${WRKSRC}/bindings/c/taglib_c.pc.cmake
.endif
	${REINPLACE_CMD} -e 's|$${LIB_INSTALL_DIR}/pkgconfig|libdata/pkgconfig|' \
		${WRKSRC}/CMakeLists.txt ${WRKSRC}/bindings/c/CMakeLists.txt

.include <bsd.port.post.mk>
