# New ports collection makefile for: adodb
# Date created:		4 May 2001
# Whom:			abgoeree@uwnet.nl
#
# $FreeBSD$
#

PORTNAME=	adodb
PORTVERSION=	1.12
PORTREVISION=	1
CATEGORIES=	databases www
MASTER_SITES=	http://phplens.com/lens/dl/
DISTNAME=	${PORTNAME}112
EXTRACT_SUFX=	.tgz

MAINTAINER=	abgoeree@uwnet.nl

RUN_DEPENDS=	${LOCALBASE}/libexec/apache/libphp4.so:${PORTSDIR}/www/mod_php4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES

ADODB_DIR=	share/doc/apache/php/adodb

post-patch:
	${PERL} -pi -e 's!^readme\.htm!${PREFIX}/${ADODB_DIR}/readme\.htm!' \
		${WRKSRC}/readme.txt
	${PERL} -pi -e 's!^tute\.htm!${PREFIX}/${ADODB_DIR}/tute\.htm!' \
		${WRKSRC}/readme.txt

do-install:
	${MKDIR} ${PREFIX}/share/doc/adodb
	${MKDIR} ${PREFIX}/${ADODB_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${PREFIX}/share/doc/adodb
	${INSTALL_DATA} ${WRKSRC}/*.php ${PREFIX}/${ADODB_DIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${PREFIX}/${ADODB_DIR}

.include <bsd.port.mk>
