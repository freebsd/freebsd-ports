# $FreeBSD$

PORTNAME=	texstudio
DISTVERSION=	2.12.8
CATEGORIES=	editors
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	abiliojr@gmail.com
COMMENT=	Integrated writing environment for LaTeX documents

LICENSE=	GPLv2

BROKEN_aarch64=		fails to compile: error: no member named mc_eip in __mcontext
BROKEN_armv6=		fails to compile: error: no member named mc_eip in __mcontext

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell \
		libpoppler.so:graphics/poppler

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

qt4_DEPRECATED=		Qt4 has been EOL since december 2015
qt4_EXPIRATION_DATE=	2019-03-15

qt4_LIB_DEPENDS=	libpoppler-qt4.so:graphics/poppler-qt4 \
			libquazip.so:archivers/quazip@qt4
qt5_LIB_DEPENDS=	libpoppler-qt5.so:graphics/poppler-qt5 \
			libquazip5.so:archivers/quazip@qt5

USES=		desktop-file-utils dos2unix ghostscript:run \
		pkgconfig qmake

.if ${FLAVOR} == qt4
USES+=		qt:4
USE_QT=		corelib gui network script svg xml \
		iconengines_run designer_build moc_build rcc_build uic_build
QMAKE_ARGS=	QUAZIP_INCLUDE="${LOCALBASE}/include/quazip" \
		QUAZIP_LIB="-lquazip"
.else
USES+=		qt:5
USE_QT	=	core gui network script svg widgets xml \
		printsupport concurrent uitools buildtools_build
QMAKE_ARGS=	QUAZIP_INCLUDE="${LOCALBASE}/include/quazip5" \
		QUAZIP_LIB="-lquazip5"
QTVER_SUFFIX=	5
.endif

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
