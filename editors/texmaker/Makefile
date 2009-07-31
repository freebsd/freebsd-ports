# ex:ts=8
# Ports collection makefile for:	texmaker
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texmaker
PORTVERSION=	1.8
PORTREVISION=	1
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
QT_COMPONENTS=	gui network moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS=	XDVI "view dvi with xdvi" On \
		GV "view ps with gv" On \
		XPDF "view pdf with xpdf" On

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

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		${WRKSRC}/texmaker.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} texmaker.pro

.include <bsd.port.post.mk>
