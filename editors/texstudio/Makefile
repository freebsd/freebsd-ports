# $FreeBSD$

PORTNAME=	texstudio
DISTVERSION=	2.12.22
CATEGORIES=	editors

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Integrated writing environment for LaTeX documents

LICENSE=	GPLv2

BROKEN_armv6=	fails to compile: error: no member named mc_eip in __mcontext

LIB_DEPENDS=	libhunspell-1.7.so:textproc/hunspell \
		libpoppler.so:graphics/poppler \
		libpoppler-qt5.so:graphics/poppler-qt5 \
		libquazip5.so:archivers/quazip

USES=		compiler:c++11-lang desktop-file-utils dos2unix \
		ghostscript:run gl pkgconfig qmake qt:5 xorg
USE_QT	=	core gui network script svg widgets xml \
		printsupport concurrent uitools buildtools_build
QMAKE_ARGS=	QUAZIP_INCLUDE="${LOCALBASE}/include/quazip5" \
		QUAZIP_LIB="-lquazip5"
QTVER_SUFFIX=	5

USE_XORG=	x11
USE_GL=		gl
USE_TEX=	latex dvipsk
USE_GITHUB=	yes
GH_ACCOUNT=	${PORTNAME}-org

DOS2UNIX_FILES=	${PORTNAME}.pro

QMAKE_ARGS+=	USE_SYSTEM_HUNSPELL=true USE_SYSTEM_QUAZIP=true

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		-e '/appdata.path/s,\/usr,${PREFIX},' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
