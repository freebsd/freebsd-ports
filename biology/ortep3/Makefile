# New ports collection makefile for:	ORTEP-III
# Date created:		1999-05-08
# Whom:			Ryo MIYAMOTO
#
# $FreeBSD$
#

PORTNAME=	ortep3
PORTVERSION=	1.0.3
CATEGORIES=	biology
#MASTER_SITES=	ftp://ftp.ccl.net/pub/chemistry/software/SOURCES/FORTRAN/ortep/ 
#		ftp://ftp.ornl.gov/pub/ortep/src/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=alex
DISTFILES=	ortep-1.0.3.tar.Z ortep-1.0.3.f
DISTNAME=	ortep
EXTRACT_ONLY=	ortep.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot

WRKSRC=		${WRKDIR}/${DISTNAME}/src

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400002 && ${OSVERSION} < 400018
BROKEN=	doesn\'t build with new f77 compiler
.endif

post-extract:
	${MV} ${WRKSRC}/ortep.f ${WRKSRC}/ortep.f-1.0
	${CP} ${DISTDIR}/ortep-${PORTVERSION}.f ${WRKSRC}/ortep.f

pre-patch:
	${CP} ${FILESDIR}/Makefile.ortep3 ${WRKDIR}/${DISTNAME}/src/Makefile
.if defined(USEPGPLOT)
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/patch-aa
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/patch-ab
.endif

pre-install:
	${MKDIR} ${PREFIX}/share/doc/ortep3
	${MKDIR} ${PREFIX}/share/doc/ortep3/examples
	${MKDIR} ${PREFIX}/share/doc/ortep3/man
	${MKDIR} ${PREFIX}/share/doc/ortep3/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ortep3 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/examples/* \
	      ${PREFIX}/share/doc/ortep3/examples
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/man/* \
	      ${PREFIX}/share/doc/ortep3/man
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/src/000readme.txt \
	      ${PREFIX}/share/doc/ortep3/src
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/README.1st \
	      ${PREFIX}/share/doc/ortep3

.include <bsd.port.post.mk>
