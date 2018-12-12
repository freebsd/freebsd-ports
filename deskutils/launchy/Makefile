# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	launchy
PORTVERSION=	2.5
PORTREVISION=	11
CATEGORIES=	deskutils
MASTER_SITES=	SF/${PORTNAME}/Launchy%20on%20Linux/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source keystroke launcher

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs
RUN_DEPENDS=	${LOCALBASE}/bin/xdg-open:devel/xdg-utils

USES=		dos2unix qmake qt:4
DOS2UNIX_FILES=	readme.lyx readme.txt
USE_QT=		moc_build rcc_build uic_build gui network
LDFLAGS+=	-lX11
PORTDOCS=	*

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's,/usr,${PREFIX},' \
		${WRKSRC}/platforms/unix/unix.pro \
		${WRKSRC}/plugins/calcy/calcy.pro \
		${WRKSRC}/plugins/gcalc/gcalc.pro \
		${WRKSRC}/plugins/runner/runner.pro \
		${WRKSRC}/plugins/verby/verby.pro \
		${WRKSRC}/plugins/weby/weby.pro \
		${WRKSRC}/src/src.pro

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/?eadme.* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
