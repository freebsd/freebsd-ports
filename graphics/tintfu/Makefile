# ex:ts=8
# Ports collection makefile for:	tintfu
# Date created:			Nov 10, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tintfu
PORTVERSION=	0.0.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
EXTRACT_SUFX=	.jar

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A GraphViz .dot file editor

NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_BUILD=	yes
USE_JAVA=	1.3+

PLIST_FILES=	${JAVAJARDIR:S,^${PREFIX}/,,}/${DISTNAME}.jar \
		bin/tintfu

post-patch:
	@${SED} -e 's,%%JAVAJARDIR%%,${JAVAJARDIR},' \
		-e 's,%%DISTNAME%%,${DISTNAME},' ${FILESDIR}/tintfu > ${WRKSRC}/tintfu

do-install:
	${INSTALL_DATA} ${WRKSRC}/${DISTNAME}.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
