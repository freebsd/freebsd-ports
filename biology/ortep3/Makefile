# New ports collection makefile for:	ORTEP-III
# Date created:		1999-05-08
# Whom:			Ryo MIYAMOTO
#
# $FreeBSD$
#

PORTNAME=	ortep3
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	biology
MASTER_SITES=	http://www.ccl.net/cca/software/SOURCES/FORTRAN/ortep/:Z \
		ftp://ftp.ornl.gov/pub/ortep/src/:f
DISTFILES=	ortep.tar.Z:Z ortep.f:f
EXTRACT_ONLY=	ortep.tar.Z

MAINTAINER=	rmiya@cc.hirosaki-u.ac.jp
COMMENT=	The Oak Ridge Thermal Ellipsoid Plot Program for Crystal Structure

.if defined(WITH_PGPLOT)
LIB_DEPENDS=	pgplot.5:${PORTSDIR}/graphics/pgplot
.endif

WRKSRC=		${WRKDIR}/ortep/src

MAKE_ARGS=	FFLAGS="${FFLAGS}" LFLAGS="${LFLAGS}"

.if defined(WITH_PGPLOT)
EXTRA_PATCHES=	${FILESDIR}/extra-patch-aa
LFLAGS=		-L${LOCALBASE}/lib -lpgplot -L${X11BASE}/lib -lX11
.endif

post-extract:
	${MV} ${WRKSRC}/ortep.f ${WRKSRC}/ortep.f-1.0
	${CP} ${DISTDIR}/ortep.f ${WRKSRC}/ortep.f

pre-build:
	${CP} ${FILESDIR}/Makefile.ortep3 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ortep3 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/doc/ortep3
	${INSTALL_DATA} ${WRKSRC}/../README.1st \
		${PREFIX}/share/doc/ortep3
	@${MKDIR} ${PREFIX}/share/doc/ortep3/examples
	${INSTALL_DATA} ${WRKSRC}/../examples/* \
		${PREFIX}/share/doc/ortep3/examples
	@${MKDIR} ${PREFIX}/share/doc/ortep3/man
	${INSTALL_DATA} ${WRKSRC}/../man/* \
		${PREFIX}/share/doc/ortep3/man
	@${MKDIR} ${PREFIX}/share/doc/ortep3/src
	${INSTALL_DATA} ${WRKSRC}/000readme.txt \
		${PREFIX}/share/doc/ortep3/src

.include <bsd.port.mk>
