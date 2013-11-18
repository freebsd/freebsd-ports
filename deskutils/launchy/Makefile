# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	launchy
PORTVERSION=	2.5
PORTREVISION=	1
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/Launchy%20on%20Linux/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source keystroke launcher

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/bin/xdg-open:${PORTSDIR}/devel/xdg-utils

USES=		dos2unix qmake
DOS2UNIX_FILES=	readme.lyx readme.txt
USE_QT4=	qmake_build moc_build rcc_build uic_build gui network
PORTDOCS=	*

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} 's,/usr,${PREFIX},' \
		${WRKSRC}/platforms/unix/unix.pro \
		${WRKSRC}/plugins/calcy/calcy.pro \
		${WRKSRC}/plugins/gcalc/gcalc.pro \
		${WRKSRC}/plugins/runner/runner.pro \
		${WRKSRC}/plugins/verby/verby.pro \
		${WRKSRC}/plugins/weby/weby.pro \
		${WRKSRC}/src/src.pro

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/?eadme.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
