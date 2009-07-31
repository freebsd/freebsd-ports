# New ports collection makefile for:	rayshade
# Date created:		21 January 1998
# Whom:			giffunip@asme.org
#
# $FreeBSD$
#

PORTNAME=	rayshade
PORTVERSION=	4.0.6
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://graphics.stanford.edu/pub/rayshade/	\
		ftp://ftp.princeton.edu/pub/Graphics/rayshade.4.0/
DISTNAME=	${PORTNAME}.${PORTVERSION}
EXTRACT_SUFX=	.tar.Z
.ifndef NOPORTDOCS
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} guide.ps.Z
.endif
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An extensible system for creating ray-traced images

BUILD_DEPENDS=	$(LOCALBASE)/lib/librle.a:${PORTSDIR}/graphics/urt

DIST_SUBDIR=	rayshade

WRKSRC=		${WRKDIR}/${PORTNAME}.4.0
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
ALL_TARGET=

.if defined (BATCH) || defined(PACKAGE_BUILDING)
CONFIGURE_ARGS=	< ${WRKDIR}/config.ans
pre-configure:
	@${MKDIR} ${PREFIX}/bin
	${CP} ${FILESDIR}/config.ans ${WRKDIR}/config.ans
	${REINPLACE_CMD} -e "s,@CFLAGS@,${CFLAGS},g ; \
			     s,@CC@,${CC},g ; \
			     s,@LOCALBASE@,${LOCALBASE},g ; \
			     s,@PREFIX@,${PREFIX},g" ${WRKDIR}/config.ans
.endif

do-install:
	$(INSTALL_PROGRAM) $(WRKSRC)/rayshade/rayshade $(PREFIX)/bin
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/guide.ps.Z ${DOCSDIR}
	$(MKDIR) $(PREFIX)/share/examples/rayshade
	$(INSTALL_DATA) $(WRKSRC)/Examples/* $(PREFIX)/share/examples/rayshade
.endif

.include <bsd.port.mk>
