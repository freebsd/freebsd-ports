# $FreeBSD$

PORTNAME=	qsvn
DISTVERSION=	0.8.1
DISTVERSIONSUFFIX=	-src
PORTREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	http://www.anrichter.net/projects/qsvn/chrome/site/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Qt based GUI frontend for Subversion

LIB_DEPENDS=	libsvn_client-1.so:${PORTSDIR}/devel/subversion

IGNORE=		does not support Subversion 1.9
DEPRECATED=	Development discontinued since 2009
EXPIRATION_DATE=	2015-11-23

USE_QT4=	gui sql moc_build uic_build rcc_build qmake_build
USE_LDCONFIG=	yes
USES=		cmake

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src

DESKTOP_ENTRIES="QSvn" "SVN client" "${PREFIX}/share/pixmaps/qsvn.png" \
		"qsvn" "Development;RevisionControl;Qt;" true

SVNQT_INCLUDE_DIR=	include/svnqt4
PLIST_SUB=	SVNQT_INCLUDE_DIR="${SVNQT_INCLUDE_DIR}"

pre-configure:
	${REINPLACE_CMD} -e 's,include/svnqt,${SVNQT_INCLUDE_DIR},g' \
		${WRKSRC}/svnqt/CMakeLists.txt
	${REINPLACE_CMD} -e 's,/usr/local,${LOCALBASE},g' \
		${WRKSRC}/svnqt/cmakemodules/FindSubversion.cmake

post-install:
	${INSTALL_DATA} ${WRKSRC}/images/qsvn.png ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
