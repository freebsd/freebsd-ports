# $FreeBSD$
#
# Support for Drupal ports and modules.
#
# Feature:	drupal
# Usage:	USES=drupal or USES=drupal:ARGS
# Valid ARGS:	module <version> theme
#
# module	The port is a drupal module
#
# MAINTAINER: ports@FreeBSD.org

.if !defined(_INCLUDE_USES_DRUPAL_Mk)
_INCLUDE_USES_DRUPAL_Mk=	yes

.if ${drupal_ARGS:M[7]}
_DRUPAL_VERSION=	${drupal_ARGS:M[7]}
.endif

VALID_VERSIONS=	7

.if ${drupal_ARGS:N[7]:Ntheme:Nmodule}
IGNORE=	Unknown argument for USES=drupal: ${drupal_ARGS:N[7]:Ntheme:Nmodule}
.endif

_DRUPAL_COMP=	${drupal_ARGS:N[7]}

.if !defined(_DRUPAL_VERSION) || ! ${VALID_VERSIONS:M${_DRUPAL_VERSION}}
IGNORE=	Missing or invalid argument for USES=drupal, a version must be provided: ${VALID_VERSIONS}
.endif

.if ${drupal_ARGS:Mmodule} && ${drupal_ARGS:Mtheme}
IGNORE=	theme and module arguments are mutually exclusive for USES=drupal
.endif

DRUPAL_BASE?=	www/drupal${_DRUPAL_VERSION}

DRUPAL_DIR=		${PREFIX}/${DRUPAL_BASE}
DRUPAL_DOCSDIR?=	${PREFIX}/${DRUPAL_BASE}/doc
PLIST_SUB+=		DRUPAL_BASE=${DRUPAL_BASE}
SUB_LIST+=		DRUPAL_BASE=${DRUPAL_BASE} DRUPAL_DIR=${DRUPAL_DIR}

.if ! ${_DRUPAL_COMP}
DOCSDIR?=	${DRUPAL_DOCSDIR}
.endif

.if ${_DRUPAL_COMP}
_USES_POST+=	drupal
PKGNAMEPREFIX=  drupal${_DRUPAL_VERSION}-

# drupal contributions must be licensed under the GPLv2 or GPLv3.  This is
# documented at: http://drupal.org/licensing/faq/
.if !defined(LICENSE)
LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
.endif

.if defined(DRUPAL_MODSUBDIR)
DRUPAL_MODDIR?=	${DRUPAL_BASE}/sites/all/${_DRUPAL_COMP}s/${DRUPAL_MODSUBDIR}
.else
DRUPAL_MODDIR?=	${DRUPAL_BASE}/sites/all/${_DRUPAL_COMP}s
.endif

DRUPAL_MODLIB?=	${DRUPAL_BASE}/sites/all/libraries

DOCSDIR?=	${DRUPAL_DOCSDIR}/${PORTNAME}

MASTER_SITE_DRUPAL+= \
	http://ftp.drupal.org/files/projects/ \
	http://ftp.osuosl.org/pub/drupal/files/projects/
MASTER_SITE_DRUPAL_SUBDIR=

MASTER_SITES?=		${MASTER_SITE_DRUPAL}
MASTER_SITE_SUBDIR?=	${MASTER_SITE_DRUPAL_SUBDIR}

DIST_SUBDIR=	drupal

NO_BUILD?=	yes

WRKSRC?=	${WRKDIR}/${PORTNAME}
RUN_DEPENDS+=	${LOCALBASE}/${DRUPAL_BASE}/index.php:${DRUPAL_BASE}

PLIST_SUB+=	DRUPAL_MODDIR=${DRUPAL_MODDIR}
PLIST_FILES+=	"@owner www" \
		"@group www" \
		${MODULE_FILES:C|^|%%DRUPAL_MODDIR%%/|} \
		"@owner root" \
		"@group wheel"
PLIST_DIRS+=	${MODULE_DIRS:C|^|%%DRUPAL_MODDIR%%/|}
.endif
.endif

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_DRUPAL_POST_MK)
_INCLUDE_USES_DRUPAL_POST_MK=	yes

.if ${_DRUPAL_COMP}
.if ${PORT_OPTIONS:MDOCS}
PLIST_FILES+=	${DOC_FILES:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	${DOC_DIRS:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

do-install:
	@${MKDIR} ${DRUPAL_MODDIR:C|^|${STAGEDIR}${PREFIX}/|}
.if defined(MODULE_DIRS)
	@${MKDIR} ${MODULE_DIRS:C|^|${STAGEDIR}${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.for f in ${MODULE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${PREFIX}/${DRUPAL_MODDIR}/${f}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${DOC_DIRS:C|^|${STAGEDIR}${DOCSDIR}/|}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/${f}
.endfor

.endif
.endif
