# New ports collection makefile for:	maven
# Date created:				17 October 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=	maven
PORTVERSION=	1.0.r2
CATEGORIES=	devel java
MASTER_SITES=	http://nagoya.apache.org/mirror/%SUBDIR%/binaries/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.0-rc2

MAINTAINER=	rui@ruilopes.com
COMMENT=	Java project management and project comprehension tool

USE_BZIP2=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.3+
NO_BUILD=	YES
DIR=		share/java/maven
PLIST_SUB=	DIR=${DIR}
PKGMESSAGE=	${WRKDIR}/pkg-message

post-configure:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%DIR%%,${DIR},g' pkg-message > ${PKGMESSAGE}

do-install:
	@cd ${WRKSRC} && ${FIND} . \! -name '*.bat' \! -name repository \
		| ${CPIO} -pduv -R ${LIBOWN}:${LIBGRP} ${PREFIX}/${DIR}
	${CHMOD} -R ${LIBMODE} ${PREFIX}/${DIR}
	${CHOWN} -R ${BINOWN}:${BINGRP} ${PREFIX}/${DIR}/bin
	${CHMOD} -R ${BINMODE} ${PREFIX}/${DIR}/bin
	${CHOWN} ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${DIR}/bin/*.conf
	${CHMOD} ${SHAREMODE} ${PREFIX}/${DIR}/bin/*.conf
	${FIND} ${PREFIX}/${DIR} -type d | ${XARGS} ${CHMOD} +rx
	${LN} -fs ${PREFIX}/${DIR}/bin/maven ${PREFIX}/bin

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(/usr/ports/Tools/scripts/plist -d -m /etc/mtree/BSD.local.dist ${PREFIX}|sed -E 's,^share/nls/.+$$,,g;s,${DIR},%%DIR%%,g'|tr -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
