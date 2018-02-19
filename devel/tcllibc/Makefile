# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PKGNAMESUFFIX=	c

COMMENT=	Compiled implementations of some of the modules of Tcllib

LICENSE=	TclTk
LICENSE_NAME=	Tcl/Tk License
LICENSE_FILE=	${WRKSRC}/license.terms
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

BUILD_DEPENDS=	critcl:devel/critcl
RUN_DEPENDS=	${LOCALBASE}/lib/tcllib/pkgIndex.tcl:devel/tcllib

USES=		bison
MASTERDIR=	${.CURDIR}/../tcllib
TMPPLIST=	${WRKDIR}/PLIST
DESCR=		${.CURDIR}/pkg-descr
ALL_TARGET=	critcl
OPTIONS_DEFINE=

pre-build:
	cd ${WRKSRC}/modules/json/c && ${LOCALBASE}/bin/bison -b json json.y

do-install:
	${RM} ${WRKSRC}/modules/tcllibc/license.terms
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/tcllib
	${MV} ${WRKSRC}/modules/tcllibc ${STAGEDIR}${PREFIX}/lib/tcllib/
	${SED} -e s,%%PLATFORM%%,`${LOCALBASE}/bin/critcl -show | ${SED} -n 's| *platform *||p'`,\
		${.CURDIR}/pkg-plist > ${TMPPLIST}

.include "${MASTERDIR}/Makefile"
