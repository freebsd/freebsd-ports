PORTNAME=	llvm
PORTVERSION=	4
CATEGORIES=	devel lang
MASTER_SITES=	# not applicable
DISTFILES=	# not applicable
PKGNAMESUFFIX=	-${FLAVOR}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Install symlinks for llvm toolchain in ${PREFIX}

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${FILESDIR}/LICENSE.ETC

FLAVORS=	base localbase
FLAVOR?=	${FLAVORS:[1]}

RUN_DEPENDS=	clang:devel/llvm

.if ${FLAVOR:Mlocalbase}
CONFLICTS_INSTALL=	binutils
.endif

.if ${FLAVOR:Mbase}
PREFIX=		/usr
.endif

NO_ARCH=	yes

SUB_FILES=	wrapper.sh

COMMANDS=	cc c++ cpp ld objdump
.if ${FLAVOR:Mbase}
# Conflicts with devel/llvm in localbase flavor
COMMANDS+=	ld.lld
.endif

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
