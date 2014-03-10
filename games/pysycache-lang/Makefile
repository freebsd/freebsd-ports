# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	lang
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/py4childs/pysycache/v${PORTVERSION}/
PKGNAMEPREFIX=	pysycache-
DISTFILES=	#
DIST_SUBDIR=	pysycache

MAINTAINER=	acm@FreeBSD.org
COMMENT=	The pysycache lang support

RUN_DEPENDS=	pysycache.py:${PORTSDIR}/games/pysycache

USES=		zip:infozip
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${DIST_SUBDIR}

OPTIONS_DEFINE=	FRENCH GERMAN ITALIAN PORTUGUESE SPANISH
FRENCH_DESC=	French language support
GERMAN_DESC=	German language support
ITALIAN_DESC=	Italian language support
PORTUGUESE_DESC=	Portuguese language support
SPANISH_DESC=	Spanish language support

OPTIONS_DEFAULT=	FRENCH GERMAN ITALIAN PORTUGUESE SPANISH

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFRENCH}
DISTFILES+=	pysycache-lang-fr-${PORTVERSION}.zip
PLIST_SUB+=	FRENCH=""
FLAG_LANG=	true
HAVE_LANG+=	fr
.else
PLIST_SUB+=	FRENCH="@comment "
.endif

.if ${PORT_OPTIONS:MGERMAN}
DISTFILES+=	pysycache-lang-de-${PORTVERSION}.zip
PLIST_SUB+=	GERMAN=""
FLAG_LANG=	true
HAVE_LANG+=	de
.else
PLIST_SUB+=	GERMAN="@comment "
.endif

.if ${PORT_OPTIONS:MITALIAN}
DISTFILES+=	pysycache-lang-it-${PORTVERSION}.zip
PLIST_SUB+=	ITALIAN=""
FLAG_LANG=	true
HAVE_LANG+=	it
.else
PLIST_SUB+=	ITALIAN="@comment "
.endif

.if ${PORT_OPTIONS:MPORTUGUESE}
DISTFILES+=	pysycache-lang-pt-${PORTVERSION}.zip
PLIST_SUB+=	PORTUGUESE=""
FLAG_LANG=	true
HAVE_LANG+=	pt
.else
PLIST_SUB+=	PORTUGUESE="@comment "
.endif

.if ${PORT_OPTIONS:MSPANISH}
DISTFILES+=	pysycache-lang-es-${PORTVERSION}.zip
PLIST_SUB+=	SPANISH=""
FLAG_LANG=	true
HAVE_LANG+=	es
.else
PLIST_SUB+=	SPANISH="@comment "
.endif

pre-fetch:
.if defined(FLAG_LANG)
	@${TRUE}
.else
	@${ECHO} "################################"
	@${ECHO} "#                              #"
	@${ECHO} "# No language support selected #"
	@${ECHO} "#                              #"
	@${ECHO} "################################"
	@${FALSE}
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
.for OPT in ${HAVE_LANG}
	@${UNZIP_CMD} -q ${_DISTDIR}/pysycache-lang-${OPT}-${PORTVERSION}.zip -d ${WRKSRC}
.endfor

do-install:
	@cd ${WRKSRC} && \
		${FIND} * -type d -exec ${MKDIR} "${DATADIR}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DATADIR}/{}" \;

.include <bsd.port.mk>
