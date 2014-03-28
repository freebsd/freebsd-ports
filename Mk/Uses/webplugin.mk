# $FreeBSD$
#
# Documentation and examples:
#
# Feature:	webplugin
# Usage:	USES=webplugin or USES=webplugin:ARGS
# Valid ARGS:	gecko: Support geko based plugings
# 		native: Support gecko, opera, webkit-gtk*
# 		linux: Support linux plugins
# 		[list of indivudual engines]: specify browsers to use
# 		all: All browser (implicit, default)
#
# USES=webplugin will create symlinks automatically for each supported
# application that supports the webplugin framework.  Also, it will remove
# these symlinks when the plug-in port is uninstalled.
#
# WEBPLUGIN_NAME	- If your port installs files in ${WEBPLUGIN_DIR},
# 			  then you can tweak WEBPLUGIN_NAME to change the
# 			  name of the directory
# 			  (lib/browser_plugins/symlinks/WEBPLUGIN_NAME).
#			  Default: WEBPLUGIN_NAME=${PKGBASE}
#
# WEBPLUGIN_FILES	- The plug-in files that are going to be linked
#			  in lib/browser_plugins/symlinks/*/. It cannot
#			  be empty or the port will set IGNORE.
#
# WEBPLUGIN_DIR	- The directory where the plug-in file(s) can be
# 			  found.  Each plug-in file in WEBPLUGIN_FILES
# 			  must be found in WEBPLUGIN_DIR.  If your port
# 			  does not install in WEBPLUGIN_DIR, but in its own
# 			  path, you will need to specify that here or
# 			  symlinks will be created to non-existent files.
#			  Default: WEBPLUGIN_DIR=${_WEBPLUGIN_LIBDIR:S,^${LOCALBASE}/,${PREFIX}/,}/${WEBPLUGIN_NAME}
#
#	Makefile:
#	------------------------------------------------------
#	USES=	webplugin:gecko
#	[...]
#	WEBPLUGIN_FILES=fooplugin.so fooplugin.xpi
#
#	post-install:
#		${MKDIR} ${STAGEDIR}${WEBPLUGIN_DIR}
#		${INSTALL_DATA} ${WEBPLUGIN_FILES:S,^,${WRKSRC}/plugins/,} \
#			${STAGEDIR}${WEBPLUGIN_DIR}
#
#	.include <bsd.port.mk>
#	------------------------------------------------------
#
# You do not need to add lib/browser_plugins and lib/browser_plugins/symlinks
# in pkg-plist, because they will be removed automatically.
#
#	pkg-plist:
#	------------------------------------------------------
#	[...]
#	%%WEBPLUGIN_DIR%%/fooplugin.so
#	%%WEBPLUGIN_DIR%%/fooplugin.xpi
#	@dirrmtry %%WEBPLUGIN_DIR%%
#	------------------------------------------------------
#
# Here is what it will look like when it creates the symlinks:
#
#	------------------------------------------------------
#	/usr/local/lib/browser_plugins/symlinks/gecko/fooplugin.so -> /usr/local/lib/browser_plugins/application/fooplugin.so
#	/usr/local/lib/browser_plugins/symlinks/gecko/fooplugin.xpi -> /usr/local/lib/browser_plugins/application/fooplugin.xpi
#	------------------------------------------------------
#
# If your port uses libtool, and installs any *.a and *.la files, do not add
# these files to WEBPLUGIN_FILES.  WEBPLUGIN_FILES should be *.so or/and
# *.xpi ONLY.
#
# Example to add in Makefile and pkg-plist if your port installs plug-ins in
# its own directory, and you need to set WEBPLUGIN_DIR.
#
#	Makefile:
#	------------------------------------------------------
#	[...]
# 	USES=	webplugin:gecko
#	WEBPLUGIN_DIR=${PREFIX}/lib/application
#	WEBPLUGIN_FILES=fooplugin.so fooplugin.xpi
#
#	[...]
#
#	.include <bsd.port.mk>
#	------------------------------------------------------
#
# As for the pkg-plist, it should only include the actual files your
# port installs:
#
#	pkg-plist:
#	------------------------------------------------------
#	[...]
#	lib/application/fooplugin.a
#	lib/application/fooplugin.la
#	lib/application/fooplugin.so
#	lib/application/fooplugin.xpi
#	@dirrm lib/application
#	------------------------------------------------------
#
# Here is what it will look like when it creates symlinks:
#
#	------------------------------------------------------
#	/usr/local/lib/browser_plugins/symlinks/gecko/fooplugin.so -> /usr/local/lib/application/fooplugin.so
#	/usr/local/lib/browser_plugins/symlinks/gecko/fooplugin.xpi -> /usr/local/lib/application/fooplugin.xpi
#	------------------------------------------------------
#
# MAINTAINER= gecko@FreeBSD.org

.if !defined(_INCLUDE_USES_WEBPLUGIN_MK)
_INCLUDE_USES_WEBPLUGIN_MK=	yes

WEBPLUGIN_NAME?=		${PKGBASE}
_WEBPLUGIN_APPS_ALL_LINUX=	linux-firefox linux-opera linux-opera-devel \
				linux-seamonkey
_WEBPLUGIN_APPS_ALL_NATIVE=	gecko opera opera-devel webkit-gtk2
_WEBPLUGIN_APPS_ALL=		${_WEBPLUGIN_APPS_ALL_LINUX} \
				${_WEBPLUGIN_APPS_ALL_NATIVE}

webplugin_ARGS?=	all
_WEBPLUGIN_ARGS=	${webplugin_ARGS:C/,/ /}
_WEBPLUGIN_TEST=	${_WEBPLUGIN_APPS_ALL}
.if ${_WEBPLUGIN_ARGS} == all
_WEBPLUGIN_PATTERN=	*
.elif ${_WEBPLUGIN_ARGS} == native
_WEBPLUGIN_PATTERN=	*
_WEBPLUGIN_TEST=	${_WEBPLUGIN_APPS_ALL_NATIVE}
.elif ${_WEBPLUGIN_ARGS} == linux
_WEBPLUGIN_PATTERN=	*
_WEBPLUGIN_TEST=	${_WEBPLUGIN_APPS_ALL_LINUX}
.else
_WEBPLUGIN_PATTERN=	${_WEBPLUGIN_ARGS}
.endif

.if !defined(WEBPLUGIN_FILES)
IGNORE=	Cannot be installed: WEBPLUGIN_FILES is empty. Please, add plug-in files to it
.endif

.for _TEMP_APP__ in ${_WEBPLUGIN_APPS_ALL}
_TEMP_APP_=${_TEMP_APP__}
_TEMP_FLAG_=0
.	for _TEMP_USE__ in ${USE_webplugin}
_TEMP_USE_=${_TEMP_USE__}
.		if !${_TEMP_APP_:C!${_TEMP_USE_:S/*/.*/:S/?/./}!!} || \
		( ${_TEMP_APP_:Mlinux-*} && ${_TEMP_USE_:Mlinux} ) || \
		( ${_TEMP_APP_:Nlinux-*} && ${_TEMP_USE_:Mnative} )
_TEMP_FLAG_=1
.		endif
.	endfor
.	if	${_TEMP_FLAG_}
USE_WEBPLUGIN_EXP+=	${_TEMP_APP__}
.	endif
.endfor

.for p in ${_WEBPLUGIN_PATTERN}
_WEBPLUGIN_MATCHED+=	${_WEBPLUGIN_TEST:M${p}}
.endfor

_WEBPLUGIN_LIBDIR=		${LOCALBASE}/lib/browser_plugins
_WEBPLUGIN_SLDIR=		${_WEBPLUGIN_LIBDIR}/symlinks

_WEBPLUGIN_SLDIRS=	${_WEBPLUGIN_MATCHED:S.^.${_WEBPLUGIN_SLDIR}/.}

_WEBPLUGIN_APPS=		${USE_WEBPLUGIN_EXP:S.^.${LOCALBASE}/lib/.:S.$./plugins.:N*opera*:N*gecko*:N*webkit*}
_WEBPLUGIN_LINKFARMS=	${_WEBPLUGIN_APPS} ${_WEBPLUGIN_SLDIRS}

WEBPLUGIN_DIR?=		${_WEBPLUGIN_LIBDIR:S,^${LOCALBASE}/,${PREFIX}/,}/${WEBPLUGIN_NAME}

PLIST_SUB+=		WEBPLUGIN_DIR="${WEBPLUGIN_DIR:S,^${PREFIX}/,,}"

webplugin-post-install:
	@${ECHO_CMD} "@cwd ${LOCALBASE}" >> ${TMPPLIST}
.for d in ${_WEBPLUGIN_LINKFARMS}
	${INSTALL} -d ${STAGEDIR}${d}
.for l in ${WEBPLUGIN_FILES}
	${LN} -sf ${l:S,^,${WEBPLUGIN_DIR}/,} ${STAGEDIR}${d}/
	@${ECHO_CMD} "${d:S,^${LOCALBASE}/,,}/${l:T}" >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@unexec rmdir ${d:S,^${LOCALBASE},%D,} 2>/dev/null || true" >> ${TMPPLIST}
.endfor
	@${ECHO_CMD} "@unexec rmdir ${_WEBPLUGIN_SLDIR:S,^${LOCALBASE},%D,} 2>/dev/null || true" >> ${TMPPLIST}
	@${ECHO_CMD} "@unexec rmdir ${_WEBPLUGIN_LIBDIR:S,^${LOCALBASE},%D,} 2>/dev/null || true" >> ${TMPPLIST}

.endif
