# New ports collection makefile for:	myphpmoney
# Date created:				Sun Mar 09, 2003
# Whom:					courou <courou@users.sourceforge.net>
#
# $FreeBSD$

PORTNAME=		myphpmoney
PORTVERSION=		1.3
CATEGORIES=		finance www
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	myphpmoney
DISTNAME=		${PORTNAME}-${PORTVERSION}RC2

MAINTAINER=		courou@users.sourceforge.net
COMMENT=		A PHP script for managing your accounts

RUN_DEPENDS=		${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4
LIB_DEPENDS=		mysqlclient:${PORTSDIR}/databases/mysql323-client

PREFIX=			${LOCALBASE}
WEBOWN?=		www
WEBGRP?=		www
APACHEDIR=		${PREFIX}/www/data
INSTALLDIR=		${APACHEDIR}/myphpmoney
NO_BUILD=		yes
PLIST=			${WRKDIR}/plist

PLIST_SUB+=		INSTALLDIR=${INSTALLDIR:S,^${PREFIX}/,,}

post-patch:
	${RM} -f ${PLIST}
	cd ${WRKSRC};\
	${FIND} . ! -type d | ${SORT} | ${SED} "s|^.|%%INSTALLDIR%%|"\
		>${PLIST};\
	${FIND} . -type d | ${SORT} -r | ${SED} "s|^.|@dirrm %%INSTALLDIR%%|"\
		>>${PLIST}

do-install:
	${MKDIR} ${INSTALLDIR}
	cd ${WRKSRC}; ${FIND} . \
		| ${CPIO} -pdm -R ${WEBOWN}:${WEBGRP} ${INSTALLDIR}
	${CHMOD} -R ${BINMODE} ${INSTALLDIR}
	${CHMOD} 777 ${INSTALLDIR}/public_html/dump
	${FIND} ${INSTALLDIR} ! -type d | ${XARGS} ${CHMOD} ${NOBINMODE}

.include <bsd.port.mk>
