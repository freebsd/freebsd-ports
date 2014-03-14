# Created by: Aron Schlesinger <as@bsdgroup.de>
# $FreeBSD$

PORTNAME=	vtiger
DISTVERSION=	5.0.3-ga-release-fix-1
PORTREVISION=	2
CATEGORIES=	german www
MASTER_SITES=	http://forge.vtiger.com/frs/download.php/322/ \
		http://people.bsdgroup.de/~as/freebsd/distfiles/vtiger/
DISTNAME=	de_de.lang

MAINTAINER=	ports@FreeBSD.org
COMMENT=	German messages for vtiger

DEPRECATED=	Depends on expiring www/vtiger
EXPIRATION_DATE=	2014-03-10

WRKSRC=		${WRKDIR}/German_de_de
WWWDIR?=	${PREFIX}/www/${PORTNAME}

RUN_DEPENDS+=	${WWWDIR}/include/language:${PORTSDIR}/www/vtiger

USES=		zip
NO_BUILD=	YES

SUB_FILES=	pkg-message

NO_STAGE=	yes
do-install:
	@${FIND} ${WRKSRC} -type f -exec ${SH} -c '${INSTALL_DATA} -v {} \
	$$(${ECHO} {} | ${SED} -e "s,^${WRKSRC},${WWWDIR},")' \;

post-install:
	@${CAT} ${PKGMESSAGE}

create-plist:
	@${FIND} -s ${WRKSRC} -type f | ${SED} -e 's,^${WRKSRC},%%WWWDIR%%,' > ${PLIST}

.include <bsd.port.mk>
