# $FreeBSD$
#
# Provide support for Python related ports. This includes detecting Python
# interpreters, ports providing package and modules for python as well as
# consumer ports requiring Python at build or run time.
#
# Feature:	python
# Usage:	USES=python or USES=python:args
# Valid ARGS:	<version>, build, run
#
# version 	If your port requires only some set of Python versions, you
# 		can set this to [min]-[max] or min+ or -max or as an
# 		explicit version or as a meta port version (eg. 3.2-3.3 for
# 		[min]-[max], 2.7+ or -3.2 for min+ and -max, 2.7 for an
# 		explicit version or 3 for a meta port version). Example:
#
#			USES=python:2.7		# Only use Python 2.7
#			USES=python:3.2+	# Use Python 3.2 or newer
#			USES=python:3.2-3.3	# Use Python 3.2 or 3.3
#			USES=python:-3.2	# Use any Python up to 3.2
#			USES=python:2		# Use the Python 2 meta port
#			USES=python		# Use the set default Python
#						# version
#
# build		Indicates that Python is needed at build time and adds
#		it as BUILD_DEPENDS.
# run		Indicates that Python is needed at run time and adds
#		it as RUN_DEPENDS.
#
# If build and run are omitted, Python will be added as BUILD_DEPENDS and
# RUN_DEPENDS.
#
# Variables, which can be set by a user:
#
# PYTHON_VERSION	- The chosen Python interpreter including the version,
#			  e.g. python2.7, python3.3, etc. This allows the user
#			  to override the currently chosen default version and
#			  to install the port for a specific Python version.
#			  It must not be set by a port.
#
# Variables, which can be set by the port:
#
# USE_PYTHON		- A list of additional features and functionality to
#			  enable. Supported features are:
#
#	concurrent 	- Indicates that the port can be installed for
#			  different python versions at the same time. The port
#			  is supposed to use a unique prefix for certain
#			  directories using USES=uniquefiles:dirs (see the
#			  uniquefiles.mk Uses for details about the
#			  directories), if set to yes. Binaries receive an
#			  additional suffix, based on ${PYTHON_VER}.
#
#			  The values for the uniquefiles USES are set as
#			  follows:
#
#				UNIQUE_PREFIX=  ${PYTHON_PKGNAMEPREFIX}
#				UNIQUE_SUFFIX=  -${PYTHON_VER}
#
#			  If the port is installed for the current default
#			  python version, scripts and binaries in
#
#				${PREFIX}/bin
#				${PREFIX}/sbin
#				${PREFIX}/libexec
#
#			  are linked from the prefixed version to the
#			  prefix-less original name, e.g.
#			  bin/foo-2.7 --> bin/foo.
#
#	distutils	- Use distutils as do-configure, do-build and
#			  do-install targets.
#
#	autoplist	- Automatically generates the packaging list for a
#			  port that uses distutils when defined.
#			  requires: distutils
#
#	py3kplist	- Automatically generates Python 3.x compatible
#			  __pycache__ entries from a Python 2.x packaging list
#			  when defined. Use this for ports that do *not* use
#			  standard Python packaging mechanisms such as
#			  distutils, and support *both* Python 2.x and 3.x.
#			  Not needed, if USE_PYTHON=autoplist is set.
#
#	pythonprefix	- Says that the port installs in ${PYTHONBASE} instead
#			  of ${PREFIX}.
#
#	noegginfo	- Skip an egg-info entry from plist, if defined.
#
# PYTHON_CMD		- Python's command line file name, including the
#			  version number (used for dependencies).
#			  default: ${PYTHONBASE}/bin/${PYTHON_VERSION}
#
# PYSETUP		- Name of the setup script used by the distutils
#			  package.
#			  default: setup.py
#
# PYDISTUTILS_PKGNAME
#			- Internal name in the distutils for egg-info.
#			  default: ${PORTNAME}
#
# PYDISTUTILS_PKGVERSION
#			- Internal version in the distutils for egg-info.
#			  default: ${PORTVERSION}
#
# PYDISTUTILS_CONFIGURE_TARGET
#			- Pass this command to distutils on configure stage.
#			  default: config
#
# PYDISTUTILS_BUILD_TARGET
#			- Pass this command to distutils on build stage.
#			  default: build
#
# PYDISTUTILS_INSTALL_TARGET
#			- Pass this command to distutils on install stage.
#			  default: install
#
# PYDISTUTILS_CONFIGUREARGS
#			- Arguments to config with distutils.
#			  default: <empty>
#
# PYDISTUTILS_BUILDARGS
#			- Arguments to build with distutils.
#			  default: <empty>
#
# PYDISTUTILS_INSTALLARGS
#			- Arguments to install with distutils.
#			  default: -c -O1 --prefix=${PREFIX} --single-version-externally-managed --root=${STAGEDIR}
#
# PYDISTUTILS_EGGINFO
#			- Canonical name for egg-info.
#			  default: ${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-py${PYTHON_VER}.egg-info
#
# The following variables can be read by ports and must not be modified:
#
# PYTHONBASE		- The installation prefix of the chosen Python
#			  interpreter, e.g. /usr/local
#
# PYTHON_PORTVERSION
#			- Version number suitable for ${PORTVERSION}.
#
# PYTHON_PORTSDIR	- The port directory of the chosen Python interpreter
#
# PYTHON_REL		- The release number of the chosen Python interpreter
#			  without dots, e.g. 276, 341, ...
#
# PYTHON_SUFFIX		- The major-minor release number of the chosen Python
#			  interpreter without dots, e.g. 27, 34, ...
#			  Used for prefixes and suffixes.
#
# PYTHON_MAJOR_VER	- The major release version of the chosen Python
#			  interpreter, e.g. 2, 3, ...
#
# PYTHON_VER		- The major-minor release version of the chosen Python
#			  interpreter, e.g. 2.7, 3.4, ...
#
# PYTHON_ABIVER		- Additional ABI flags set by the chosen Python
#			  interpreter, e.g. md
#
# PYTHON_INCLUDEDIR	- Location of the Python include files.
#			  default: ${PYTHONBASE}/include/${PYTHON_VERSION}
#
# PYTHON_LIBDIR		- Base of the python library tree
#			  default: ${PYTHONBASE}/lib/${PYTHON_VERSION}
#
# PYTHON_SITELIBDIR	- Location of the site-packages tree. Don't change,
#			  unless you know what you do.
#			  default: ${PYTHON_LIBDIR}/site-packages
#
# There are PREFIX-clean variants of the PYTHON_*DIR variables above.
# They are meant to be used by ports instead of the above variables, so the
# ports respect ${PREFIX} (unless USE_PYTHON=pythonprefix is specified).
#
# PYTHONPREFIX_INCLUDEDIR	default: ${PREFIX}/include/${PYTHON_VERSION}
# PYTHONPREFIX_LIBDIR		default: ${PREFIX}/lib/${PYTHON_VERSION}
# PYTHONPREFIX_SITELIBDIR	default: ${PYTHONPREFIX_LIBDIR}/site-packages
#
# PYTHON_PLATFORM	- Python's idea of the OS release.
#			  This is faked with ${OPSYS} and ${OSREL} until we
#			  find out how to delay defining a variable until
#			  after a certain target has been built.
#
# PYTHON_PKGNAMEPREFIX
#			- Use this as a ${PKGNAMEPREFIX} to distinguish
#			  packages for different Python versions.
#			  default: py${PYTHON_SUFFIX}-
#
# Using USES=python.mk also will add some useful entries to PLIST_SUB:
#
#	PYTHON_INCLUDEDIR=${PYTHONPREFIX_INCLUDEDIR:S;${PREFIX}/;;}
#	PYTHON_LIBDIR=${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;}
#	PYTHON_PLATFORM=${PYTHON_PLATFORM}
#	PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
#	PYTHON_VERSION=${PYTHON_VERSION}
#	PYTHON_VER=${PYTHON_VER}
#
#
# Deprecated variables, which exist for compatibility and will be removed
# soon:
#
# USE_PYDISTUTILS	- Deprecated, use USE_PYTHON=distutils instead
#
# PYDISTUTILS_AUTOPLIST
#			- Deprecated, use USE_PYTHON=autoplist instead
#
# PYTHON_PY3K_PLIST_HACK
#			- Deprecated, use USE_PYTHON=py3kplist instead
#
# PYDISTUTILS_NOEGGINFO
#			- Deprecated, use USE_PYTHON=noegginfo instead
#
# PYTHON_DEFAULT_VERSION
# PYTHON2_DEFAULT_VERSION
# PYTHON3_DEFAULT_VERSION
#			- Deprecated, use PYTHON[2,3]_DEFAULT instead,
#			  see bsd.default-versions.mk
#
# PYTHON_PKGNAMESUFFIX
#			- Deprecated, use PYTHON_PKGNAMEPREFIX instead
#			  default: -py${PYTHON_SUFFIX}
#
# PYTHON_CONCURRENT_INSTALL
#			- Deprecated, use USE_PYTHON=concurrent instead
#
# USE_PYTHON_PREFIX	- Deprecated, use USE_PYTHON=pythonprefix instead
#
# PYDISTUTILS_INSTALLNOSINGLE
#			- Deprecated without replacement
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_PYTHON_MK)
_INCLUDE_USES_PYTHON_MK=	yes

# What Python version and what Python interpreters are currently supported?
_PYTHON_VERSIONS=		2.7 3.4 3.3 3.2	# preferred first
_PYTHON_PORTBRANCH=		2.7		# ${_PYTHON_VERSIONS:[1]}
_PYTHON_BASECMD=		${LOCALBASE}/bin/python
_PYTHON_RELPORTDIR=		${PORTSDIR}/lang/python

# COMPAT KNOBS, remove them, once the tree is cleaned
.undef _PY_COMPAT_OLD
# We will reuse USE_PYTHON with a different meaning, so make sure that, while
# we are in the transition phase from USE_PYTHON -> USES=python, it is mapped
# and reassigned correctly
.if defined(USE_PYTHON_BUILD) || defined(USE_PYTHON_RUN)
# old style
_PY_COMPAT_OLD= yes
.elif defined(USE_PYTHON)
.if ${USE_PYTHON} == "yes"
# old style
_PY_COMPAT_OLD= yes
.elif ${USE_PYTHON:C/[-0-9.+]*//} == ""
# old style X.Y, X.Y+, X.Y-, -X.Y, X.Y-Z.A
_PY_COMPAT_OLD=	yes
.endif # ${USE_PYTHON} == "yes" ...
.endif # defined(USE_PYTHON_BUILD) || defined(USE_PYTHON_RUN)

.if defined(_PY_COMPAT_OLD)
.if defined(USE_PYTHON)
.if ${USE_PYTHON} != "yes"
python_ARGS:=	${USE_PYTHON}
.endif
.else
.if defined(USE_PYTHON_BUILD)
.if ${USE_PYTHON_BUILD} != "yes"
python_ARGS=	${USE_PYTHON_BUILD},build
.else
python_ARGS=	build
.endif
.endif # defined(USE_PYTHON_BUILD)
.if defined(USE_PYTHON_RUN)
.if ${USE_PYTHON_RUN} != "yes"
python_ARGS+=	${USE_PYTHON_RUN},run
.else
python_ARGS+=	run
.endif
.endif # defined(USE_PYTHON_RUN)
.endif # defined(USE_PYTHON)
# Everything passed to python_ARGS, undef USE_PYTHON, since we will reuse
# it with a different meaning below
.undef USE_PYTHON
.endif # defined(_PY_COMPAT_OLD)
.undef _PY_COMPAT_OLD

.if !defined(USE_PYTHON)
USE_PYTHON=
.if defined(USE_PYDISTUTILS)
USE_PYTHON+=	distutils
.endif
.if defined(PYDISTUTILS_AUTOPLIST)
USE_PYTHON+=	autoplist
.endif
.if defined(PYTHON_PY3K_PLIST_HACK)
USE_PYTHON+=	py3kplist
.endif
.if defined(PYTHON_CONCURRENT_INSTALL)
USE_PYTHON+=	concurrent
.endif
.if defined(USE_PYTHON_PREFIX)
USE_PYTHON+=	pythonprefix
.endif
.if defined(PYDISTUTILS_NOEGGINFO)
USE_PYTHON+=	noegginfo
.endif
.endif # !defined(USE_PYTHON)
# COMPAT KNOBS END

# Make each individual feature available as _PYTHON_FEATURE_<FEATURENAME>
.for var in ${USE_PYTHON}
_PYTHON_FEATURE_${var:tu}=	yes
.endfor

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _PYTHON_BUILD_DEP
.undef _PYTHON_RUN_DEP
_PYTHON_ARGS=		${python_ARGS:S/,/ /g}
.if ${_PYTHON_ARGS:Mbuild}
_PYTHON_BUILD_DEP=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Nbuild}
.endif
.if ${_PYTHON_ARGS:Mrun}
_PYTHON_RUN_DEP=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Nrun}
.endif

# The port does not specify a build or run dependency, assume both are
# required.
.if !defined(_PYTHON_BUILD_DEP) && !defined(_PYTHON_RUN_DEP)
_PYTHON_BUILD_DEP=	yes
_PYTHON_RUN_DEP=	yes
.endif

# Determine version number of Python to use
.include "${PORTSDIR}/Mk/bsd.default-versions.mk"

.if defined(PYTHON_DEFAULT_VERSION)
WARNING+=	"PYTHON_DEFAULT_VERSION is defined, consider using DEFAULT_VERSIONS=python=${PYTHON_DEFAULT_VERSION:S/^python//} instead"
.endif
.if defined(PYTHON2_DEFAULT_VERSION)
WARNING+=	"PYTHON2_DEFAULT_VERSION is defined, consider using DEFAULT_VERSIONS=python2=${PYTHON2_DEFAULT_VERSION:S/^python//} instead"
.endif
.if defined(PYTHON3_DEFAULT_VERSION)
WARNING+=	"PYTHON3_DEFAULT_VERSION is defined, consider using DEFAULT_VERSIONS=python3=${PYTHON3_DEFAULT_VERSION:S/^python//} instead"
.endif

.if exists(${LOCALBASE}/bin/python)
_PYTHON_DEFAULT_VERSION!=	(${LOCALBASE}/bin/python -c \
		'import sys; print("%d.%d" % sys.version_info[:2])' 2> /dev/null \
		|| ${ECHO_CMD} ${_PYTHON_PORTBRANCH}) | ${TAIL} -1
.if defined(PYTHON_DEFAULT) && (${PYTHON_DEFAULT} != ${_PYTHON_DEFAULT_VERSION})
WARNING+=	"Your requested default python version ${PYTHON_DEFAULT} is different from the installed default python interpreter version ${_PYTHON_DEFAULT_VERSION}"
.endif
PYTHON_DEFAULT_VERSION=		python${_PYTHON_DEFAULT_VERSION}
.else
PYTHON_DEFAULT_VERSION=		python${PYTHON_DEFAULT}
.endif # exists(${LOCALBASE}/bin/python)

# Is only a meta-port version defined?
.if ${PYTHON_DEFAULT_VERSION} == "python2"
PYTHON2_DEFAULT_VERSION?=	python${PYTHON2_DEFAULT}
.elif ${PYTHON_DEFAULT_VERSION:R} == "python2"
PYTHON2_DEFAULT_VERSION=	${PYTHON_DEFAULT_VERSION}
.else
PYTHON2_DEFAULT_VERSION?=	python${PYTHON2_DEFAULT}
.endif
.if ${PYTHON_DEFAULT_VERSION} == "python3"
PYTHON3_DEFAULT_VERSION?=	python${PYTHON3_DEFAULT}
.elif ${PYTHON_DEFAULT_VERSION:R} == "python3"
 PYTHON3_DEFAULT_VERSION=	${PYTHON_DEFAULT_VERSION}
.else
PYTHON3_DEFAULT_VERSION?=	python${PYTHON3_DEFAULT}
.endif

.if ${_PYTHON_ARGS} == "2"
_PYTHON_ARGS=		${PYTHON2_DEFAULT_VERSION:S/^python//}
_WANTS_META_PORT=	2
.elif ${_PYTHON_ARGS} == "3"
_PYTHON_ARGS=		${PYTHON3_DEFAULT_VERSION:S/^python//}
_WANTS_META_PORT=	3
.endif  # ${_PYTHON_ARGS} == "2"

.if defined(PYTHON_VERSION)
# A port/user requests a specific python version for its dependencies via
# DEPENDS_ARGS, since it requires the specific python version itself.
# Several things can happen now:
#	a) the dependency supports the requested version -> everything's fine
#	b) the dependency does not support the requested version
#		1) the dependency works in a way that the different python
#		   versions do not matter -> everything's fine
#		2) the dependency is likely to break due to the conflict
#		   nothing's fine
#
# b.2) needs to be resolved. Due to the complexity of how different pieces of
# software are built, we can't solve this automatically. Instead, let's assume
# that maintainers know what they are doing and assume PYTHON_VERSION to be a
# hint. Just warn maintainers, if the versions do not match
# (_PYTHON_VERSION_NONSUPPORTED).
_PYTHON_VERSION:=	${PYTHON_VERSION:S/^python//}
_PYTHON_CMD=		${LOCALBASE}/bin/${PYTHON_VERSION}
.else
_PYTHON_VERSION:=	${PYTHON_DEFAULT_VERSION:S/^python//}
_PYTHON_CMD=		${LOCALBASE}/bin/${PYTHON_DEFAULT_VERSION}
.endif # defined(PYTHON_VERSION)

# Validate Python version whether it meets the version restriction.
_PYTHON_VERSION_CHECK:=		${_PYTHON_ARGS:C/^([1-9]\.[0-9])$/\1-\1/}
_PYTHON_VERSION_MINIMUM_TMP:=	${_PYTHON_VERSION_CHECK:C/([1-9]\.[0-9])[-+].*/\1/}
_PYTHON_VERSION_MINIMUM:=	${_PYTHON_VERSION_MINIMUM_TMP:M[1-9].[0-9]}
_PYTHON_VERSION_MAXIMUM_TMP:=	${_PYTHON_VERSION_CHECK:C/.*-([1-9]\.[0-9])/\1/}
_PYTHON_VERSION_MAXIMUM:=	${_PYTHON_VERSION_MAXIMUM_TMP:M[1-9].[0-9]}

.undef _PYTHON_VERSION_NONSUPPORTED
.if !empty(_PYTHON_VERSION_MINIMUM) && (${_PYTHON_VERSION} < ${_PYTHON_VERSION_MINIMUM})
_PYTHON_VERSION_NONSUPPORTED=	${_PYTHON_VERSION_MINIMUM} at least
.elif !empty(_PYTHON_VERSION_MAXIMUM) && (${_PYTHON_VERSION} > ${_PYTHON_VERSION_MAXIMUM})
_PYTHON_VERSION_NONSUPPORTED=	${_PYTHON_VERSION_MAXIMUM} at most
.endif

# If we have an unsupported version of Python, try another.
.if defined(_PYTHON_VERSION_NONSUPPORTED)
.if defined(PYTHON_VERSION) || defined(PYTHON_CMD)
_PV:=		${_PYTHON_VERSION}	# preserve the specified python version
WARNING+=	"needs Python ${_PYTHON_VERSION_NONSUPPORTED}. But a port depending on this one specified ${_PV}"
.endif # defined(PYTHON_VERSION) || defined(PYTHON_CMD)
.undef _PYTHON_VERSION
.for ver in ${PYTHON2_DEFAULT} ${PYTHON3_DEFAULT} ${_PYTHON_VERSIONS}
__VER=		${ver}
.if !defined(_PYTHON_VERSION) && \
	!(!empty(_PYTHON_VERSION_MINIMUM) && ( \
		${__VER} < ${_PYTHON_VERSION_MINIMUM})) && \
	!(!empty(_PYTHON_VERSION_MAXIMUM) && ( \
		${__VER} > ${_PYTHON_VERSION_MAXIMUM}))
_PYTHON_VERSION=	${ver}
_PYTHON_CMD=		${LOCALBASE}/bin/python${ver}
.endif
.endfor
.if !defined(_PYTHON_VERSION)
IGNORE=		needs an unsupported version of Python
.endif
.endif	# defined(_PYTHON_VERSION_NONSUPPORTED)

# Pass PYTHON_VERSION down the dependency chain. This ensures that
# port A -> B -> C all will use the same python version and do not
# try to find a different one, if the passed version fits into
# the supported version range.
PYTHON_VERSION?=	python${_PYTHON_VERSION}
DEPENDS_ARGS+=		PYTHON_VERSION=${PYTHON_VERSION}

# Got the correct python version, set some publicly accessible variables
PYTHON_VER=		${_PYTHON_VERSION}
PYTHON_SUFFIX=		${_PYTHON_VERSION:S/.//g}
PYTHON_MAJOR_VER=	${PYTHON_VER:R}
PYTHON_REL=		# empty
PYTHON_ABIVER=		# empty
PYTHON_PORTSDIR=	${_PYTHON_RELPORTDIR}${PYTHON_SUFFIX}
PYTHON_PORTVERSION!=	${MAKE} -V PORTVERSION -C ${PYTHON_PORTSDIR}
PYTHON_REL=		${PYTHON_PORTVERSION:S/.//g}

# Might be overridden by calling ports
PYTHON_CMD?=		${_PYTHON_BASECMD}${_PYTHON_VERSION}
.if exists(${PYTHON_CMD}-config) && ${PYTHON_VER} != 2.7
PYTHON_ABIVER!=		${PYTHON_CMD}-config --abiflags
.endif

PYTHONBASE!=	(${PYTHON_CMD} -c 'import sys; print(sys.prefix)' \
			2> /dev/null || ${ECHO_CMD} ${LOCALBASE}) | ${TAIL} -1

PYTHON_INCLUDEDIR=	${PYTHONBASE}/include/${PYTHON_VERSION}${PYTHON_ABIVER}
PYTHON_LIBDIR=		${PYTHONBASE}/lib/${PYTHON_VERSION}
PYTHON_PLATFORM=	${OPSYS:tl}${OSREL:C/\.[0-9.]*//}
PYTHON_SITELIBDIR=	${PYTHON_LIBDIR}/site-packages
PYTHON_PKGNAMEPREFIX=	py${PYTHON_SUFFIX}-
PYTHON_PKGNAMESUFFIX=	-py${PYTHON_SUFFIX}

PYTHONPREFIX_INCLUDEDIR=	${PYTHON_INCLUDEDIR:S;${PYTHONBASE};${PREFIX};}
PYTHONPREFIX_LIBDIR=		${PYTHON_LIBDIR:S;${PYTHONBASE};${PREFIX};}
PYTHONPREFIX_SITELIBDIR=	${PYTHON_SITELIBDIR:S;${PYTHONBASE};${PREFIX};}

# Used for recording the installed files.
_PYTHONPKGLIST=	${WRKDIR}/.PLIST.pymodtmp

# Ports bound to a certain python version SHOULD
# - use the PYTHON_PKGNAMEPREFIX
# - use directories using the PYTHON_PKGNAMEPREFIX
# - install binaries using the required PYTHON_VER, with
#   the default python version creating a symlink to the original binary
#   name (for staging-aware ports).
#
# What makes a port 'bound' to a certain python version?
# - it installs data into PYTHON_SITELIBDIR, PYTHON_INCLUDEDIR, ...
# - it links against libpython*.so
# - it uses USE_PYTHON=distutils
#

.if defined(_PYTHON_FEATURE_CONCURRENT)
_USES_POST+=		uniquefiles:dirs
.if ${PYTHON_VERSION} == ${PYTHON_DEFAULT_VERSION}
UNIQUE_DEFAULT_LINKS=	yes
.else
UNIQUE_DEFAULT_LINKS=	no
.endif
UNIQUE_PREFIX=		${PYTHON_PKGNAMEPREFIX}
UNIQUE_SUFFIX=		-${PYTHON_VER}

.if defined(_PYTHON_FEATURE_AUTOPLIST)
UNIQUE_FIND_SUFFIX_FILES=	\
	${SED} -e 's|^${PREFIX}/||' ${_PYTHONPKGLIST} ${TMPPLIST} | \
	${GREP} -e '^bin/.*$$\|^sbin/.*$$\|^libexec/.*$$'
.else
UNIQUE_FIND_SUFFIX_FILES=	\
	${GREP} -he '^bin/.*$$\|^sbin/.*$$\|^libexec/.*$$' ${TMPPLIST} 2>/dev/null
.endif
.endif # defined(_PYTHON_FEATURE_CONCURRENT)

_CURRENTPORT:=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
.if defined(_PYTHON_FEATURE_DISTUTILS) && \
	${_CURRENTPORT:S/${PYTHON_SUFFIX}$//} != ${PYTHON_PKGNAMEPREFIX}setuptools
BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:${PORTSDIR}/devel/py-setuptools${PYTHON_SUFFIX}
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}setuptools${PYTHON_SUFFIX}>0:${PORTSDIR}/devel/py-setuptools${PYTHON_SUFFIX}
.endif

# distutils support
PYSETUP?=		setup.py
PYDISTUTILS_SETUP?=	-c \
	"import sys; import setuptools; \
	__file__='${PYSETUP}'; sys.argv[0]='${PYSETUP}'; \
	exec(compile(open(__file__, 'rb').read().replace(b'\\r\\n', b'\\n'), __file__, 'exec'))"
PYDISTUTILS_CONFIGUREARGS?=	# empty
PYDISTUTILS_BUILDARGS?=		# empty
PYDISTUTILS_INSTALLARGS?=	-c -O1 --prefix=${PREFIX}
.if defined(_PYTHON_FEATURE_DISTUTILS)
. if !defined(PYDISTUTILS_INSTALLNOSINGLE)
PYDISTUTILS_INSTALLARGS+=	--single-version-externally-managed
. endif
PYDISTUTILS_INSTALLARGS+=	--root=${STAGEDIR}
.endif
PYDISTUTILS_INSTALLARGS:=	--record ${_PYTHONPKGLIST} \
		${PYDISTUTILS_INSTALLARGS}

PYDISTUTILS_PKGNAME?=	${PORTNAME}
PYDISTUTILS_PKGVERSION?=${PORTVERSION}
PYDISTUTILS_EGGINFO?=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-py${PYTHON_VER}.egg-info
PYDISTUTILS_EGGINFODIR?=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

add-plist-egginfo:
.if !defined(_PYTHON_FEATURE_NOEGGINFO) && \
	!defined(_PYTHON_FEATURE_AUTOPLIST) && \
	defined(_PYTHON_FEATURE_DISTUTILS) && \
	defined(PYTHON_REL)
. for egginfo in ${PYDISTUTILS_EGGINFO}
	if [ -d "${PYDISTUTILS_EGGINFODIR}/${egginfo}" ]; then \
		${LS} ${PYDISTUTILS_EGGINFODIR}/${egginfo} | while read f; do \
			${ECHO_CMD} ${PYDISTUTILS_EGGINFODIR:S;^${STAGEDIR}${PREFIX}/;;}/${egginfo}/$${f} >> ${TMPPLIST}; \
		done; \
	fi;
. endfor
.else
	@${DO_NADA}
.endif

.if defined(_PYTHON_FEATURE_AUTOPLIST) && defined(_PYTHON_FEATURE_DISTUTILS)
_RELSITELIBDIR=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
_RELLIBDIR=		${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;}

add-plist-post:	add-plist-pymod
add-plist-pymod:
	@${SED} -e 's|^${STAGEDIR}${PREFIX}/||' \
		-e 's|^${PREFIX}/||' \
		-e 's|^\(man/.*man[0-9]\)/\(.*\.[0-9]\)$$|\1/\2.gz|' \
		-e 's|[[:alnum:]|[:space:]]*/\.\./*||g; s|/\./|/|g' \
		${_PYTHONPKGLIST} | ${SORT} >> ${TMPPLIST}

.else
.if ${PYTHON_REL} >= 320 && defined(_PYTHON_FEATURE_PY3KPLIST)
# When Python version is 3.2+ we rewrite all the filenames
# of TMPPLIST that end with .py[co], so that they conform
# to PEP 3147 (see http://www.python.org/dev/peps/pep-3147/)
PYMAGICTAG=		${PYTHON_CMD} -c 'import imp; print(imp.get_tag())'
add-plist-post:
	@${AWK} '\
		/\.py[co]$$/ && !($$0 ~ "/" pc "/") {id = match($$0, /\/[^\/]+\.py[co]$$/); if (id != 0) {d = substr($$0, 1, RSTART - 1); dirs[d] = 1}; sub(/\.py[co]$$/,  "." mt "&"); sub(/[^\/]+\.py[co]$$/, pc "/&"); print; next} \
		/^@dirrm / {d = substr($$0, 8); if (d in dirs) {print $$0 "/" pc}; print $$0; next} \
		/^@dirrmtry / {d = substr($$0, 11); if (d in dirs) {print $$0 "/" pc}; print $$0; next} \
		{print} \
		' \
		pc="__pycache__" mt="$$(${PYMAGICTAG})" \
		${TMPPLIST} > ${TMPPLIST}.pyc_tmp
	@${MV} ${TMPPLIST}.pyc_tmp ${TMPPLIST}
.endif # ${PYTHON_REL} >= 320 && defined(_PYTHON_FEATURE_PY3KPLIST)
.endif # defined(_PYTHON_FEATURE_AUTOPLIST) && defined(_PYTHON_FEATURE_DISTUTILS)

# Fix for programs that build python from a GNU auto* environment
CONFIGURE_ENV+=	PYTHON="${PYTHON_CMD}"

# Python 3rd-party modules
PYGAME=		${PYTHON_PKGNAMEPREFIX}game>0:${PORTSDIR}/devel/py-game
PYNUMERIC=	${PYTHON_SITELIBDIR}/Numeric/Numeric.py:${PORTSDIR}/math/py-numeric
PYNUMPY=	${PYTHON_SITELIBDIR}/numpy/core/numeric.py:${PORTSDIR}/math/py-numpy
PYXML=		${PYTHON_SITELIBDIR}/_xmlplus/__init__.py:${PORTSDIR}/textproc/py-xml

# dependencies
.if defined(_PYTHON_BUILD_DEP)
BUILD_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
.if defined(_WANTS_META_PORT)
BUILD_DEPENDS+=	python${_WANTS_META_PORT}:${_PYTHON_RELPORTDIR}${_WANTS_META_PORT}
.endif
.endif
.if defined(_PYTHON_RUN_DEP)
RUN_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
.if defined(_WANTS_META_PORT)
RUN_DEPENDS+=	python${_WANTS_META_PORT}:${_PYTHON_RELPORTDIR}${_WANTS_META_PORT}
.endif
.endif

# set $PREFIX as Python's one
.if defined(_PYTHON_FEATURE_PYTHONPREFIX)
PREFIX=		${PYTHONBASE}
.endif

# Substitutions for pkg-plist
# Use a short form of the PYTHONPREFIX_*DIR variables; we don't need the
# base directory in the plist file.
PLIST_SUB+=	PYTHON_INCLUDEDIR=${PYTHONPREFIX_INCLUDEDIR:S;${PREFIX}/;;} \
		PYTHON_LIBDIR=${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;} \
		PYTHON_PLATFORM=${PYTHON_PLATFORM} \
		PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} \
		PYTHON_VERSION=${PYTHON_VERSION} \
		PYTHON_VER=${PYTHON_VER}

_USES_POST+=	python
.endif # _INCLUDE_USES_PYTHON_MK

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PYTHON_POST_MK)
_INCLUDE_USES_PYTHON_POST_MK=	yes

# py-distutils support
PYDISTUTILS_CONFIGURE_TARGET?=	config
PYDISTUTILS_BUILD_TARGET?=	build
PYDISTUTILS_INSTALL_TARGET?=	install

.if defined(_PYTHON_FEATURE_DISTUTILS)
LDSHARED?=	${CC} -shared
MAKE_ENV+=	LDSHARED="${LDSHARED}" PYTHONDONTWRITEBYTECODE= PYTHONOPTIMIZE=

.if !target(do-configure) && !defined(HAS_CONFIGURE) && !defined(GNU_CONFIGURE)
do-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_CONFIGURE_TARGET} ${PYDISTUTILS_CONFIGUREARGS})
.endif

.if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})
.endif

.if !target(do-install)
do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
.endif

add-plist-post: add-plist-egginfo
.endif # defined(_PYTHON_FEATURE_DISTUTILS)
.endif # defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PYTHON_POST_MK)
