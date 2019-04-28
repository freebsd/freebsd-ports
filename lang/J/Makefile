# $FreeBSD$

PORTNAME=	J
PORTVERSION=	${JVERSION:S/^j//:S/-release//}
PORTEPOCH=	1
CATEGORIES=	lang math

MAINTAINER=	sevenjp@gmail.com
COMMENT=	J programming language

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/jsource-${JVERSION}/license.txt

ONLY_FOR_ARCHS_REASON_amd64=	Not built or tested for other archs. i386 needs hostdefs and netdefs files to be generated.

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpcre2-8.so:devel/pcre2 \
		libsqlite3.so:databases/sqlite3

USES+=		libedit gmake shebangfix uidfix

SHEBANG_GLOB=	*.sh

SUB_FILES=	jconsole profile.ijs

USE_GITHUB=	yes
GH_ACCOUNT=	jsoftware
GH_PROJECT=	jsource
GH_TAGNAME=	${JVERSION}

# J is released with ports-unfriendly versioning
JVERSION=	j807-release

BIN_FILES=	jconsole
LIB_FILES=	libj.so libtsdll.so

OPTIONS_DEFINE=	OPENMP

OPENMP_DESC=	Build with OpenMP support
OPENMP_USES=	compiler:openmp
OPENMP_MAKE_ENV=	USE_OPENMP=1
OPENMP_LIB_DEPENDS=	libgomp.so:lang/gcc7

# J wants to install jconsole, also provided by openjdk
CONFLICTS_INSTALL=	openjdk6 \
		openjdk6-jre \
		openjdk7 \
		openjdk7-jre \
		openjdk8 \
		openjdk8-jre

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/j/bin
	${MKDIR} ${STAGEDIR}${PREFIX}/share/j/system
	${MKDIR} ${STAGEDIR}${PREFIX}/share/j/addons
	${INSTALL_PROGRAM} ${BIN_FILES:C!^!${WRKDIR}/jbld/j64/bin/!} ${STAGEDIR}${PREFIX}/lib/j/bin/
	${INSTALL_LIB} ${LIB_FILES:C!^!${WRKDIR}/jbld/j64/bin/!} ${STAGEDIR}${PREFIX}/lib/j/bin # Required by the J runtime
	${INSTALL_DATA} ${WRKDIR}/profile.ijs ${STAGEDIR}${PREFIX}/share/j/
	${INSTALL_SCRIPT} ${WRKDIR}/jconsole ${STAGEDIR}${PREFIX}/bin/
	(cd ${WRKDIR}/jbld/j64/system && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/j/system)
	(cd ${WRKDIR}/jbld/j64/addons && ${COPYTREE_SHARE} \* ${STAGEDIR}${PREFIX}/share/j/addons)

.include <bsd.port.mk>
