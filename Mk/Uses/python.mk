# Provide support for Python related ports. This includes detecting Python
# interpreters, ports providing package and modules for python as well as
# consumer ports requiring Python at build or run time.
#
# Feature:	python
# Usage:	USES=python[:version-spec][,arg,...]
# Valid ARGS:	<version-spec>, patch, build, run, test, env
#
# version-spec 	Declarative specification for the Python version(s) the
#		port supports. Subsets and ranges can be specified:
#
#			* <version>
#			* <minimum-version>-<maximum-version>
#			* <minimum-version>+
#			* -<maximum-version>
#
#		Examples:
#
#			USES=python:2.7		# Supports Python 2.7 Only
#			USES=python:3.9+	# Supports Python 3.9 or later
#			USES=python:3.9-3.10	# Supports Python 3.9 to 3.10
#			USES=python:-3.9	# Supports Python up to 3.9
#			USES=python		# Supports 3.9+
#
# NOTE:	<version-spec> should be as specific as possible, matching the versions
#	upstream declares support for, without being incorrect. In particular,
#	USES=python *without* a <version-spec> means 3.9+,
#	including unreleased versions, which is probably incorrect.
#
#	Not specifying a <version-spec> should only be used when a more specific
#	<version-spec> cannot be specified due to syntax limitations, for
#	example: 2.7,3.9-3.10, but even in this case, X.Y+ (2.7+), or -X.Y (-3.9)
#	is preferred and likely more correct.
#
# patch		Python is needed at patch time. Adds dependency to PATCH_DEPENDS.
# build		Python is needed at build time. Adds dependency to BUILD_DEPENDS.
# run		Python is needed at run time. Adds dependency to RUN_DEPENDS.
# test		Python is needed at test time. Adds dependency to TEST_DEPENDS.
# env		Does not depend on Python but needs the environment set up. This
#		is mainly used when depending on flavored python ports, or when a
#		correct PYTHON_CMD is required.  It has the same effect as setting
#		PYTHON_NO_DEPENDS.
#
# If build, run and test are omitted, Python will be added as BUILD_DEPENDS,
# RUN_DEPENDS and TEST_DEPENDS.
# patch is independant, it does not prevent the default build/run/test
# dependency.
# env or PYTHON_NO_DEPENDS can be set to not add any dependencies.
#
# Exported variables:
#
# PYTHON_VERSION	- The chosen Python interpreter including the version,
#			  e.g. python2.7, python3.9, etc.
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
#	cryptography_build
#			- Depend on security/cryptography at build-time.
#
#	cryptography	- Depend on security/cryptography at run-time.
#
#	cryptography_test
#			- Depend on security/cryptography at test-time.
#
#	cython		- Depend on lang/cython at build-time.
#
#	cython_run	- Depend on lang/cython at run-time.
#
#	cython_test	- Depend on lang/cython for tests.
#
#	cython3		- Depend on lang/cython3 at build-time.
#
#	cython3_run	- Depend on lang/cython3 at run-time.
#
#	cython3_test	- Depend on lang/cython3 for tests.
#
#	flavors		- Force creation of flavors for Python 2 and 3 default
#			  versions, where applicable.
#
#	noflavors	- Disable automatic creation of flavors if they would
#			  otherwise be created and they are not wanted.
#
#	allflavors 	- Generate flavors for all possible versions and not
#			  simply the default ones.  Only to be used for py-*
#			  ports that are part of the Python distribution, but
#			  kept as separate ports.
#
#	optsuffix	- Set PKGNAMESUFFIX to PYTHON_PKGNAMESUFFIX if not the
#			  default python version.
#
#	distutils	- Use distutils as do-configure, do-build and
#			  do-install targets. implies flavors.
#
#	pep517		- Follow the PEP-517 standard to build and install wheels
#			  as do-build and do-install targets. implies flavors.
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
#	nose		- Run tests with nose (devel/py-nose)
#
#	nose2		- Run tests with nose2 (devel/py-nose2)
#
#	pytest		- Run tests with latest pytest (devel/py-pytest)
#
#	unittest	- Run tests with unittest
#
#	unittest2	- Run tests with unittest2 (devel/py-unittest2)
#
# PYTHON_CMD		- Python's command line file name, including the
#			  version number (used for dependencies).
#			  default: ${PYTHONBASE}/bin/${PYTHON_VERSION}
#
# PEP517_BUILD_CMD	- Command sequence for a PEP-517 build frontend that builds a wheel.
#			  default: ${PYTHON_CMD} -m build --no-isolation --wheel ${PEP517_BUILD_CONFIG_SETTING}
#
# PEP517_BUILD_DEPEND	- Port needed to execute ${PEP517_BUILD_CMD}.
#			  default: ${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR}
#
# PEP517_BUILD_CONFIG_SETTING
#			- Options for the build backend. Must include -C or --config-setting per option.
#			  default: <empty>
#
# PEP517_INSTALL_CMD	- Command sequence for a PEP-517 install frontend that installs a wheel.
#			  default: ${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.whl
#
# PEP517_INSTALL_DEPEND	- Port needed to execute ${PEP517_INSTALL_CMD}.
#			  default: ${PYTHON_PKGNAMEPREFIX}installer>=0:devel/py-installer@${PY_FLAVOR}
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
# PYTEST_BROKEN_TESTS	- Lists of 'pytest -k' patterns to skip tests which
#			  require fixing.
#			  default: <empty>
#
# PYTEST_IGNORED_TESTS	- Lists of 'pytest -k' patterns to skip tests which are
#			  not expected to pass, e.g. requiring a database access.
#			  default: <empty>
#
# The following variables can be read by ports and must not be modified:
#
# PYTHONBASE		- The installation prefix of the chosen Python
#			  interpreter, e.g. /usr/local
#
# PYTHON_DISTVERSION
#			- Version number suitable for ${DISTVERSION}.
#
# PYTHON_PORTSDIR	- The port directory of the chosen Python interpreter
#
# PYTHON_REL		- The release number of the chosen Python interpreter
#			  without dots, e.g. 20706, 30901, ...
#
# PYTHON_SUFFIX		- The major-minor release number of the chosen Python
#			  interpreter without dots, e.g. 27, 38, ...
#			  Used for prefixes and suffixes.
#
# PYTHON_BASESUFFIX	- PYTHON_SUFFIX without the threaded ABI flag.
#
# PYTHON_TAG		- Defined by PEP 3147, magic tag containing
#			  implementation name and shorthand version,
#			  primarily for bytecode files. Includes
#			  preceding dot, e.g. .cpython-312,
#			  .cpython-313, ...
#
# PYTHON_SOABI		- Defined by PEP 3149, tag containing
#			  implementation name, shorthand version
#			  and ABI tags, primarily for compiled
#			  extension modules. Includes preceding
#			  dot, e.g. .cpython-313, .cpython-313t,
#			  .cpython-313td, ...
#
# PYTHON_MAJOR_VER	- The major release version of the chosen Python
#			  interpreter, e.g. 2, 3, ...
#
# PYTHON_VER		- The major-minor release version of the chosen Python
#			  interpreter, e.g. 2.7, 3.9, ...
#
# PYTHON_BASEVER	- PYTHON_VER without the threaded ABI flag.
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
# PYTHON_PKGNAMESUFFIX
#			- Use this as a ${PKGNAMESUFFIX} to distinguish
#			  packages for different Python versions.
#			  default: -py${PYTHON_SUFFIX}
#
# Using USES=python also will add some useful entries to SUB_LIST and PLIST_SUB:
#
#	PYTHON_INCLUDEDIR=${PYTHONPREFIX_INCLUDEDIR}
#	PYTHON_LIBDIR=${PYTHONPREFIX_LIBDIR}
#	PYTHON_PLATFORM=${PYTHON_PLATFORM}
#	PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR}
#	PYTHON_SUFFIX=${PYTHON_SUFFIX}
#	PYTHON_BASESUFFIX=${PYTHON_BASESUFFIX}
#	PYTHON_VER=${PYTHON_VER}
#	PYTHON_BASEVER=${PYTHON_BASEVER}
#	PYTHON_VERSION=${PYTHON_VERSION}
#
# where PYTHON_INCLUDEDIR, PYTHON_LIBDIR and PYTHON_SITELIBDIR have their PREFIX
# stripped for PLIST_SUB.
#
# PYTHON2 and PYTHON3 will also be set according to the Python version:
#
#	PYTHON2="" PYTHON3="@comment " for Python 2.x
#	PYTHON2="@comment " PYTHON3="" for Python 3.x
#
# PYDISTUTILS_INSTALLNOSINGLE
#			- Deprecated without replacement
#
# Dependency lines of selected Python modules:
#
# PY_SETUPTOOLS			- setuptools port based on USE_PYTHON=distutils
# PYGAME			- pygame port
# PYNUMPY			- NumPy port
# PY_MERCURIAL			- mercurial port, PKGNAME varies based on default
#				  Python version
# PY_BOOST			- Boost Python libraries port
#
# The following variables may be set by the user:
#
# PYTEST_ENABLE_ALL_TESTS	- Enable tests skipped by PYTEST_BROKEN_TESTS
#				  and PYTEST_IGNORED_TESTS.
# PYTEST_ENABLE_BROKEN_TESTS	- Enable tests skipped by PYTEST_BROKEN_TESTS.
# PYTEST_ENABLE_IGNORED_TESTS	- Enable tests skipped by PYTEST_IGNORED_TESTS.
#
# MAINTAINER: python@FreeBSD.org

.if !defined(_INCLUDE_USES_PYTHON_MK)
_INCLUDE_USES_PYTHON_MK=	yes

ZEROREGS_UNSAFE=	yes

# What Python version and what Python interpreters are currently supported?
# When adding a version, please keep the comment in
# Mk/bsd.default-versions.mk in sync.
_PYTHON_VERSIONS=		3.11 3.12 3.10 3.9 2.7 # preferred first
_PYTHON_PORTBRANCH=		3.11		# ${_PYTHON_VERSIONS:[1]}
_PYTHON_BASECMD=		${LOCALBASE}/bin/python
_PYTHON_RELPORTDIR=		lang/python

# List all valid USE_PYTHON features here
_VALID_PYTHON_FEATURES=	allflavors \
			autoplist \
			concurrent \
			cryptography_build \
			cryptography \
			cryptography_test \
			cython \
			cython_run \
			cython_test \
			cython3 \
			cython3_run \
			cython3_test \
			distutils \
			flavors \
			noegginfo \
			noflavors \
			nose \
			nose2 \
			optsuffix \
			pep517 \
			py3kplist \
			pytest \
			pythonprefix \
			unittest \
			unittest2
_INVALID_PYTHON_FEATURES=
.  for var in ${USE_PYTHON}
.    if empty(_VALID_PYTHON_FEATURES:M${var})
_INVALID_PYTHON_FEATURES+=	${var}
.    endif
.  endfor
.  if !empty(_INVALID_PYTHON_FEATURES)
IGNORE=	uses unknown USE_PYTHON features: ${_INVALID_PYTHON_FEATURES}
.  endif

# Make each individual feature available as _PYTHON_FEATURE_<FEATURENAME>
.  for var in ${USE_PYTHON}
_PYTHON_FEATURE_${var:C/=.*$//:tu}=	${var:C/.*=//:S/,/ /g}
.  endfor

# distutils automatically generates flavors depending on the supported
# versions.
.  if defined(_PYTHON_FEATURE_DISTUTILS)
_PYTHON_FEATURE_FLAVORS=	yes
.  endif

# pep517 automatically generates flavors depending on the supported
# versions.
.  if defined(_PYTHON_FEATURE_PEP517)
_PYTHON_FEATURE_FLAVORS=	yes
.  endif

.  if defined(_PYTHON_FEATURE_NOFLAVORS)
.undef _PYTHON_FEATURE_FLAVORS
.  endif

# Make sure that no dependency or some other environment variable
# pollutes the build/run dependency detection
.undef _PYTHON_BUILD_DEP
.undef _PYTHON_RUN_DEP
.undef _PYTHON_TEST_DEP
_PYTHON_ARGS=		${python_ARGS:S/,/ /g}
.  if ${_PYTHON_ARGS:Mpatch}
_PYTHON_PATCH_DEP=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Npatch}
.  endif
.  if ${_PYTHON_ARGS:Mbuild}
_PYTHON_BUILD_DEP=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Nbuild}
.  endif
.  if ${_PYTHON_ARGS:Mrun}
_PYTHON_RUN_DEP=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Nrun}
.  endif
.  if ${_PYTHON_ARGS:Mtest}
_PYTHON_TEST_DEP=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Ntest}
.  endif
.  if ${_PYTHON_ARGS:Menv}
PYTHON_NO_DEPENDS=	yes
_PYTHON_ARGS:=		${_PYTHON_ARGS:Nenv}
.  endif

# The port does not specify a build, run or test dependency, assume all are
# required.
.  if !defined(_PYTHON_BUILD_DEP) && !defined(_PYTHON_RUN_DEP) && \
    !defined(_PYTHON_TEST_DEP) && !defined(PYTHON_NO_DEPENDS)
_PYTHON_BUILD_DEP=	yes
_PYTHON_RUN_DEP=	yes
_PYTHON_TEST_DEP=	yes
.  endif

.  if ${_PYTHON_ARGS} == 2.7
DEV_WARNING+=		"lang/python27 reached End of Life and will be removed somewhere in the future, please convert to a modern version of python"
.  elif ${_PYTHON_ARGS} == 2
DEV_ERROR+=		"USES=python:2 is no longer supported, use USES=python:2.7"
.  elif ${_PYTHON_ARGS} == 3
DEV_ERROR+=		"USES=python:3 is no longer supported, use USES=python:3.9+ or an appropriate version range"
.  endif  # ${_PYTHON_ARGS} == 2.7

_PYTHON_VERSION:=	${PYTHON_DEFAULT}

.  if empty(_PYTHON_ARGS)
_PYTHON_ARGS=	3.9+
.  endif

# Validate Python version whether it meets the version restriction.
_PYTHON_VERSION_CHECK:=		${_PYTHON_ARGS:C/^([1-9]\.[1-9]?[0-9])$/\1-\1/}
_PYTHON_VERSION_MINIMUM_TMP:=	${_PYTHON_VERSION_CHECK:C/([1-9]\.[1-9]?[0-9])[-+].*/\1/}
_PYTHON_VERSION_MINIMUM:=	${_PYTHON_VERSION_MINIMUM_TMP:M[1-9].[0-9]}${_PYTHON_VERSION_MINIMUM_TMP:M[1-9].[1-9][0-9]}
_PYTHON_VERSION_MAXIMUM_TMP:=	${_PYTHON_VERSION_CHECK:C/.*-([1-9]\.[1-9]?[0-9])/\1/}
_PYTHON_VERSION_MAXIMUM:=	${_PYTHON_VERSION_MAXIMUM_TMP:M[1-9].[0-9]}${_PYTHON_VERSION_MAXIMUM_TMP:M[1-9].[1-9][0-9]}

# At this point we should have no argument left in ${_PYTHON_ARGS}
# except a version spec
_V1=		[1-9].[0-9]
_V2=		[1-9].[1-9][0-9]
_PYTHON_ARGS:=	${_PYTHON_ARGS:N${_V1}-${_V1}:N${_V1}-${_V2}:N${_V2}-${_V2}:N${_V1}:N${_V2}:N${_V1}+:N${_V2}+:N-${_V1}:N-${_V2}}
.  if !empty(_PYTHON_ARGS)
IGNORE=	uses unknown USES=python arguments: ${_PYTHON_ARGS}
.  endif

# Pattern to convert python versions (X.Y or X.YY) to comparable format X.YY
_VC=		C/^([1-9]\.)([0-9])$$/\10\2/

.undef _PYTHON_VERSION_NONSUPPORTED
.  if !empty(_PYTHON_VERSION_MINIMUM) && (${_PYTHON_VERSION:${_VC}:S/t$//} < ${_PYTHON_VERSION_MINIMUM:${_VC}:S/t$//})
_PYTHON_VERSION_NONSUPPORTED=	${_PYTHON_VERSION_MINIMUM} at least
.  elif !empty(_PYTHON_VERSION_MAXIMUM) && (${_PYTHON_VERSION:${_VC}:S/t$//} > ${_PYTHON_VERSION_MAXIMUM:${_VC}:S/t$//})
_PYTHON_VERSION_NONSUPPORTED=	${_PYTHON_VERSION_MAXIMUM} at most
.  endif

# If we have an unsupported version of Python, try another.
.  if defined(_PYTHON_VERSION_NONSUPPORTED)
.undef _PYTHON_VERSION
.    for ver in ${PYTHON_DEFAULT} ${PYTHON2_DEFAULT} ${_PYTHON_VERSIONS}
__VER=		${ver}
.      if !defined(_PYTHON_VERSION) && \
	!(!empty(_PYTHON_VERSION_MINIMUM) && ( \
		${__VER:${_VC}:S/t$//} < ${_PYTHON_VERSION_MINIMUM:${_VC}:S/t$//})) && \
	!(!empty(_PYTHON_VERSION_MAXIMUM) && ( \
		${__VER:${_VC}:S/t$//} > ${_PYTHON_VERSION_MAXIMUM:${_VC}:S/t$//}))
_PYTHON_VERSION=	${ver}
.      endif
.    endfor
.    if !defined(_PYTHON_VERSION)
IGNORE=		needs an unsupported version of Python
.    endif
.  endif	# defined(_PYTHON_VERSION_NONSUPPORTED)

# Automatically generates FLAVORS if empty
.  if empty(FLAVORS) && defined(_PYTHON_FEATURE_FLAVORS)
.  undef _VALID_PYTHON_VERSIONS
.    for ver in ${PYTHON_DEFAULT} ${PYTHON2_DEFAULT} ${_PYTHON_VERSIONS}
__VER=		${ver}
.      if !(!empty(_PYTHON_VERSION_MINIMUM) && ( \
		${__VER:${_VC}:S/t$//} < ${_PYTHON_VERSION_MINIMUM:${_VC}:S/t$//})) && \
	!(!empty(_PYTHON_VERSION_MAXIMUM) && ( \
		${__VER:${_VC}:S/t$//} > ${_PYTHON_VERSION_MAXIMUM:${_VC}:S/t$//}))
.        if empty(_VALID_PYTHON_VERSIONS:M${ver})
_VALID_PYTHON_VERSIONS+=	${ver}
.        endif
.      endif
.    endfor
# Get all possible flavors depending on version requirements
.    if defined(_VALID_PYTHON_VERSIONS)
_ALL_PYTHON_FLAVORS=	${_VALID_PYTHON_VERSIONS:S/.//:S/^/py/}
.    else
_ALL_PYTHON_FLAVORS=	${_PYTHON_VERSIONS:S/.//:S/^/py/}
.    endif
# Decide how many flavors we want.  By default, only generate the default
# versions.
.    if defined(BUILD_ALL_PYTHON_FLAVORS) || defined(_PYTHON_FEATURE_ALLFLAVORS)
FLAVORS=	${_ALL_PYTHON_FLAVORS}
.    else
.      for _v in ${PYTHON_DEFAULT} ${PYTHON2_DEFAULT}
_f=	py${_v:S/.//}
.        if ${_ALL_PYTHON_FLAVORS:M${_f}} && !${FLAVORS:M${_f}}
.          if !empty(FLAVORS)
FLAVORS:=	${FLAVORS} ${_f}
.          else
FLAVORS:=	${_f}
.          endif
.        endif
.      endfor
.    endif
.    if !empty(FLAVORS) && empty(FLAVOR)
FLAVOR=	${FLAVORS:[1]}
.    endif
.  endif

.  if ${FLAVOR:Mpy[23][0-9]}${FLAVOR:Mpy[23][1-9][0-9]}${FLAVOR:Mpy31[3-9]t}
_PYTHON_VERSION=	${FLAVOR:S/py//:C/(.)/\1./}
.  endif

.  if !empty(FLAVOR) && ${_PYTHON_VERSION} != ${PYTHON_DEFAULT}
.    if defined(_PYTHON_FEATURE_OPTSUFFIX)
DEV_WARNING+=	"USE_PYTHON=optsuffix is deprecated, consider migrating to using unconditional PKGNAMESUFFIX or PKGNAMEPREFIX"
PKGNAMESUFFIX=	${PYTHON_PKGNAMESUFFIX}
.    endif
.  endif

# To avoid having dependencies with @ and empty flavor:
# _PYTHON_VERSION is either set by (first that matches):
# - If using Python flavors, from the current Python flavor
# - If using a version restriction (USES=python:3.9+), from the first
#   acceptable default Python version.
# - From PYTHON_DEFAULT
PY_FLAVOR=	py${_PYTHON_VERSION:S/.//}

PYTHON_VERSION=	python${_PYTHON_VERSION}

# Got the correct python version, set some publicly accessible variables
PYTHON_VER=		${_PYTHON_VERSION}
PYTHON_BASEVER=		${PYTHON_VER:S/t$//}
PYTHON_SUFFIX=		${_PYTHON_VERSION:S/.//g}
PYTHON_BASESUFFIX=	${PYTHON_SUFFIX:S/t$//}
PYTHON_MAJOR_VER=	${PYTHON_VER:R}
PYTHON_REL=		# empty
PYTHON_ABIVER=		# empty
PYTHON_PORTSDIR=	${_PYTHON_RELPORTDIR}${PYTHON_SUFFIX}

# Protect partial checkouts from Mk/Scripts/functions.sh:export_ports_env().
.  if !defined(_PORTS_ENV_CHECK) || exists(${PORTSDIR}/${PYTHON_PORTSDIR})
.include "${PORTSDIR}/${PYTHON_PORTSDIR:S/t$//}/Makefile.version"
.  endif
# Create a 5 integer version string, prefixing 0 to the minor and patch
# tokens if it's a single character. Only use the first 3 tokens of
# DISTVERSION to stay consistent regardless of pre-release or ABI flags
PYTHON_REL=	${PYTHON_DISTVERSION:C/^([0-9]+\.[0-9]+\.[0-9]+).*/\1/:C/\.([0-9])$/.0\1/:C/\.([0-9]\.[0-9]+)/.0\1/:S/.//g}

# Might be overridden by calling ports
PYTHON_CMD?=		${_PYTHON_BASECMD}${_PYTHON_VERSION}
.  if ${PYTHON_MAJOR_VER} > 2
.    if exists(${PYTHON_CMD}-config)
PYTHON_ABIVER!=		${PYTHON_CMD}-config --abiflags
.    endif
.  endif

.  if ${PYTHON_REL} >= 30807
PYTHON_TAG=	.cpython-${PYTHON_BASESUFFIX}
PYTHON_SOABI=	.cpython-${PYTHON_SUFFIX}
.  else
PYTHON_TAG=	# empty
PYTHON_SOABI=	# empty
.  endif

.  if ${PYTHON_MAJOR_VER} < 3
DEPRECATED?=	Uses Python 2.7 which is EOLed upstream
.  endif

.  if !defined(PYTHONBASE)
PYTHONBASE!=	(${PYTHON_CMD} -c 'import sys; print(sys.prefix)' \
			2> /dev/null || ${ECHO_CMD} ${LOCALBASE}) | ${TAIL} -1
.  endif
_EXPORTED_VARS+=	PYTHONBASE

PYTHON_INCLUDEDIR=	${PYTHONBASE}/include/python${_PYTHON_VERSION}${PYTHON_ABIVER}
PYTHON_LIBDIR=		${PYTHONBASE}/lib/python${_PYTHON_VERSION}
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

# cryptography* support
.  if ${PYCRYPTOGRAPHY_DEFAULT} == rust
CRYPTOGRAPHY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography>=44.0.3,1:security/py-cryptography@${PY_FLAVOR}
.  else
CRYPTOGRAPHY_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cryptography-legacy>=3.4.8_3,1:security/py-cryptography-legacy@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CRYPTOGRAPHY_BUILD)
BUILD_DEPENDS+=	${CRYPTOGRAPHY_DEPENDS}
.  endif

.  if defined(_PYTHON_FEATURE_CRYPTOGRAPHY)
RUN_DEPENDS+=	${CRYPTOGRAPHY_DEPENDS}
.  endif

.  if defined(_PYTHON_FEATURE_CRYPTOGRAPHY_TEST)
TEST_DEPENDS+=	${CRYPTOGRAPHY_DEPENDS}
.  endif

# cython* support

.  if defined(_PYTHON_FEATURE_CYTHON)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.37<3:lang/cython@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CYTHON_RUN)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.37<3:lang/cython@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CYTHON_TEST)
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython>=0.29.37<3:lang/cython@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CYTHON3)
BUILD_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython3>=3.1.2:lang/cython3@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CYTHON3_RUN)
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython3>=3.1.2:lang/cython3@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CYTHON3_TEST)
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}cython3>=3.1.2:lang/cython3@${PY_FLAVOR}
.  endif

.  if defined(_PYTHON_FEATURE_CONCURRENT)
.    if !defined(_PYTHON_FEATURE_FLAVORS) && (${_PYTHON_VERSION_MINIMUM:M3*} || ${_PYTHON_VERSION_MAXIMUM:M2*})
DEV_WARNING+=	"USE_PYTHON=concurrent when only one of Python 2 or 3 is supported AND not using flavors does not make any sense"
.    endif
_USES_POST+=		uniquefiles:dirs
.    if defined(_PYTHON_FEATURE_FLAVORS) && ${FLAVOR} == ${FLAVORS:[1]}
UNIQUE_DEFAULT_LINKS=	yes
.    elif !defined(_PYTHON_FEATURE_FLAVORS) && ${_PYTHON_VERSION} == ${PYTHON_DEFAULT}
UNIQUE_DEFAULT_LINKS=	yes
.    else
UNIQUE_DEFAULT_LINKS=	no
.    endif
UNIQUE_PREFIX=		${PYTHON_PKGNAMEPREFIX}
UNIQUE_SUFFIX=		-${PYTHON_VER}
UNIQUE_SUFFIX_TYPES+=	SUFFIX_MAN
UNIQUE_SUFFIX_MAN_WITH_EXT=	.[1-9ln]
UNIQUE_SUFFIX_MAN_EXTRA_EXT=	.gz

.    if defined(_PYTHON_FEATURE_AUTOPLIST)
_UNIQUE_FIND_SUFFIX_FILES=	${SED} -e 's|^${PREFIX}/||' ${_PYTHONPKGLIST} ${TMPPLIST}
.    else
_UNIQUE_FIND_SUFFIX_FILES=	${SED} -e 's|^${PREFIX}/||' ${TMPPLIST} 2>/dev/null
.    endif
UNIQUE_FIND_SUFFIX_FILES+=	${_UNIQUE_FIND_SUFFIX_FILES} | \
				${EGREP} -he '^bin/.*$$|^sbin/.*$$|^libexec/.*$$'
UNIQUE_FIND_SUFFIX_MAN_FILES+=	${_UNIQUE_FIND_SUFFIX_FILES} | \
				${EGREP} -he '^man/man[1-9ln]/.*$$|^share/man/man[1-9ln]/.*$$'
.  endif # defined(_PYTHON_FEATURE_CONCURRENT)

_CURRENTPORT:=	${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}
.  if defined(_PYTHON_FEATURE_DISTUTILS) && \
	${_CURRENTPORT} != ${PYTHON_PKGNAMEPREFIX}setuptools && \
	${_CURRENTPORT} != ${PYTHON_PKGNAMEPREFIX}setuptools58 && \
	${_CURRENTPORT} != ${PYTHON_PKGNAMEPREFIX}setuptools44
.    if ${PYTHON_VER} == 2.7
BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}setuptools44>0:devel/py-setuptools44@${PY_FLAVOR}
RUN_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}setuptools44>0:devel/py-setuptools44@${PY_FLAVOR}
.    else
BUILD_DEPENDS+=		${PYTHON_PKGNAMEPREFIX}setuptools>=63.1.0:devel/py-setuptools@${PY_FLAVOR}
.    endif
.  endif

.  if defined(_PYTHON_FEATURE_PEP517)
.    if ${PYTHON_MAJOR_VER} < 3
DEV_ERROR+=		"USES=python:2.7 is incompatible with USE_PYTHON=pep517"
.    endif
.    if defined(_PYTHON_FEATURE_DISTUTILS)
DEV_ERROR+=		"USE_PYTHON=distutils is incompatible with USE_PYTHON=pep517"
.    endif
.    if defined(_PYTHON_FEATURE_PY3KPLIST)
DEV_ERROR+=		"USE_PYTHON=py3kplist is incompatible with USE_PYTHON=pep517"
.    endif
.    if defined(_PYTHON_FEATURE_NOEGGINFO)
DEV_ERROR+=		"USE_PYTHON=noegginfo is incompatible with USE_PYTHON=pep517"
.    endif
.  endif

# distutils support
PYSETUP?=		setup.py
PYDISTUTILS_SETUP?=	-c \
	"import sys; import setuptools; \
	__file__='${PYSETUP}'; sys.argv[0]='${PYSETUP}'; \
	exec(compile(open(__file__, 'rb').read().replace(b'\\r\\n', b'\\n'), __file__, 'exec'))"
PYDISTUTILS_CONFIGUREARGS?=	# empty
PYDISTUTILS_BUILDARGS?=		# empty
PYDISTUTILS_INSTALLARGS?=	-c -O1 --prefix=${PREFIX}
.  if defined(_PYTHON_FEATURE_DISTUTILS)
.    if !defined(PYDISTUTILS_INSTALLNOSINGLE)
PYDISTUTILS_INSTALLARGS+=	--single-version-externally-managed
.    endif
PYDISTUTILS_INSTALLARGS+=	--root=${STAGEDIR}
.  endif
PYDISTUTILS_INSTALLARGS:=	--record ${_PYTHONPKGLIST} \
		${PYDISTUTILS_INSTALLARGS}

PYDISTUTILS_PKGNAME?=	${PORTNAME}
PYDISTUTILS_PKGVERSION?=${PORTVERSION}
PYDISTUTILS_EGGINFO?=	${PYDISTUTILS_PKGNAME:C/[^A-Za-z0-9.]+/_/g}-${PYDISTUTILS_PKGVERSION:C/[^A-Za-z0-9.]+/_/g}-py${PYTHON_VER}.egg-info
PYDISTUTILS_EGGINFODIR?=${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}

# PEP-517 support
PEP517_BUILD_CMD?=	${PYTHON_CMD} -m build --no-isolation --wheel ${PEP517_BUILD_CONFIG_SETTING}
PEP517_BUILD_DEPEND?=	${PYTHON_PKGNAMEPREFIX}build>=0:devel/py-build@${PY_FLAVOR}
PEP517_INSTALL_CMD?=	${PYTHON_CMD} -m installer --destdir ${STAGEDIR} --prefix ${PREFIX} ${BUILD_WRKSRC}/dist/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.whl
PEP517_INSTALL_DEPEND?=	${PYTHON_PKGNAMEPREFIX}installer>=0:devel/py-installer@${PY_FLAVOR}

# nose support
.  if defined(_PYTHON_FEATURE_NOSE)
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose>=0:devel/py-nose@${PY_FLAVOR}
.  endif

# nose2 support
.  if defined(_PYTHON_FEATURE_NOSE2)
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}nose2>=0:devel/py-nose2@${PY_FLAVOR}
.  endif

# pytest support
.  if defined(_PYTHON_FEATURE_PYTEST)
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}pytest>=7,1:devel/py-pytest@${PY_FLAVOR}
PYTEST_BROKEN_TESTS?=	# empty
PYTEST_IGNORED_TESTS?=	# empty
_PYTEST_SKIPPED_TESTS?=	# empty
.    if !defined(PYTEST_ENABLE_ALL_TESTS)
.      if !defined(PYTEST_ENABLE_BROKEN_TESTS)
_PYTEST_SKIPPED_TESTS+=	${PYTEST_BROKEN_TESTS}
.      endif
.      if !defined(PYTEST_ENABLE_IGNORED_TESTS)
_PYTEST_SKIPPED_TESTS+=	${PYTEST_IGNORED_TESTS}
.      endif
.    endif # !defined(PYTEST_ENABLE_ALL_TESTS)
_PYTEST_FILTER_EXPRESSION=	${_PYTEST_SKIPPED_TESTS:C/^(.)/and not \1/:tW:C/^and //}
.  endif # defined(_PYTHON_FEATURE_PYTEST)

# unittest2 support
.  if defined(_PYTHON_FEATURE_UNITTEST2)
TEST_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}unittest2>=0:devel/py-unittest2@${PY_FLAVOR}
.  endif

.  if !defined(_PYTHON_FEATURE_NOEGGINFO) && \
	!defined(_PYTHON_FEATURE_AUTOPLIST) && \
	defined(_PYTHON_FEATURE_DISTUTILS) && \
	defined(PYTHON_REL)
_USES_stage+=	933:add-plist-egginfo
add-plist-egginfo:
.    for egginfo in ${PYDISTUTILS_EGGINFO}
	if [ -d "${PYDISTUTILS_EGGINFODIR}/${egginfo}" ]; then \
		${LS} ${PYDISTUTILS_EGGINFODIR}/${egginfo} | while read f; do \
			${ECHO_CMD} ${PYDISTUTILS_EGGINFODIR:S;^${STAGEDIR}${PREFIX}/;;}/${egginfo}/$${f} >> ${TMPPLIST}; \
		done; \
	fi;
.    endfor
.  endif

.  if defined(_PYTHON_FEATURE_AUTOPLIST) && (defined(_PYTHON_FEATURE_DISTUTILS) || defined(_PYTHON_FEATURE_PEP517))
_RELSITELIBDIR=	${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;}
_RELLIBDIR=		${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;}

_USES_stage+=	934:add-plist-pymod
add-plist-pymod:
	@${SED} -e 's|^"\(.*\)"$$|\1|' \
		-e 's|^${STAGEDIR}${PREFIX}/||' \
		-e 's|^${PREFIX}/||' \
		-e 's|^\(man/.*man[0-9]\)/\(.*\.[0-9]\)$$|\1/\2.gz|' \
		-e 's|^\(share/man/.*man[0-9]\)/\(.*\.[0-9]\)$$|\1/\2.gz|' \
		-e 's|[[:alnum:]|[:space:]]*/\.\./*||g; s|/\./|/|g' \
		${_PYTHONPKGLIST} | ${SORT} >> ${TMPPLIST}

.  else
.    if ${PYTHON_REL} >= 30200 && defined(_PYTHON_FEATURE_PY3KPLIST)
# When Python version is 3.2+ we rewrite all the filenames
# of TMPPLIST that end with .py[co], so that they conform
# to PEP 3147 (see https://www.python.org/dev/peps/pep-3147/)
_PYMAGICTAG=		${PYTHON_CMD} -c 'import sys; print(sys.implementation.cache_tag)'
_USES_stage+=	935:add-plist-python
add-plist-python:
	@${AWK} '\
		/\.py[co]$$/ && !($$0 ~ "/" pc "/") {id = match($$0, /\/[^\/]+\.py[co]$$/); if (id != 0) {d = substr($$0, 1, RSTART - 1); dirs[d] = 1}; sub(/\.pyc$$/,  "." mt "&"); sub(/\.pyo$$/, "." mt "." pyo); sub(/[^\/]+\.py[co]$$/, pc "/&"); print; next} \
		/^@dirrm / {d = substr($$0, 8); if (d in dirs) {print $$0 "/" pc}; print $$0; next} \
		/^@dirrmtry / {d = substr($$0, 11); if (d in dirs) {print $$0 "/" pc}; print $$0; next} \
		{print} \
		' \
		pc="__pycache__" mt="$$(${_PYMAGICTAG})" pyo="opt-1.pyc" \
		${TMPPLIST} > ${TMPPLIST}.pyc_tmp
	@${MV} ${TMPPLIST}.pyc_tmp ${TMPPLIST}
.    endif # ${PYTHON_REL} >= 30200 && defined(_PYTHON_FEATURE_PY3KPLIST)
.  endif # defined(_PYTHON_FEATURE_AUTOPLIST) && (defined(_PYTHON_FEATURE_DISTUTILS) || defined(_PYTHON_FEATURE_PEP517))

# Fix for programs that build python from a GNU auto* environment
CONFIGURE_ENV+=	PYTHON="${PYTHON_CMD}"

# By default CMake picks up the highest available version of Python package.
# Enforce the version required by the port or the default.
CMAKE_ARGS+=	-DPython_ADDITIONAL_VERSIONS=${PYTHON_VER}
CMAKE_ARGS+=	-DPython_EXECUTABLE:FILEPATH="${PYTHON_CMD}"
CMAKE_ARGS+=	-DPython${PYTHON_MAJOR_VER}_EXECUTABLE:FILEPATH="${PYTHON_CMD}"

# Python 3rd-party modules
PYGAME=		${PYTHON_PKGNAMEPREFIX}game>0:devel/py-game@${PY_FLAVOR}
PYNUMPY=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16,1<1.27,1:math/py-numpy@${PY_FLAVOR}

.  if defined(_PYTHON_FEATURE_DISTUTILS)
.    if ${PYTHON_MAJOR_VER} < 3
PY_SETUPTOOLS=	${PYTHON_PKGNAMEPREFIX}setuptools44>0:devel/py-setuptools44@${PY_FLAVOR}
.    else
#PY_SETUPTOOLS=	${PYTHON_PKGNAMEPREFIX}setuptools58>0:devel/py-setuptools58@${PY_FLAVOR}
PY_SETUPTOOLS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
.    endif
.  else
PY_SETUPTOOLS=	${PYTHON_PKGNAMEPREFIX}setuptools>0:devel/py-setuptools@${PY_FLAVOR}
.  endif

# Common Python modules that can be needed but only for some versions of Python.
.  if ${PYTHON_REL} < 31100
PY_EXCEPTIONGROUP=	${PYTHON_PKGNAMEPREFIX}exceptiongroup>=1.1.1:devel/py-exceptiongroup@${PY_FLAVOR}
PY_TOMLI=		${PYTHON_PKGNAMEPREFIX}tomli>=2.2.1<3:textproc/py-tomli@${PY_FLAVOR}
PY_TYPING_EXTENSIONS=	${PYTHON_PKGNAMEPREFIX}typing-extensions>0:devel/py-typing-extensions@${PY_FLAVOR}
.  endif

.  if ${PYTHON_REL} >= 30000
PY_PILLOW=	${PYTHON_PKGNAMEPREFIX}pillow>=7.0.0:graphics/py-pillow@${PY_FLAVOR}
.  endif

.  if ${PYTHON_VER} != ${PYTHON_DEFAULT}
PY_MERCURIAL=	${PYTHON_PKGNAMEPREFIX}mercurial>=5.9:devel/mercurial@${PY_FLAVOR}
.  else
PY_MERCURIAL=	mercurial>=5.9:devel/mercurial@${PY_FLAVOR}
.  endif

CMAKE_ARGS+=	-DBOOST_PYTHON_SUFFIX:STRING=${PYTHON_SUFFIX}
PY_BOOST_LIB=	boost_python${PYTHON_SUFFIX}
PY_BOOST=	lib${PY_BOOST_LIB}.so:devel/boost-python-libs@${PY_FLAVOR}

# dependencies
.  for _stage in PATCH BUILD RUN TEST
.    if defined(_PYTHON_${_stage}_DEP)
${_stage}_DEPENDS+=	${PYTHON_CMD}:${PYTHON_PORTSDIR}
.    endif
.  endfor

# set $PREFIX as Python's one
.  if defined(_PYTHON_FEATURE_PYTHONPREFIX)
PREFIX=		${PYTHONBASE}
.  endif

# Substitutions for SUB_FILES
SUB_LIST+=	PYTHON_INCLUDEDIR=${PYTHONPREFIX_INCLUDEDIR} \
		PYTHON_LIBDIR=${PYTHONPREFIX_LIBDIR} \
		PYTHON_PLATFORM=${PYTHON_PLATFORM} \
		PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR} \
		PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYTHON_BASESUFFIX=${PYTHON_BASESUFFIX} \
		PYTHON_TAG=${PYTHON_TAG} \
		PYTHON_SOABI=${PYTHON_SOABI} \
		PYTHON_VER=${PYTHON_VER} \
		PYTHON_BASEVER=${PYTHON_BASEVER} \
		PYTHON_VERSION=${PYTHON_VERSION}

# Substitutions for pkg-plist
# Use a short form of the PYTHONPREFIX_*DIR variables; we don't need the
# base directory in the plist file.
PLIST_SUB+=	PYTHON_INCLUDEDIR=${PYTHONPREFIX_INCLUDEDIR:S;${PREFIX}/;;} \
		PYTHON_LIBDIR=${PYTHONPREFIX_LIBDIR:S;${PREFIX}/;;} \
		PYTHON_PLATFORM=${PYTHON_PLATFORM} \
		PYTHON_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;} \
		PYTHON_SUFFIX=${PYTHON_SUFFIX} \
		PYTHON_BASESUFFIX=${PYTHON_BASESUFFIX} \
		PYTHON_TAG=${PYTHON_TAG} \
		PYTHON_SOABI=${PYTHON_SOABI} \
		PYTHON_VER=${PYTHON_VER} \
		PYTHON_BASEVER=${PYTHON_BASEVER} \
		PYTHON_VERSION=${PYTHON_VERSION}
.  if ${PYTHON_MAJOR_VER} < 3
SUB_LIST+=	PYTHON2="" PYTHON3="@comment "
PLIST_SUB+=	PYTHON2="" PYTHON3="@comment "
.  else
SUB_LIST+=	PYTHON2="@comment " PYTHON3=""
PLIST_SUB+=	PYTHON2="@comment " PYTHON3=""
.  endif

_USES_POST+=	python
.endif # _INCLUDE_USES_PYTHON_MK

.if defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PYTHON_POST_MK)
_INCLUDE_USES_PYTHON_POST_MK=	yes

# py-distutils support
PYDISTUTILS_CONFIGURE_TARGET?=	config
PYDISTUTILS_BUILD_TARGET?=	build
PYDISTUTILS_INSTALL_TARGET?=	install

.  if defined(_PYTHON_FEATURE_DISTUTILS)
LDSHARED?=	${CC} -shared
MAKE_ENV+=	LDSHARED="${LDSHARED}" PYTHONDONTWRITEBYTECODE= PYTHONOPTIMIZE=

.    if !target(do-configure) && !defined(HAS_CONFIGURE) && !defined(GNU_CONFIGURE)
do-configure:
	@(cd ${BUILD_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_CONFIGURE_TARGET} ${PYDISTUTILS_CONFIGUREARGS})
.    endif

.    if !target(do-build)
do-build:
	@(cd ${BUILD_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_BUILD_TARGET} ${PYDISTUTILS_BUILDARGS})
.    endif

.    if !target(do-install)
do-install:
	@(cd ${INSTALL_WRKSRC}; ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PYTHON_CMD} ${PYDISTUTILS_SETUP} ${PYDISTUTILS_INSTALL_TARGET} ${PYDISTUTILS_INSTALLARGS})
.    endif
.  endif # defined(_PYTHON_FEATURE_DISTUTILS)

.  if defined(_PYTHON_FEATURE_PEP517)
.    if !empty(PEP517_BUILD_DEPEND)
BUILD_DEPENDS+=	${PEP517_BUILD_DEPEND}
.    endif
.    if !empty(PEP517_INSTALL_DEPEND)
BUILD_DEPENDS+=	${PEP517_INSTALL_DEPEND}
.    endif

.    if !target(do-configure) && !defined(HAS_CONFIGURE) && !defined(GNU_CONFIGURE)
do-configure:
	@${DO_NADA}
.    endif

.    if !target(do-build)
do-build:
	@cd ${BUILD_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PEP517_BUILD_CMD}
.    endif

.    if !target(do-install)
do-install:
	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}
	@cd ${INSTALL_WRKSRC} && ${SETENVI} ${WRK_ENV} ${MAKE_ENV} ${PEP517_INSTALL_CMD}
	@${PYTHON_CMD} -B ${PORTSDIR}/Mk/Scripts/strip_RECORD.py \
		${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME:C|[-_]+|_|g}-${DISTVERSION}*.dist-info/RECORD >> ${_PYTHONPKGLIST}
	@${REINPLACE_CMD} \
		-e '/\.pyc$$/d' \
		-e 's|^|${PYTHONPREFIX_SITELIBDIR}/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../etc/|etc/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../bin/|bin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../include/|include/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../lib/|lib/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libdata/|libdata/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../libexec/|libexec/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../man/|man/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../sbin/|sbin/|' \
		-e 's|^${PYTHONPREFIX_SITELIBDIR}/../../../share/|share/|' \
			${_PYTHONPKGLIST}
	@cd ${STAGEDIR}${PREFIX} && ${FIND} lib -name '*.pyc' >> ${_PYTHONPKGLIST}
.    endif
.  endif # defined(_PYTHON_FEATURE_PEP517)

.  if defined(_PYTHON_FEATURE_NOSE)
.    if !target(do-test)
do-test:
	cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m nose ${TEST_ARGS:NDESTDIR=*} -v
.    endif
.  endif # defined(_PYTHON_FEATURE_NOSE)

.  if defined(_PYTHON_FEATURE_NOSE2)
.    if !target(do-test)
do-test:
	cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m nose2 ${TEST_ARGS:NDESTDIR=*} -v
.    endif
.  endif # defined(_PYTHON_FEATURE_NOSE2)

.  if defined(_PYTHON_FEATURE_PYTEST)
.    if !target(do-test)
do-test:
	cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m pytest -k '${_PYTEST_FILTER_EXPRESSION}' -rs -v -o addopts= ${TEST_ARGS:NDESTDIR=*}
.    endif
.  endif # defined(_PYTHON_FEATURE_PYTEST)

.  if defined(_PYTHON_FEATURE_UNITTEST)
.    if !target(do-test)
do-test:
	cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest ${TEST_ARGS:NDESTDIR=*} -v
.    endif
.  endif # defined(_PYTHON_FEATURE_UNITTEST)

.  if defined(_PYTHON_FEATURE_UNITTEST2)
.    if !target(do-test)
do-test:
	cd ${TEST_WRKSRC} && ${SETENVI} ${WRK_ENV} ${TEST_ENV} ${PYTHON_CMD} -m unittest2 ${TEST_ARGS:NDESTDIR=*} -v
.    endif
.  endif # defined(_PYTHON_FEATURE_UNITTEST2)

.endif # defined(_POSTMKINCLUDED) && !defined(_INCLUDE_USES_PYTHON_POST_MK)
