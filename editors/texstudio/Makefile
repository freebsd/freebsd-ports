# $FreeBSD$

PORTNAME=	texstudio
PORTVERSION=	2.8.8
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TeXstudio%20${PORTVERSION}

MAINTAINER=	abiliojr@gmail.com
COMMENT=	Integrated writing environment for creating LaTeX documents

LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler \
		libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

USES=		desktop-file-utils dos2unix execinfo pkgconfig qmake
DOS2UNIX_FILES=	${PORTNAME}.pro
USE_GHOSTSCRIPT_RUN=	yes
USE_QT4=	gui network script svg xml iconengines_run \
		designer_build moc_build rcc_build uic_build
USE_TEX=	latex dvipsk
INSTALLS_ICONS=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		-e '/appdata.path/s,\/usr,${PREFIX},' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
