# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.17
CATEGORIES=	graphics print
MASTER_SITES=	http://www.geocities.com/SiliconValley/Network/1958/pstoedit/
DISTNAME=	${PORTNAME}_3_17

MAINTAINER=	jseger@FreeBSD.org

RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript55
LIB_DEPENDS=	plot.3:${PORTSDIR}/graphics/plotutils \
		plotter.3:${PORTSDIR}/graphics/plotutils

USE_ZIP=		yes
WRKSRC=		${WRKDIR}/pstoedit_3.17/src
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${PREFIX}/include -I${X11BASE}/include" \
		CXXFLAGS="${CFLAGS} -I${PREFIX}/include -I${X11BASE}/include" \
		LDLIBS="-L${PREFIX}/lib -L${X11BASE}/lib" \
		LIBS="-L${PREFIX}/lib -L${X11BASE}/lib"
ALL_TARGET=	default

MAN1=	pstoedit.1

post-extract:
	${CP} ${WRKSRC}/../config/* ${WRKSRC}

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/pstoedit
	${INSTALL_DATA} ${WRKSRC}/../*.htm ${PREFIX}/share/doc/pstoedit
.endif

.include <bsd.port.mk>
