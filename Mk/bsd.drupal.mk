#-*- mode: makefile; tab-width: 4; -*-
# ex:ts=4
#
# $FreeBSD$
#
# bsd.drupal.mk - Support for Drupal ports and modules.
#
# For FreeBSD committers:
# Please send all suggested changes to the maintainer instead of committing
# them to SVN yourself.

bsd_drupal_mk_MAINTAINER=       miwi@FreeBSD.org

# Make sure we cannot define any combination of DRUPAL{5,6}
.if (defined(DRUPAL5_MODULE) && defined(DRUPAL6_MODULE))
BROKEN=		cannot define a combination of DRUPAL5_MODULE and DRUPAL6_MODULE
.endif

.if (defined(DRUPAL5_THEME) && defined(DRUPAL6_THEME))
BROKEN=		cannot define a combination of DRUPAL5_THEME and DRUPAL6_THEME
.endif

.if defined(DRUPAL6_MODULE) || defined(DRUPAL6_PORT)  || defined(DRUPAL6_THEME)
DRUPAL_VERSION?=	6
.endif

.if !defined(DRUPAL_VERSION)
BROKEN=		must define DRUPAL_VERSION
.endif

# Make sure DRUPAL_MODULE is defined where necessary
.if defined(DRUPAL5_MODULE) || defined(DRUPAL6_MODULE)
DRUPAL_MODULE?=	yes
.endif

.if defined(DRUPAL_MODULE)
DRUPAL_MODTYPE=	modules
.endif

# Make sure DRUPAL_PORT is defined where necessary
.if defined(DRUPAL5_PORT) || defined(DRUPAL6_PORT)
DRUPAL_PORT?=	yes
.endif

# Make sure DRUPAL_THEME is defined where necessary
.if defined(DRUPAL5_THEME) || defined(DRUPAL6_THEME)
DRUPAL_THEME?=	yes
DRUPAL_MODTYPE=	themes
.endif

.if ${DRUPAL_VERSION} == "7"
DRUPAL_BASE?=   www/drupal7
.elif ${DRUPAL_VERSION} == "6"
DRUPAL_BASE?=   www/drupal6
.else
BROKEN=		Unknown DRUPAL_VERSION (${DRUPAL_VERSION})
.endif

DRUPAL_DIR=	${PREFIX}/${DRUPAL_BASE}
DRUPAL_DOCSDIR?=	${PREFIX}/${DRUPAL_BASE}/doc
PLIST_SUB+=	DRUPAL_BASE=${DRUPAL_BASE}
SUB_LIST+=	DRUPAL_BASE=${DRUPAL_BASE} DRUPAL_DIR=${DRUPAL_DIR}

.if defined(DRUPAL_PORT)
DOCSDIR?=	${DRUPAL_DOCSDIR}
.endif

.if defined(DRUPAL_MODULE) || defined (DRUPAL_THEME)
PKGNAMEPREFIX=  drupal${DRUPAL_VERSION}-

# drupal contributions must be licensed under the GPLv2 or GPLv3.  This is
# documented at: http://drupal.org/licensing/faq/
.if !defined(LICENSE)
LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual
.endif

.if defined(DRUPAL_MODSUBDIR)
DRUPAL_MODDIR?= ${DRUPAL_BASE}/sites/all/${DRUPAL_MODTYPE}/${DRUPAL_MODSUBDIR}
.else
DRUPAL_MODDIR?= ${DRUPAL_BASE}/sites/all/${DRUPAL_MODTYPE}/${PORTNAME}
.endif

DRUPAL_MODLIB?=	${DRUPAL_BASE}/sites/all/libraries

DOCSDIR?=	${DRUPAL_DOCSDIR}/${PORTNAME}

.if defined(DRUPAL_MOD_SNAPSHOT)
MASTER_SITE_DRUPAL+= \
	${MASTER_SITE_LOCAL}
MASTER_SITE_DRUPAL_SUBDIR=	pav/drupal
.else
MASTER_SITE_DRUPAL+= \
	http://ftp.drupal.org/files/projects/ \
	http://ftp.osuosl.org/pub/drupal/files/projects/
MASTER_SITE_DRUPAL_SUBDIR=
.endif

MASTER_SITES?=	${MASTER_SITE_DRUPAL}
MASTER_SITE_SUBDIR?=	${MASTER_SITE_DRUPAL_SUBDIR}

DIST_SUBDIR=	drupal

NO_BUILD?=	yes

WRKSRC?=	${WRKDIR}/${PORTNAME}
RUN_DEPENDS+=	${LOCALBASE}/${DRUPAL_BASE}/index.php:${PORTSDIR}/${DRUPAL_BASE}

.if defined(MODULE_CONF_FILES)
SUB_FILES=	pkg-install
SUB_LIST+=	CONF_FILES="${MODULE_CONF_FILES:C|^|${DRUPAL_MODDIR}/|}" \
		CONF_DIRS="${MODULE_CONF_DIRS:C|^|${DRUPAL_MODDIR}/|}"
# XXX: where?
PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${PKGINSTALL}
.endif

PLIST_SUB+=	DRUPAL_MODDIR=${DRUPAL_MODDIR}
PLIST_FILES+=	${MODULE_FILES:C|^|%%DRUPAL_MODDIR%%/|}
PLIST_FILES+=	${MODULE_CONF_FILES:C|^|%%DRUPAL_MODDIR%%/|:C|$|-dist|}
PLIST_DIRS+=	${MODULE_DIRS:C|^|%%DRUPAL_MODDIR%%/|}
.if defined(DRUPAL_MODULE) || defined(DRUPAL_THEME)
PLIST_DIRS+=	${DRUPAL_MODDIR}
.endif
.if defined(DRUPAL_MODSUBDIR)
PLIST_DIRS+=	${DRUPAL_MODDIR}
.endif
.if !defined(NOPORTDOCS)
PLIST_FILES+=	${DOC_FILES:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	${DOC_DIRS:C|^|%%DOCSDIR%%/|}
PLIST_DIRS+=	%%DOCSDIR%%
.endif

do-install:
.if defined(DRUPAL_MODULE) || defined(DRUPAL_THEME)
	@${MKDIR} ${DRUPAL_MODDIR:C|^|${PREFIX}/|}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${DRUPAL_MODDIR:C|^|${PREFIX}/|}
.endif
.if defined(MODULE_CONF_DIRS)
	@${MKDIR} ${MODULE_CONF_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${MODULE_CONF_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.if defined(MODULE_DIRS)
	@${MKDIR} ${MODULE_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${MODULE_DIRS:C|^|${PREFIX}/${DRUPAL_MODDIR}/|}
.endif
.for f in ${MODULE_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPAL_MODDIR}/${f}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DRUPAL_MODDIR}/${f}
.endfor
.for f in ${MODULE_CONF_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/${DRUPAL_MODDIR}/${f}-dist
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${DRUPAL_MODDIR}/${f}-dist
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${DOC_DIRS:C|^|${DOCSDIR}/|}
.for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
.endfor
.endif

.if defined(MODULE_CONF_FILES)
post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif
.endif
