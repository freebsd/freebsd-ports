# New ports collection makefile for:	pstodit
# Date created:		03 July 1998
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pstoedit
PORTVERSION=	3.31
CATEGORIES=	graphics print
MASTER_SITES=	http://home.t-online.de/home/helga.glunz/wglunz/pstoedit/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/graphics/ming:extract
LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming \
		plot.4:${PORTSDIR}/graphics/plotutils \
		plotter.4:${PORTSDIR}/graphics/plotutils
RUN_DEPENDS=	gs:${PORTSDIR}/print/ghostscript-gnu

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}/src

USE_ZIP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	../config/configure
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
ALL_TARGET=	default

MAN1=	pstoedit.1

CPPFLAGS=	-I${LOCALBASE}/include/ming -I${LOCALBASE}/include \
		-I${X11BASE}/include
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib

post-extract:
	@${LN} -sf `cd ${PORTSDIR}/graphics/ming && ${MAKE} -V WRKSRC`/../util \
		${WRKSRC}/util

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../*.htm ${DOCSDIR}
.endif

.include <bsd.port.mk>
