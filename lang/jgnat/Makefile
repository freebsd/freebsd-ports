# New ports collection makefile for:	jgnat
# Date created:         8 Apr 2000
# Whom:                 Samuel Tardieu <sam@inf.enst.fr>
#
# $FreeBSD$
#

PORTNAME=	jgnat
PORTVERSION=	1.0.p
DISTNAME=	${PORTNAME}-1.0p-src
CATEGORIES=	lang
MASTER_SITES=	ftp://cs.nyu.edu/pub/gnat/jgnat/jgnat-1.0p/split-1.0p/ \
		ftp://ftp.lip6.fr/pub/gnat/jgnat/jgnat-1.0p/split-1.0p/
EXTRACT_SUFX=	.tgz

MAINTAINER=	sam@inf.enst.fr

BUILD_DEPENDS=	${LOCALBASE}/bin/adagcc:${PORTSDIR}/lang/gnat \
		${LOCALBASE}/jdk1.1.8/bin/javac:${PORTSDIR}/java/jdk

USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/jgnat-1.0p/src

LIBDIR=		${PREFIX}/lib/jgnat
ADAINCDIR=	${LIBDIR}/adainclude
ADALIBDIR=	${LIBDIR}/adalib

do-install:
	-${MKDIR} ${LIBDIR}
	-${MKDIR} ${ADAINCDIR}
	-${MKDIR} ${ADALIBDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/* ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/../lib/jgnat.jar ${LIBDIR}
	${INSTALL_DATA} ${WRKSRC}/../lib/jgnat/adainclude/* ${ADAINCDIR}
	${INSTALL_DATA} ${WRKSRC}/../lib/jgnat/adalib/* ${ADALIBDIR}
	${CHMOD} a-r ${ADALIBDIR}/*.ali

.include <bsd.port.mk>
