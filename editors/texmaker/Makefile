# ex:ts=8
# Ports collection makefile for:	texmaker
# Date created:			Dec 29, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	texmaker
PORTVERSION=	1.5
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	LaTeX Development Environment

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		xdvi:${PORTSDIR}/print/xdvik \
		gv:${PORTSDIR}/print/gv \
		xpdf:${PORTSDIR}/graphics/xpdf \
${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

USE_BZIP2=	yes
USE_GHOSTSCRIPT=yes
USE_QT_VER=	4
QT_COMPONENTS=	gui moc qmake rcc uic
HAS_CONFIGURE=	yes

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} INCLUDEPATH+=/foo/bar/ZZZZZZZZZZZZZZZ \
		LIBS+=-L/foo/bar/XXXXXXXXXXXXXXXXX texmaker.pro

.include <bsd.port.mk>
