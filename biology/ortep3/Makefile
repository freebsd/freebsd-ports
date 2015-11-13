# Created by: Ryo MIYAMOTO
# $FreeBSD$

PORTNAME=	ortep3
PORTVERSION=	1.0.3
PORTREVISION=	9
CATEGORIES=	biology
MASTER_SITES=	http://www.ccl.net/cca/software/SOURCES/FORTRAN/ortep/:Z \
		ftp://ftp.ornl.gov/pub/ortep/src/:f
DISTFILES=	ortep.tar.Z:Z ortep.f:f
EXTRACT_ONLY=	ortep.tar.Z

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Oak Ridge Thermal Ellipsoid Plot Program for Crystal Structure

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26

PGPLOT_LIB_DEPENDS=	libpgplot.so:${PORTSDIR}/graphics/pgplot

USES=		fortran
WRKSRC=		${WRKDIR}/ortep/src
MAKE_ARGS=	LFLAGS="${LDFLAGS}"

PGPLOT_LDFLAGS=	-L${LOCALBASE}/lib -lpgplot -lX11

PLIST_FILES+=	bin/ortep3
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES PGPLOT
PGPLOT_DESC=	Fortran subroutine package for drawing graphs

PGPLOT_EXTRA_PATCHES=	${FILESDIR}/extra-patch-aa

post-extract:
	${MV} ${WRKSRC}/ortep.f ${WRKSRC}/ortep.f-1.0
	${CP} ${DISTDIR}/ortep.f ${WRKSRC}/ortep.f

pre-build:
	${CP} ${FILESDIR}/Makefile.ortep3 ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ortep3 ${STAGEDIR}${PREFIX}/bin
do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/src
	${INSTALL_DATA} ${WRKSRC}/../README.1st ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../man/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/000readme.txt ${STAGEDIR}${DOCSDIR}/src
do-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/../examples/* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
