# New ports collection makefile for:	maven
# Date created:				17 October 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=	maven
PORTVERSION=	1.0.r1
PORTREVISION=	1
CATEGORIES=	devel java
MASTER_SITES=	http://nagoya.apache.org/mirror/%SUBDIR%/binaries/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-1.0-rc1

MAINTAINER=	rui@ruilopes.com
COMMENT=	Java project management and project comprehension tool

USE_JAVA=	1.3+
NO_BUILD=	YES
DIR=		share/java/maven
PLIST_SUB=	DIR=${DIR}

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
	@${CAT} ${PKGDIR}/pkg-message

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(/usr/ports/Tools/scripts/plist -d -m /etc/mtree/BSD.local.dist ${PREFIX}|sed -E 's,^share/nls/.+$$,,g;s,${DIR},%%DIR%%,g'|tr -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
