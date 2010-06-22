# New ports collection makefile for:	Launchy
# Date created:				28 Jul 2008
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	launchy
PORTVERSION=	2.5
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/Launchy%20on%20Linux/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source keystroke launcher

BUILD_DEPENDS=	${LOCALBASE}/include/boost/spirit/core.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils

USE_DOS2UNIX=	readme.lyx readme.txt
USE_QT_VER=	4
QT_COMPONENTS=	qmake_build moc_build rcc_build uic_build gui network
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} 's,/usr,${PREFIX},' \
		${WRKSRC}/platforms/unix/unix.pro \
		${WRKSRC}/plugins/calcy/calcy.pro \
		${WRKSRC}/plugins/gcalc/gcalc.pro \
		${WRKSRC}/plugins/runner/runner.pro \
		${WRKSRC}/plugins/verby/verby.pro \
		${WRKSRC}/plugins/weby/weby.pro \
		${WRKSRC}/src/src.pro

do-configure:
	@(cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${QMAKE} ${QMAKEFLAGS} -r Launchy.pro)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/?eadme.* ${DOCSDIR}
.endif

.include <bsd.port.mk>
