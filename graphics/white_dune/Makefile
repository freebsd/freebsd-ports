# ex:ts=8
# Ports collection makefile for:	white_dune
# Date created:			Apr 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	white_dune
PORTVERSION=	0.21.3
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.csv.ica.uni-stuttgart.de/vrml/dune/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}pl${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical VRML97 Editor and animation tool

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_REINPLACE=	yes
USE_MESA=	yes
USE_MOTIF=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--with-optimization \
		--without-devil \
		--with-helpurl="${DOCSDIR}/index.html" \
		--with-nurbssurfaceprotourl="${DOCSDIR}/vrml200x_nurbssurface/NurbsSurfacePROTO.wrl"
ALL_TARGET=	# empty

MAN1=	dune.1

post-patch:
	@${REINPLACE_CMD} -e 's|<values.h>|<limits.h>|g' ${WRKSRC}/src/stdafx.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/nostereodune ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dune.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${TAR} -C ${WRKSRC}/docs -cf - . | \
		${TAR} -C ${DOCSDIR} --unlink -xf -
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.mk>
