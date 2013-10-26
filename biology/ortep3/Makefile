# Created by: Ryo MIYAMOTO
# $FreeBSD$

PORTNAME=	ortep3
PORTVERSION=	1.0.3
PORTREVISION=	7
CATEGORIES=	biology
MASTER_SITES=	http://www.ccl.net/cca/software/SOURCES/FORTRAN/ortep/:Z \
		ftp://ftp.ornl.gov/pub/ortep/src/:f
DISTFILES=	ortep.tar.Z:Z ortep.f:f
EXTRACT_ONLY=	ortep.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oak Ridge Thermal Ellipsoid Plot Program for Crystal Structure

PGPLOT_LIB_DEPENDS=	pgplot:${PORTSDIR}/graphics/pgplot

USE_FORTRAN=	yes
WRKSRC=		${WRKDIR}/ortep/src
MAKE_ARGS=	LFLAGS="${LFLAGS}"

PGPLOT_LFLAGS=	-L${LOCALBASE}/lib -lpgplot -lX11

PLIST_FILES+=	bin/ortep3
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES PGPLOT
PGPLOT_DESC=	Fortran subroutine package for drawing graphs

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPGPLOT}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-aa
.endif

post-extract:
	${MV} ${WRKSRC}/ortep.f ${WRKSRC}/ortep.f-1.0
	${CP} ${DISTDIR}/ortep.f ${WRKSRC}/ortep.f

pre-build:
	${CP} ${FILESDIR}/Makefile.ortep3 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ortep3 ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/src
	${INSTALL_DATA} ${WRKSRC}/../README.1st ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../man/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/000readme.txt ${DOCSDIR}/src
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
