# $FreeBSD$

PORTNAME=	qjson
PORTVERSION=	0.9.0
PORTREVISION?=	0
CATEGORIES=	devel

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Library to manage JSON objects with Qt

LICENSE=	LGPL21

USE_GITHUB=	yes
GH_ACCOUNT=	flavio
GH_TAGNAME=	${PORTVERSION}
USES=		cmake pathfix tar:bzip2
USE_LDCONFIG=	yes

.if empty(PKGNAMESUFFIX)
USE_QT4=	corelib moc_build qmake_build rcc_build uic_build
CMAKE_ARGS+=	-DQT4_BUILD:BOOL=TRUE
PLIST_SUB=	QT5="@comment " NO_QT5=""
.else
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

.include <bsd.port.options.mk>

post-build:
.if ${PORT_OPTIONS:MDOXYGEN}
	cd ${WRKSRC}/doc && doxygen
.endif

post-install:
.if ${PORT_OPTIONS:MDOXYGEN}
	${MKDIR} ${STAGEDIR}${_DOCSDIR}
	cd ${WRKSRC}/doc/html && ${COPYTREE_SHARE} \* ${STAGEDIR}${_DOCSDIR}
.endif

.include <bsd.port.mk>
