# Ports collection makefile for:	texmakerx
# Date created:			Feb 22, 2009
# Whom:				lx
#
# $FreeBSD$
#

PORTNAME=	texmakerx
PORTVERSION=	1.8.1
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	A LaTeX IDE derived from Texmaker

RUN_DEPENDS=	latex:${PORTSDIR}/print/teTeX-base \
		dvips:${PORTSDIR}/print/dvipsk-tetex \
		${LOCALBASE}/share/icons/hicolor/index.theme:${PORTSDIR}/misc/hicolor-icon-theme

WRKSRC=		${WRKDIR}/${PORTVERSION}
USE_GHOSTSCRIPT=yes
USE_QT_VER=	4
QT_COMPONENTS=	gui network xml moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
INSTALLS_ICONS=	yes

OPTIONS=	XDVI "view dvi with xdvi" On \
		GV "view ps with gv" On

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_XDVI)
RUN_DEPENDS+=	xdvi:${PORTSDIR}/print/xdvik
.endif

.if !defined(WITHOUT_GV)
RUN_DEPENDS+=	gv:${PORTSDIR}/print/gv
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^\(utilities.path =\).*,\1 ${DATADIR},' \
		${WRKSRC}/${PORTNAME}.pro

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} \
		${QMAKE} -unix PREFIX=${PREFIX} ${PORTNAME}.pro

.include <bsd.port.post.mk>
