# New ports collection makefile for:	pysycache-lang
# Date created:		2006-02-22
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	lang
PORTVERSION=	2.0
CATEGORIES=	games python
MASTER_SITES=	http://download.gna.org/py4childs/pysycache/v${PORTVERSION}/
PKGNAMEPREFIX=	pysycache-
DISTFILES=	#
DIST_SUBDIR=	pysycache

MAINTAINER=	acardenas@bsd.org.pe
COMMENT=	The pysycache lang support

RUN_DEPENDS=	pysycache.py:${PORTSDIR}/games/pysycache

USE_ZIP=	yes
USE_X_PREFIX=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
DATADIR=	${PREFIX}/share/${DIST_SUBDIR}

OPTIONS=	FRENCH	"French language support"	on \
		GERMAN	"German language support"	on \
		ITALIAN	"Italian language support"	on \
		PORTUGUESE	"Portuguese language support"	on \
		SPANISH	"Spanish language support"	on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_FRENCH)
DISTFILES+=	pysycache-lang-fr-${PORTVERSION}.zip
PLIST_SUB+=	FRENCH=""
FLAG_LANG=	true
HAVE_LANG+=	fr
.else
PLIST_SUB+=	FRENCH="@comment "
.endif

.if !defined(WITHOUT_GERMAN)
DISTFILES+=	pysycache-lang-de-${PORTVERSION}.zip
PLIST_SUB+=	GERMAN=""
FLAG_LANG=	true
HAVE_LANG+=	de
.else
PLIST_SUB+=	GERMAN="@comment "
.endif

.if !defined(WITHOUT_ITALIAN)
DISTFILES+=	pysycache-lang-it-${PORTVERSION}.zip
PLIST_SUB+=	ITALIAN=""
FLAG_LANG=	true
HAVE_LANG+=	it
.else
PLIST_SUB+=	ITALIAN="@comment "
.endif

.if !defined(WITHOUT_PORTUGUESE)
DISTFILES+=	pysycache-lang-pt-${PORTVERSION}.zip
PLIST_SUB+=	PORTUGUESE=""
FLAG_LANG=	true
HAVE_LANG+=	pt
.else
PLIST_SUB+=	PORTUGUESE="@comment "
.endif

.if !defined(WITHOUT_SPANISH)
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

.include <bsd.port.post.mk>
