# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.30
CATEGORIES=	graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu
LIB_DEPENDS=	plot.4:${PORTSDIR}/graphics/plotutils \
		plotter.4:${PORTSDIR}/graphics/plotutils

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}/src

USE_ZIP=		yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../config/configure
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-L${LOCALBASE}/lib -L${X11BASE}/lib"
CONFIGURE_ARGS=	--libdir=${DATADIR}
ALL_TARGET=	default

MAN1=	pstoedit.1

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../*.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
