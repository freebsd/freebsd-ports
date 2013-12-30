# Created by: lx
# $FreeBSD$

PORTNAME=	texmakerx
PORTVERSION=	2.1
PORTREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TexMakerX%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S:.0::}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	LaTeX IDE derived from Texmaker

LIB_DEPENDS=	libpoppler.so:${PORTSDIR}/graphics/poppler \
		libpoppler-qt4.so:${PORTSDIR}/graphics/poppler-qt4

WRKSRC=	${WRKDIR}/${PORTNAME}${PORTVERSION}

USES=		dos2unix qmake
USE_GHOSTSCRIPT_RUN=	yes
USE_QT4=	gui network xml moc_build rcc_build \
		uic_build qtestlib script
USE_TEX=	latex dvipsk
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	XDVI GV
GV_DESC=	View ps files with gv
GV_RUN_DEPENDS=	xdvi:${PORTSDIR}/print/xdvik
XDVI_DESC=	View dvi files with xdvi
XDVI_RUN_DEPENDS=	gv:${PORTSDIR}/print/gv

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		${WRKSRC}/${PORTNAME}.pro

.include <bsd.port.mk>
