# $FreeBSD$
#
# Support Kodi Home Theater Addons
#
# Feature:	kodi
# Usage:	USES=kodi[:noautoplist]
# Valid args:	noautoplist	Don't generate the plist automatically
#
# MAINTAINER: decke@FreeBSD.org

.if !defined(_INCLUDE_USES_KODI_MK)

_INCLUDE_USES_KODI_MK=	yes

_valid_ARGS=		noautoplist

# Sanity check
.for arg in ${kodi_ARGS}
.    if empty(_valid_ARGS:M${arg})
IGNORE= Incorrect 'USES+= kodi:${kodi_ARGS}' usage: argument [${arg}] is not recognized
.    endif
.endfor

BUILD_DEPENDS+=	${LOCALBASE}/include/kodi/AddonBase.h:multimedia/kodi
LIB_DEPENDS+=	libp8-platform.so:devel/p8-platform \
		libkodiplatform.so:devel/kodi-platform
RUN_DEPENDS+=	kodi:multimedia/kodi

PKGNAMEPREFIX?=	kodi-addon-
KODI_ADDON?=	${PORTNAME}

PLIST_SUB+=	DISTVERSION="${DISTVERSION}"

.if empty(kodi_ARGS:Mnoautoplist)
_USES_install+=	820:kodi-autoplist
kodi-autoplist:
	@${FIND} -ds ${STAGEDIR}${PREFIX}/lib/kodi/addons/${KODI_ADDON} \( -type f -or -type l \) -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST}

	@if [ -d ${STAGEDIR}${PREFIX}/share/kodi/addons/${KODI_ADDON} ]; then \
		${FIND} -ds ${STAGEDIR}${PREFIX}/share/kodi/addons/${KODI_ADDON} -type f -print | ${SED} -E -e \
		's,^${STAGEDIR}${PREFIX}/?,,' >> ${TMPPLIST} ; \
	fi
.endif

.endif # !defined(_INCLUDE_USES_KODI_MK)
