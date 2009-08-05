# ex:ts=8
# Ports collection makefile for:	texmaker
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texmaker
PORTVERSION=	1.9.2
PORTEPOCH=	1
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	makc@FreeBSD.org
COMMENT=	LaTeX Development Environment

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_GHOSTSCRIPT=yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
QMAKE_ARGS=	PREFIX=${PREFIX} ICONDIR=${PREFIX}/share/pixmaps \
		DESKTOPDIR=${DESKTOPDIR} -unix
MAKE_JOBS_SAFE=	yes

OPTIONS=	XDVI "view dvi with xdvi" On \
		GV "view ps with gv" On \
		XPDF "view pdf with xpdf" On

STRIP_FILES=	bin/texmaker

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XDVI)
RUN_DEPENDS+=	xdvi:${PORTSDIR}/print/xdvik
.endif

.if !defined(WITHOUT_GV)
RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv
.endif

.if !defined(WITHOUT_XPDF)
RUN_DEPENDS+=	xpdf:${PORTSDIR}/graphics/xpdf
.endif

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} ${QMAKE_ARGS} texmaker.pro

post-configure:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC .*|CC=${CC}|; s|^CXX .*|CXX=${CXX}|; s|^LINK .*|LINK=${CXX}|'

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${PREFIX}/,}

.include <bsd.port.post.mk>
