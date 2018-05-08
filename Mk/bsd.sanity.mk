# $FreeBSD$
#
# MAINTAINER: portmgr@FreeBSD.org
#

# Warnings for everyone

.for opt in ${ALL_OPTIONS:NDEBUG}
.if defined(WITH_${opt})
WARNING+=     "WITH_${opt} is unsupported, use WITH=${opt} on the command line, or one of these in /etc/make.conf, OPTIONS_SET+=${opt} to set it globally, or ${OPTIONS_NAME}_SET+=${opt} for only this port."
.endif
.if defined(WITHOUT_${opt})
WARNING+=     "WITHOUT_${opt} is unsupported, use WITHOUT=${opt} on the command line, or one of these in /etc/make.conf, OPTIONS_UNSET+=${opt} to set it globally, or ${OPTIONS_NAME}_UNSET+=${opt} for only this port."
.endif
.endfor

ALL_UNSUPPORTED=	WITHOUT_NLS NOPORTDOCS NOPORTEXAMPLES WITH_BDB_VER \
			OVERRIDE_LINUX_BASE_PORT WITH_OPENSSL_PORT \
			WITH_OPENSSL_BASE PYTHON_DEFAULT_VERSION \
			PYTHON2_DEFAULT_VERSION PYTHON3_DEFAULT_VERSION
ALL_DEPRECATED=		
ALL_NOTNEEDED=		WITH_NEW_XORG WITHOUT_NEW_XORG WITH_KMS WITHOUT_KMS

WITHOUT_NLS_ALT=	"OPTIONS_UNSET=NLS, or ${OPTIONS_NAME}_UNSET+=NLS instead"
NOPORTDOCS_ALT=		"OPTIONS_UNSET=DOCS, or ${OPTIONS_NAME}_UNSET+=DOCS instead"
NOPORTEXAMPLES_ALT=	"OPTIONS_UNSET=EXAMPLES, or ${OPTIONS_NAME}_UNSET+=EXAMPLES instead"
WITH_BDB_VER_ALT=	"DEFAULT_VERSIONS+=bdb=${WITH_BDB_VER}"
OVERRIDE_LINUX_BASE_PORT_ALT=	"DEFAULT_VERSIONS+=linux=${OVERRIDE_LINUX_BASE_PORT}"
WITH_OPENSSL_PORT_ALT=	"DEFAULT_VERSIONS+=ssl=${SSL_DEFAULT:Uopenssl} in your make.conf"
WITH_OPENSSL_BASE_ALT=	"DEFAULT_VERSIONS+=ssl=base in your make.conf"
WITH_NEW_XORG_ALT=	"removed and has no effect"
WITHOUT_NEW_XORG_ALT=	${WITH_NEW_XORG_ALT}
WITH_MKS_ALT=	"removed and has no effect"
WITHOUT_MKS_ALT=	${WITH_MKS_ALT}
PYTHON_DEFAULT_VERSION_ALT=	"DEFAULT_VERSIONS=python=${PYTHON_DEFAULT_VERSION:S/^python//}"
PYTHON2_DEFAULT_VERSION_ALT=	"DEFAULT_VERSIONS=python2=${PYTHON2_DEFAULT_VERSION:S/^python//}"
PYTHON3_DEFAULT_VERSION_ALT=	"DEFAULT_VERSIONS=python3=${PYTHON3_DEFAULT_VERSION:S/^python//}"

.for a in ${ALL_DEPRECATED}
.if defined(${a})
WARNING+=	"${a} is deprecated, please use ${${a}_ALT}"
.endif
.endfor

.for a in ${ALL_NOTNEEDED}
.if defined(${a})
WARNING+=	"${a} is not needed: ${${a}_REASON}"
.endif
.endfor

.for a in ${ALL_UNSUPPORTED}
.if defined(${a})
ERROR+=	"${a} is unsupported, please use ${${a}_ALT}"
.endif
.endfor



# Warnings only when DEVELOPER=yes

.if exists(${.CURDIR}/../../Mk/bsd.port.mk)
.if ${.CURDIR:H:T} != ${PKGCATEGORY}
DEV_ERROR+=	"The first entry in CATEGORIES should be the directory where the port lives"
.endif
.else
DEV_WARNING+=	"Not validating first entry in CATEGORIES due to being outside of PORTSDIR. Please ensure this is proper when committing."
.endif

.if defined(USE_PERL5) && ${USE_PERL5} == yes
DEV_ERROR+=	"USE_PERL5=yes is unsupported, please use USES=perl5 instead"
.endif

.if !empty(LIB_DEPENDS:M*/../*)
DEV_ERROR+=	"LIB_DEPENDS contains unsupported relative path to dependency"
.endif

.if !empty(RUN_DEPENDS:M*/../*)
DEV_ERROR+=	"RUN_DEPENDS contains unsupported relative path to dependency"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mpkgconfig}
DEV_ERROR+=	"USE_GNOME=pkgconfig is unsupported, please use USES=pkgconfig"
.endif

.if defined(USE_ZOPE) && ${USE_ZOPE} == yes
DEV_ERROR+=	"USE_ZOPE=yes is unsupported, please use USES=zope instead"
.endif

.if defined(USE_GITHUB) && defined(GH_COMMIT)
DEV_ERROR+=	"GH_COMMIT is unsupported, please convert GHL-\>GH in MASTER_SITES and set GH_TAGNAME to tag or commit hash and remove GH_COMMIT"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mgnomehack}
DEV_WARNING+=	"USE_GNOME=gnomehack is deprecated, please use USES=pathfix"
.endif

.if defined(USE_GNOME) && ${USE_GNOME:Mdesktopfileutils}
DEV_WARNING+=	"USE_GNOME=desktopfileutils is deprecated, please use USES=desktop-file-utils"
.endif

.if defined(LIB_DEPENDS) && ${LIB_DEPENDS:Nlib*}
DEV_ERROR+=	"All LIB_DEPENDS should use the new format and start out with lib.  \(libfoo.so vs foo.so\)"
.endif

.if defined(_PREMKINCLUDED)
DEV_ERROR+=	"you cannot include bsd.port[.pre].mk twice"
.endif

.if defined(LICENSE)
.if ${LICENSE:MBSD}
DEV_WARNING+=	"LICENSE must not contain BSD, instead use BSD[234]CLAUSE"
.endif
.else
DEV_WARNING+=	"Please set LICENSE for this port"
.endif

.if defined(USE_PYDISTUTILS) && ${USE_PYDISTUTILS} == "easy_install"
DEV_ERROR+=	"USE_PYDISTUTILS=easy_install is no longer supported, please use USE_PYDISTUTILS=yes"
.endif

.if defined(USE_PYTHON) && (${USE_PYTHON} == "yes" || ${USE_PYTHON:C/[-0-9.+]*//} == "")
_PYTHON_VAL := ${USE_PYTHON}
.if ${_PYTHON_VAL} != "yes"
DEV_ERROR+=	"USE_PYTHON=${_PYTHON_VAL} is no longer supported, please use USES=python:${_PYTHON_VAL}"
.else
DEV_ERROR+=	"USE_PYTHON=yes is no longer supported, please use USES=python"
.endif
.endif
.if defined(USE_PYTHON_RUN)
.if ${USE_PYTHON_RUN} != "yes"
DEV_ERROR+=	"USE_PYTHON_RUN is no longer supported, please use USES=python:${USE_PYTHON_RUN},run"
.else
DEV_ERROR+=	"USE_PYTHON_RUN is no longer supported, please use USES=python:run"
.endif
.endif
.if defined(USE_PYTHON_BUILD)
.if ${USE_PYTHON_BUILD} != "yes"
DEV_ERROR+=	"USE_PYTHON_BUILD is no longer supported, please use USES=python:${USE_PYTHON_BUILD},build"
.else
DEV_ERROR+=	"USE_PYTHON_BUILD is no longer supported, please use USES=python:build"
.endif
.endif

.if defined(USE_RC_SUBR) && ${USE_RC_SUBR:tu} == YES
DEV_ERROR+=	"USE_RC_SUBR=yes has not been supported for a long time, remove it."
.endif

.if defined(USE_TCL) || defined(USE_TCL_BUILD) || defined(USE_TCL_RUN) || defined(USE_TCL_WRAPPER) || \
   defined(USE_TK)  || defined(USE_TK_BUILD)  || defined(USE_TK_RUN)  || defined(USE_TK_WRAPPER)
DEV_ERROR+=	"USE_TCL and USE_TK are no longer supported, please use USES=tcl or USES=tk"
.endif

.if defined(USE_FPC) && ${USE_FPC:tl} == "yes"
DEV_ERROR+=	"USE_FPC=yes is no longer supported, please use USES=fpc"
.endif

SANITY_UNSUPPORTED=	USE_OPENAL USE_FAM USE_MAKESELF USE_ZIP USE_LHA USE_CMAKE \
		USE_READLINE USE_ICONV PERL_CONFIGURE PERL_MODBUILD \
		USE_PERL5_BUILD USE_PERL5_RUN USE_DISPLAY USE_FUSE \
		USE_GETTEXT USE_GMAKE USE_SCONS USE_DRUPAL NO_INSTALL_MANPAGES \
		INSTALLS_SHLIB USE_PYDISTUTILS PYTHON_CONCURRENT_INSTALL \
		PYDISTUTILS_AUTOPLIST PYTHON_PY3K_PLIST_HACK PYDISTUTILS_NOEGGINFO \
		USE_PYTHON_PREFIX USE_BZIP2 USE_XZ USE_PGSQL NEED_ROOT \
		UNIQUENAME LATEST_LINK USE_SQLITE USE_FIREBIRD USE_PHPEXT \
		USE_ZENDEXT USE_PHP_BUILD USE_PHPIZE WANT_PHP_CLI WANT_PHP_CGI \
		WANT_PHP_MOD WANT_PHP_WEB WANT_PHP_EMB USE_BDB PLIST_DIRSTRY \
		USE_RCORDER USE_OPENSSL WANT_GNOME RUBYGEM_AUTOPLIST WANT_SDL \
		INSTALLS_EGGINFO USE_DOS2UNIX NO_STAGE USE_RUBYGEMS USE_GHOSTSCRIPT \
		USE_GHOSTSCRIPT_BUILD USE_GHOSTSCRIPT_RUN USE_AUTOTOOLS APACHE_PORT \
		USE_FPC_RUN WANT_FPC_BASE WANT_FPC_ALL
SANITY_DEPRECATED=	PYTHON_PKGNAMESUFFIX MLINKS \
			USE_MYSQL WANT_MYSQL_VER \
			PYDISTUTILS_INSTALLNOSINGLE \
			USE_APACHE USE_APACHE_BUILD USE_APACHE_RUN
SANITY_NOTNEEDED=	CMAKE_NINJA WX_UNICODE USE_KDEBASE_VER \
			USE_KDELIBS_VER USE_QT_VER

.for a in 1 2 3 4 5 6 7 8 9 L N
SANITY_DEPRECATED+=	MAN${a}
MAN${a}_ALT=		it more, obsoleted by staging
.endfor

USE_AUTOTOOLS_ALT=	USES=autoreconf and GNU_CONFIGURE=yes
USE_OPENAL_ALT=		USES=openal
USE_FAM_ALT=		USES=fam
USE_MAKESELF_ALT=	USES=makeself
USE_ZIP_ALT=		USES=zip
USE_LHA_ALT=		USES=lha
USE_BZIP2_ALT=		USES=tar:bzip2
USE_XZ_ALT=		USES=tar:xz
USE_CMAKE_ALT=		USES=cmake
USE_READLINE_ALT=	USES=readline
USE_ICONV_ALT=		USES=iconv
USE_GMAKE_ALT=		USES=gmake
PERL_CONFIGURE_ALT=	USES=perl5 along with USE_PERL5=configure
PERL_MODBUILD_ALT=	USES=perl5 along with USE_PERL5=modbuild
USE_PERL5_BUILD_ALT=	USES=perl5 along with USE_PERL5=build
USE_PERL5_RUN_ALT=	USES=perl5 along with USE_PERL5=run
USE_DISPLAY_ALT=	USES=display
USE_FUSE_ALT=		USES=fuse
USE_GETTEXT_ALT=	USES=gettext
USE_SCONS_ALT=		USES=scons
USE_DRUPAL_ALT=		USES=drupal
USE_PYDISTUTILS_ALT=		USE_PYTHON=distutils
USE_PGSQL_ALT=		USES=pgsql
INSTALLS_SHLIB_ALT=	USE_LDCONFIG
NEED_ROOT_ALT=		USES=fakeroot or USES=uidfix
PYTHON_CONCURRENT_INSTALL_ALT=	USE_PYTHON=concurrent
PYDISTUTILS_AUTOPLIST_ALT=	USE_PYTHON=autoplist
PYTHON_PY3K_PLIST_HACK_ALT=	USE_PYTHON=py3kplist
PYDISTUTILS_NOEGGINFO_ALT=	USE_PYTHON=noegginfo
USE_PYTHON_PREFIX_ALT=		USE_PYTHON=pythonprefix
PYTHON_PKGNAMESUFFIX_ALT=	PYTHON_PKGNAMEPREFIX
NO_INSTALL_MANPAGES_ALT=	USES=imake:noman
UNIQUENAME_ALT=		PKGBASE
LATEST_LINK_ALT=	PKGBASE
CMAKE_NINJA_REASON=	Now the ninja generator is the default
WX_UNICODE_REASON=	Now no-op as only unicode is supported now
PLIST_DIRSTRY_ALT=	PLIST_DIRS
USE_SQLITE_ALT=		USES=sqlite
USE_FIREBIRD_ALT=	USES=firebird
USE_BDB_ALT=		USES=bdb:${USE_BDB}
USE_MYSQL_ALT=		USES=mysql:${USE_MYSQL}
WANT_MYSQL_VER_ALT=	USES=mysql:${WANT_MYSQL_VER}
USE_OPENSSL_ALT=	USES=ssl
USE_PHPIZE_ALT=		USES=php:phpize
USE_PHPEXT_ALT=		USES=php:ext
USE_ZENDEXT_ALT=	USES=php:zend
USE_PHP_BUILD_ALT=	USES=php:build
WANT_PHP_CLI_ALT=	USES=php:cli
WANT_PHP_CGI_ALT=	USES=php:cgi
WANT_PHP_MOD_ALT=	USES=php:mod
WANT_PHP_WEB_ALT=	USES=php:web
WANT_PHP_EMB_ALT=	USES=php:embed
USE_RCORDER_ALT=	USE_RC_SUBR=${USE_RCORDER}
WANT_GNOME_ALT=		USES=gnome
MLINKS_ALT=		it no more
USE_DOS2UNIX_ALT=	USES=dos2unix
PYDISTUTILS_INSTALLNOSINGLE_ALT=	it no more
INSTALLS_EGGINFO_ALT=	an entry in the plist
WANT_SDL_ALT=		USE_SDL for SDL directly, if you need optional dependency, use options
RUBYGEM_AUTOPLIST_ALT=	USES=gem
USE_RUBYGEMS_ALT=	USES=gem
USE_GHOSTSCRIPT_ALT=	USES=ghostscript
USE_GHOSTSCRIPT_BUILD_ALT=	USES=ghostscript
USE_GHOSTSCRIPT_RUN_ALT=	USES=ghostscript
NO_STAGE_ALT=	https://wiki.freebsd.org/ports/StageDir to convert your port to staging
USE_APACHE_ALT=		USES=apache:${USE_APACHE:C/2(0-9)/2.\1/g}
USE_APACHE_BUILD_ALT=	USES=apache:build,${USE_APACHE_BUILD:C/2(0-9)/2.\1/g}
USE_APACHE_RUN_ALT=	USES=apache:run,${USE_APACHE_RUN:C/2(0-9)/2.\1/g}
APACHE_PORT_ALT=	DEFAULT_VERSIONS+=apache=${APACHE_PORT:S/www\/apache//:C/2(0-9)/2.\1/}
USE_FPC_RUN_ALT=	USES=fpc:run
WANT_FPC_BASE_ALT=	USES=fpc:base
WANT_FPC_ALL_ALT=	USES=fpc:all

.for a in ${SANITY_DEPRECATED}
.if defined(${a})
DEV_WARNING+=	"${a} is deprecated, please use ${${a}_ALT}"
.endif
.endfor

.for a in ${SANITY_NOTNEEDED}
.if defined(${a})
DEV_WARNING+=	"${a} is not needed: ${${a}_REASON}"
.endif
.endfor

.for a in ${SANITY_UNSUPPORTED}
.if defined(${a})
DEV_ERROR+=	"${a} is unsupported, please use ${${a}_ALT}"
.endif
.endfor
