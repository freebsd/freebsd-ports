# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	lang
PORTVERSION=	2.0
PORTREVISION=	7
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/py4childs/pysycache/v${PORTVERSION}/
PKGNAMEPREFIX=	pysycache-
DISTFILES=	#
DIST_SUBDIR=	pysycache

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The pysycache lang support

RUN_DEPENDS=	pysycache.py:games/pysycache

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${DIST_SUBDIR}

OPTIONS_MULTI=	LANG
OPTIONS_MULTI_LANG=	FRENCH GERMAN ITALIAN PORTUGUESE SPANISH
OPTIONS_DEFAULT=	FRENCH GERMAN ITALIAN PORTUGUESE SPANISH

FRENCH_DESC=	French language support
GERMAN_DESC=	German language support
ITALIAN_DESC=	Italian language support
PORTUGUESE_DESC=	Portuguese language support
SPANISH_DESC=	Spanish language support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFRENCH}
DISTFILES+=	pysycache-lang-fr-${PORTVERSION}.zip
PLIST_SUB+=	FRENCH=""
HAVE_LANG+=	fr
.else
PLIST_SUB+=	FRENCH="@comment "
.endif

.if ${PORT_OPTIONS:MGERMAN}
DISTFILES+=	pysycache-lang-de-${PORTVERSION}.zip
PLIST_SUB+=	GERMAN=""
HAVE_LANG+=	de
.else
PLIST_SUB+=	GERMAN="@comment "
.endif

.if ${PORT_OPTIONS:MITALIAN}
DISTFILES+=	pysycache-lang-it-${PORTVERSION}.zip
PLIST_SUB+=	ITALIAN=""
HAVE_LANG+=	it
.else
PLIST_SUB+=	ITALIAN="@comment "
.endif

.if ${PORT_OPTIONS:MPORTUGUESE}
DISTFILES+=	pysycache-lang-pt-${PORTVERSION}.zip
PLIST_SUB+=	PORTUGUESE=""
HAVE_LANG+=	pt
.else
PLIST_SUB+=	PORTUGUESE="@comment "
.endif

.if ${PORT_OPTIONS:MSPANISH}
DISTFILES+=	pysycache-lang-es-${PORTVERSION}.zip
PLIST_SUB+=	SPANISH=""
HAVE_LANG+=	es
.else
PLIST_SUB+=	SPANISH="@comment "
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
.for OPT in ${HAVE_LANG}
	@${UNZIP_CMD} -q ${_DISTDIR}/pysycache-lang-${OPT}-${PORTVERSION}.zip -d ${WRKSRC}
.endfor

do-install:
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>
