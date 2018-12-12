# $FreeBSD$

PORTNAME=	qjson
DISTVERSION=	0.9.0
PORTREVISION=	3
CATEGORIES=	devel
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Library to manage JSON objects with Qt

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.lib

FLAVORS=	qt5 qt4
FLAVOR?=	${FLAVORS:[1]}

USES=		cmake pathfix
USE_GITHUB=	yes
GH_ACCOUNT=	flavio
USE_LDCONFIG=	yes

.  if ${FLAVOR} == qt4
DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES+=		qt:4
USE_QT=		corelib moc_build qmake_build rcc_build uic_build
CMAKE_ON=	QT4_BUILD
PLIST_SUB=	QT5="@comment " NO_QT5=""
.  else
USES+=		compiler:c++11-lang qt:5
USE_QT=		core buildtools_build qmake_build
CMAKE_OFF=	QT4_BUILD
PLIST_SUB=	QT5="" NO_QT5="@comment "
QT_SUFFIX=	-qt5
.  endif

_DOCSDIR=	${DOCSDIR}${QT_SUFFIX}
DOCSDIR_REL=	${_DOCSDIR:S,^${PREFIX}/,,}
PLIST_SUB+=	QT_SUFFIX="${QT_SUFFIX}" \
		PORTVERSION="${PORTVERSION}"

OPTIONS_DEFINE=	DOXYGEN
OPTIONS_SUB=	yes

DOXYGEN_BUILD_DEPENDS=	doxygen:devel/doxygen

post-build-DOXYGEN-on:
	cd ${WRKSRC}/doc && doxygen

post-install-DOXYGEN-on:
	${MKDIR} ${STAGEDIR}${_DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} . ${STAGEDIR}${_DOCSDIR}

.include <bsd.port.mk>
