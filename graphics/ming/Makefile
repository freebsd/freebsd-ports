# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.4.4
PORTREVISION?=	0
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Releases/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Flash 4/5 movie output library with many languages support

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS=	ja-ming-[0-9]*

CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ming
CPPFLAGS+=	-I. -I.. -I${LOCALBASE}/include
LDFLAGS+=	-L. -L.. -L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
USE_BISON=	build
USE_GMAKE=	yes
USE_GNOME=	gnomehack
USE_LDCONFIG=	yes

DOCS=		HISTORY NEWS README TODO
DOCS_UTIL=	README TIPS TODO swftoperl.html

.if defined(SLAVEPORT)
LIB_DEPENDS+=	ming.5:${PORTSDIR}/graphics/ming
.endif

.if !target(post-install)
post-install:
	${MKDIR} ${PREFIX}/include/ming/ ${PREFIX}/include/ming/blocks/ ${PREFIX}/include/ming/util/
	cd ${WRKSRC}/ && \
		${INSTALL_SCRIPT} util/cws2fws util/ming-config ${PREFIX}/bin/ && \
		${INSTALL_DATA} *.h src/*.h ${PREFIX}/include/ming/ && \
		${INSTALL_DATA} src/blocks/*.h ${PREFIX}/include/ming/blocks/ && \
		${INSTALL_DATA} util/png2dbl.c util/*.h ${PREFIX}/include/ming/util/
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/ ${DOCSDIR}/util/
	cd ${WRKSRC}/ && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}/
	cd ${WRKSRC}/util/ && ${INSTALL_DATA} ${DOCS_UTIL} ${DOCSDIR}/util/
.endif
.endif

.include <bsd.port.mk>
