# New ports collection makefile for:	SpecTcl1.1
# Date created:		Fri Oct  3 18:50:53 CEST 1997
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	SpecTcl
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	devel tk80
MASTER_SITES=	ftp://ftp.scriptics.com/pub/tcl/guitools/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	wish8.0:${PORTSDIR}/x11-toolkits/tk80

USE_REINPLACE=	yes
NO_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/bin/specJava
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/bin/specTcl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specJava ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/specTcl ${PREFIX}/bin
	${MKDIR} ${PREFIX}/SpecTcl
	${INSTALL_DATA} ${WRKSRC}/changes ${PREFIX}/SpecTcl
	${INSTALL_DATA} ${WRKSRC}/license.terms ${PREFIX}/SpecTcl
	${MKDIR} ${PREFIX}/SpecTcl/lib
	${CP} -r ${WRKSRC}/SpecTcl/* ${PREFIX}/SpecTcl/lib
	${MKDIR} ${PREFIX}/SpecTcl/demo
	${CP} -r ${WRKSRC}/demo/* ${PREFIX}/SpecTcl/demo
	${MKDIR} ${PREFIX}/SpecTcl/examples
	${CP} -r ${WRKSRC}/examples/* ${PREFIX}/SpecTcl/examples

.include <bsd.port.mk>
