# New ports collection makefile for:	ORTEP-III
# Date created:		1999-05-08
# Whom:			Ryo MIYAMOTO
#
# $FreeBSD$
#

PORTNAME=	ortep3
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	biology
MASTER_SITES=	ftp://ftp.ccl.net/pub/chemistry/software/SOURCES/FORTRAN/ortep/ \
		ftp://ftp.ornl.gov/pub/ortep/src/
DISTFILES=	ortep.tar.Z ortep.f
EXTRACT_ONLY=	ortep.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp

.if defined(WITH_PGPLOT)
LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot
.endif

WRKSRC=		${WRKDIR}/ortep/src

post-extract:
	${MV} ${WRKSRC}/ortep.f ${WRKSRC}/ortep.f-1.0
	${CP} ${DISTDIR}/ortep.f ${WRKSRC}/ortep.f

pre-patch:
	${CP} ${FILESDIR}/Makefile.ortep3 ${WRKSRC}/Makefile
.if defined(USEPGPLOT)
	cd ${WRKSRC} && ${PATCH} < ${FILESDIR}/extra-patch-aa
.endif
  
pre-install:
	${MKDIR} ${PREFIX}/share/doc/ortep3
	${MKDIR} ${PREFIX}/share/doc/ortep3/examples
	${MKDIR} ${PREFIX}/share/doc/ortep3/man
	${MKDIR} ${PREFIX}/share/doc/ortep3/src

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ortep3 ${PREFIX}/bin
	${INSTALL_DATA} ${WRKDIR}/ortep/examples/* \
	      ${PREFIX}/share/doc/ortep3/examples
	${INSTALL_DATA} ${WRKDIR}/ortep/man/* \
	      ${PREFIX}/share/doc/ortep3/man
	${INSTALL_DATA} ${WRKDIR}/ortep/src/000readme.txt \
	      ${PREFIX}/share/doc/ortep3/src
	${INSTALL_DATA} ${WRKDIR}/ortep/README.1st \
	      ${PREFIX}/share/doc/ortep3

.include <bsd.port.mk>
