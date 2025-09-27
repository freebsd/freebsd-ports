<!--
ai-master-prompt.md: master prompt file for AI assistants to know how to perform
                     various simple operations on ports and ports tree.
                     AI assistants find it by using the .env file in the root of
                     the repository, or by using relevant environment variables.
                     For example, the Google's gemini AI assistant can use
                     GEMINI_SYSTEM_MD to find this file.

MAINTAINER: yuri@FreeBSD.org
-->

# Project Context: FreeBSD ports

## General Instructions
- Individual port directories are under category directories: {category}/{port directory}
- In order to perform operations on an individual port you need to change directory into this port.
- In every port's directory there is a Makefile.
- WRKDIR of every port can be determined by the command 'make -V WRKDIR'
- WRKSRC of every port can be determined by the command 'make -V WRKSRC'
- When any port is updated, the distinfo file can be regenerated using the 'make makesum' command.
- Any port can download and extract the source files using the 'make patch' command.
- Working directory can be removed (cleaned) using the 'make clean' command.
- PORTREVISION should be removed when DISTVERSION or PORTVERSION is updated.
- Any FreeBSD package that is needed can be installed using the command 'sudo pkg install -A {package name}'.
- In case if any work* directories are present in the port directory before the port update such directories should be removed by the 'make clean' command.
- The USES variable in port's Makefile defines what type of port this is.
  - When USES contains the word 'gmake' this is a port that is built using GNU Make (using the the gmake executable).
  - When USES contains the word 'cmake' this is a port that is built using cmake.
  - When USES contains the word 'python' this is a Python based port.
  - When USES contains the word 'cargo' this is a Rust based port.
  - When USES contains the word 'cabal' this is a Haskell based port.
- Port uses GitHub to fetch distfiles if it has the USE_GITHUB=yes line.
- Every port has a maintainer, maintainer's e-mail address is in the MAINTAINER variable.

### Instructions for ports that use GitHub to fetch distfiles
- GitHub account name of such ports is in GH_ACCOUNT, or otherwise PORTNAME is used as an account name.
- GitHub project name of such ports is in GH_PROJECT, or otherwise PORTNAME is used as a project name.
- The GitHub git URL is constructed as https://github.com/{GH_ACCOUNT}/{GH_PROJECT}.git
- The latest released version of a git URL can be determined using the command '../../Tools/scripts/git-get-latest-remote-version.sh {Git-URL} {DISTVERSIONPREFIX}'

### Instructions for Python based ports
- The latest released version of the software can be determined using the command '../../Tools/scripts/pypi-get-latest-version.sh {python project name}'
- Dependencies need to be updated when the port is updated. They need to be compared with the dependency requirements set in the project.
- setuptools build dependency should never be added to BUILD_DEPENDS, and instead the distutils element should be present in USE_PYTHON.
- numpy dependency should be added as ${PYNUMPY} instead of the usual syntax. No version information should be added in this case.
- pillow dependency should be added as ${PY_PILLOW} instead of the usual syntax. No version information should be added in this case.
- The cython build dependency should never be added to BUILD_DEPENDS. Instead, the cython element should be added to USE_PYTHON for cython dependencies of versions 1.x or 2.x, and the cython3 element should be added to USE_PYTHON for cython dependencies of versions 3.x
- Do not add upper version limits for Python based ports.
- Always replace exact version comparison in dependencies with >=.

### Instructions for Haskell based ports
- Directories of all Haskell ports have the prefix "hs-".
- The latest released version of the software can be determined using the command '../../Tools/scripts/haskell-get-latest-version.sh {haskell project name}'
