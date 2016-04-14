# $FreeBSD$

PORTNAME=	texstudio
PORTVERSION=	2.10.8
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TeXstudio%20${PORTVERSION}

MAINTAINER=	abiliojr@gmail.com
COMMENT=	Integrated writing environment for LaTeX documents

LIB_DEPENDS=	libpoppler.so:graphics/poppler

USES=		desktop-file-utils dos2unix execinfo ghostscript:run \
		pkgconfig qmake
DOS2UNIX_FILES=	${PORTNAME}.pro

_USE_QT4=	gui network script svg xml \
		iconengines_run designer_build moc_build rcc_build uic_build
_USE_QT5=	gui network script svg xml \
		printsupport concurrent uitools buildtools_build

USE_TEX=	latex dvipsk

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

OPTIONS_SINGLE=		TOOLKIT
OPTIONS_SINGLE_TOOLKIT=	QT4 QT5
OPTIONS_DEFAULT=	QT5

TOOLKIT_DESC=	Qt toolkit
QT4_USE=	${_USE_QT4:S/^/QT4=/}
QT4_LIB_DEPENDS=libpoppler-qt4.so:graphics/poppler-qt4
QT5_USE=	${_USE_QT5:S/^/QT5=/}
QT5_LIB_DEPENDS=libpoppler-qt5.so:graphics/poppler-qt5

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		-e '/appdata.path/s,\/usr,${PREFIX},' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
