# New ports collection makefile for:	moneydance
# Date created:		27 Feb 2000
# Whom:			Sean Reilly <sreilly@seanreilly.com>
#
# $FreeBSD$
#

PORTNAME=	moneydance
PORTVERSION=	3.2
PORTREVISION=	1
CATEGORIES=	finance deskutils
MASTER_SITES=	http://moneydance.com/download/3/Unix/
DISTNAME=	${PORTNAME}_other
EXTRACT_ONLY=

MAINTAINER=	sreilly@seanreilly.com
COMMENT=	A Personal Finance Manager

USE_JAVA=	1.3+
RESTRICTED=	Strict license

# Since the vendor's file has not version information in its name:
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

NO_BUILD=	YES
MDSUBDIR=	share/java/moneydance
PLIST_SUB=	MDSUBDIR=${MDSUBDIR}

MDDIR=		${PREFIX}/${MDSUBDIR}

do-install:
	${TAR} -C ${PREFIX}/${MDSUBDIR:H} -xvzpf ${_DISTDIR}/${DISTFILES} \
		--exclude moneydance/swingall.jar \
		--exclude moneydance/moneydance
	${SED} -e 's,%%MDDIR%%,${MDDIR},g' -e 's,%%PREFIX%%,${PREFIX},g' \
		< ${FILESDIR}/moneydance.sh > ${PREFIX}/bin/moneydance
	${CHMOD} 755 ${PREFIX}/bin/moneydance

.include <bsd.port.mk>
