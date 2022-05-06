PORTNAME=	llvm-base
PORTVERSION=	1
CATEGORIES=	devel lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Install symlinks for llvm toolchain in /usr

# To the extent that anything in this port is copyrightable, it is the
# list of files in the chosen LLVM version which is under the ports
# collection license.
LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${.CURDIR}/../../COPYRIGHT

RUN_DEPENDS=	clang:devel/llvm

PREFIX=		/usr

NO_ARCH=	yes

SUB_FILES=	wrapper.sh

COMMANDS=	cc c++ cpp ld ld.lld objdump

PLIST_FILES=	${COMMANDS:S|^|bin/|}

.include <bsd.port.pre.mk>

do-build:
	# Do nothing, we can't use DO_BUILD becaue we need SUB_FILES

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/wrapper.sh \
	    ${STAGEDIR}${PREFIX}/bin/cc
.for c in ${COMMANDS:Ncc}
	    ${LN} -s cc ${STAGEDIR}${PREFIX}/bin/${c}
.endfor

.include <bsd.port.mk>
