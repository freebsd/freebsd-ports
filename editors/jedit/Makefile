# New ports collection makefile for:    jedit
# Date created:				22 June 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jedit
PORTVERSION=	4.1.0
PORTREVISION=	1
CATEGORIES=	editors java
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
_DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}install
DISTNAME=	${_DISTNAME:S/0install$/install/}
EXTRACT_SUFX=	.jar
EXTRACT_ONLY=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Powerful programmer's text editor written in Java

USE_JAVA=	1.3+

USE_XLIB=	yes
NO_BUILD=	yes

MAN1=		jedit.1

do-configure:
	@${SED} "s|%%PREFIX%%|${PREFIX}|g ; s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${FILESDIR}/jedit.sh > ${WRKDIR}/jedit.sh

do-install:
	@${SED} "s|%%PREFIX%%|${PREFIX}| ; s|%%WRKDIR%%|${WRKDIR}|" ${FILESDIR}/instscript | \
		${SETENV} CLASSPATH=${DISTDIR}/${DISTNAME}.jar \
		${LOCALBASE}/bin/javavm installer.Install text
	@${INSTALL_SCRIPT} ${WRKDIR}/jedit.sh ${PREFIX}/bin/jedit

.if defined(PARALLEL_PACKAGE_BUILD)
IGNORE=	hang
.endif

.include <bsd.port.mk>
