PORTNAME=	keystone-engine
DISTVERSION=	0.9.1-3
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	kai@FreeBSD.org
COMMENT=	Keystone Assembler Engine with Python bindings

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.TXT

BROKEN_FreeBSD_11_powerpc64=	fails to install: /wrkdirs/usr/ports/devel/py-keystone-engine/work-py36/keystone-engine-0.9.1-3/src/build/llvm/lib/libkeystone.so: No such file or directory
BROKEN_FreeBSD_12_powerpc64=	fails to install: /wrkdirs/usr/ports/devel/py-keystone-engine/work-py36/keystone-engine-0.9.1-3/src/build/llvm/lib/libkeystone.so: No such file or directory

BUILD_DEPENDS=	cmake:devel/cmake

USES=		pkgconfig python:3.6+
USE_PYTHON=	distutils autoplist

# setup.py loses track of its cwd when it switches over to the CMake build
# process and searches in ${WRKSRC}/src/build/lib instead of ${WRKSRC}/build/lib
# for the Python packages that were built before the CMake build process.
pre-install:
	@${CP} -r ${WRKSRC}/build/lib ${WRKSRC}/src/build/lib

# Next problem: The compiled library is not installed automatically by setup.py
# so it needs to be manually installed and stripped to the appropriate
# directory.
post-install:
	${INSTALL_LIB} ${WRKSRC}/src/build/llvm/lib/libkeystone.so \
	       	${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/keystone

# Even without the both fixes (or hacks?) that were applied beforehand the
# .PLIST.pymodtmp has only the EGG files as a whole. Therefore the
# .PLIST.pymodtmp has to be regenerated in some way - it's a rather "dirty"
# hack to pass the stage-qa target.
#
# Another solution would a static pkg-plist but then the package has to be
# bound to a specific Python version or multiple package must be created for
# specific Python versions.
post-stage:
	@${FIND} ${STAGEDIR} -type f -o -type l | \
	       	${SORT} | ${SED} -e 's|${STAGEDIR}||' \
       		> ${WRKDIR}/.PLIST.pymodtmp

.include <bsd.port.mk>
