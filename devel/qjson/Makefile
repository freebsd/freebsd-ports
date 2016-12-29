# $FreeBSD$

PORTNAME=	qjson
PORTVERSION=	0.9.0
PORTREVISION?=	0
CATEGORIES=	devel

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library to manage JSON objects with Qt

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.lib

USE_GITHUB=	yes
GH_ACCOUNT=	flavio
GH_TAGNAME=	${PORTVERSION}
USES=		cmake pathfix
USE_LDCONFIG=	yes

.if empty(PKGNAMESUFFIX)
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
CMAKE_ARGS+=	-DQT4_BUILD:BOOL=TRUE
PLIST_SUB=	QT5="@comment " NO_QT5=""
.else
PORTSCOUT=	ignore:1

USE_QT5=	core buildtools_build qmake_build
CMAKE_ARGS+=	-DQT4_BUILD:BOOL=FALSE
PLIST_SUB=	QT5="" NO_QT5="@comment "
QT_SUFFIX=	-qt5
.endif

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
