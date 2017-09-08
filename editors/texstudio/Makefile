# $FreeBSD$

PORTNAME=	texstudio
PORTVERSION=	2.11.0
PORTREVISION=	7
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TeXstudio%20${PORTVERSION}

MAINTAINER=	abiliojr@gmail.com
COMMENT=	Integrated writing environment for LaTeX documents

LIB_DEPENDS=	libhunspell-1.6.so:textproc/hunspell \
		libpoppler.so:graphics/poppler

BROKEN_aarch64=		fails to compile: error: no member named mc_eip in __mcontext
BROKEN_armv6=		fails to compile: error: no member named mc_eip in __mcontext

USES=		desktop-file-utils dos2unix execinfo ghostscript:run \
		pkgconfig qmake
DOS2UNIX_FILES=	${PORTNAME}.pro

_USE_QT4=	corelib gui network script svg xml \
		iconengines_run designer_build moc_build rcc_build uic_build
_USE_QT5=	core gui network script svg widgets xml \
		printsupport concurrent uitools buildtools_build

USE_XORG=	x11
USE_GL=		gl
USE_TEX=	latex dvipsk

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

QMAKE_ARGS=	USE_SYSTEM_HUNSPELL=true USE_SYSTEM_QUAZIP=true

TOOLKIT_DESC=	Qt toolkit
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT4_LIB_DEPENDS=libpoppler-qt4.so:graphics/poppler-qt4 \
		libquazip.so:archivers/quazip
QT4_QMAKE_ON=	QUAZIP_INCLUDE="${LOCALBASE}/include/quazip" \
		QUAZIP_LIB="-lquazip"
QT5_USE=	${_USE_QT5:S/^/QT5=/}
QT5_LIB_DEPENDS=libpoppler-qt5.so:graphics/poppler-qt5 \
		libquazip5.so:archivers/quazip-qt5
QT5_QMAKE_ON=	QUAZIP_INCLUDE="${LOCALBASE}/include/quazip5" \
		QUAZIP_LIB="-lquazip5"

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		-e '/appdata.path/s,\/usr,${PREFIX},' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
