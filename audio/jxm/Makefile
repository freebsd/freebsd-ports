# New ports collection makefile for:	jxm
# Date created:		07 March 2004
# Whom:			Nick Sayer <nsayer@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	jxm
PORTVERSION=	0.9
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	javaxm
DISTNAME=	jxm-${PORTVERSION}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMPCR (USB XM radio) control software

RUN_DEPENDS=	${JDKDIR}/jre/lib/ext/CommDriver.jar:${PORTSDIR}/comms/java-commapi-freebsd

USE_JAVA=	1.4+

do-extract:
	${MKDIR} ${WRKSRC}

do-build:
	@${SED} -e 's,%%PREFIX%%,${PREFIX},g' \
		< ${FILESDIR}/jxm > ${WRKSRC}/jxm

do-install:
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} \
		${PREFIX}/share/java/classes/jxm.jar
	${INSTALL_SCRIPT} ${WRKSRC}/jxm \
		${PREFIX}/bin/jxm

.include <bsd.port.mk>
