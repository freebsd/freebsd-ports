# Created by: lx
# $FreeBSD$

PORTNAME=	texmakerx
PORTVERSION=	2.1
PORTREVISION=	4
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TexMakerX%20${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION:S:.0::}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A LaTeX IDE derived from Texmaker

LIB_DEPENDS=	poppler:${PORTSDIR}/graphics/poppler \
		poppler-qt4:${PORTSDIR}/graphics/poppler-qt4
RUN_DEPENDS=	${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

WRKSRC=	${WRKDIR}/${PORTNAME}${PORTVERSION}

USE_GHOSTSCRIPT=yes
USE_QT4=	gui network xml moc_build qmake_build rcc_build \
		uic_build qtestlib script
USE_TEX=	latex dvipsk
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	XDVI GV
GV_DESC=	View ps files with gv
XDVI_DESC=	View dvi files with xdvi

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXDVI}
RUN_DEPENDS+=	xdvi:${PORTSDIR}/print/xdvik
.endif

.if ${PORT_OPTIONS:MGV}
RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		-e 's,/usr/include,${LOCALBASE}/include,g' \
		-e 's,/usr/lib,${LOCALBASE}/lib,g' \
		${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} PREFIX=${PREFIX} ${PORTNAME}.pro

.include <bsd.port.mk>
