# $FreeBSD$

PORTNAME=	J
PORTVERSION=	${JVERSION:S/^j//:S/-release//}
CATEGORIES=	lang math

MAINTAINER=	sevenjp@gmail.com
COMMENT=	J programming language

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/jsource-j806-release/license.txt

ONLY_FOR_ARCHS=	amd64
ONLY_FOR_ARCHS_REASON_amd64=	Not built or tested for other archs. i386 needs hostdefs and netdefs files to be generated.

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libpcreposix.so:devel/pcre \
		libsqlite3.so:databases/sqlite3

USES+=		libedit gmake shebangfix uidfix
SHEBANG_GLOB=	*.sh

SUB_FILES=	jconsole profile.ijs

USE_GITHUB=	yes
GH_ACCOUNT=	jsoftware
GH_PROJECT=	jsource
GH_TAGNAME=	${JVERSION}

# J is released with ports-unfriendly versioning
JVERSION=	j806-release

BIN_FILES=	jconsole
LIB_FILES=	libj.so libtsdll.so libjavx.so

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
