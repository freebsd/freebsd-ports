# New ports collection makefile for:	meta-cvs
# Date created:		13 February 2003
# Whom:			johs
#
# $FreeBSD$
#

PORTNAME=	meta-cvs
PORTVERSION=	1.0.9
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://users.footprints.net/~kaz/
DISTNAME=	mcvs-${PORTVERSION}

MAINTAINER=	johs@copyleft.no
COMMENT=	A more capable version control system than CVS, built around CVS

BUILD_DEPENDS=	clisp:${PORTSDIR}/lang/clisp

USE_GCC=	2.95

pre-build:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile
	${CP} ${FILESDIR}/build.sh ${WRKSRC}/code

post-install:
	${SED} 's:PREFIX:${PREFIX}:g' ${FILESDIR}/mcvs.tmpl > ${WRKDIR}/mcvs
	${INSTALL_SCRIPT} ${WRKDIR}/mcvs ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Meta-CVS-PAPER ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/QUICK-GUIDE ${DOCSDIR}
.endif

.include <bsd.port.mk>
