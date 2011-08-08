# New ports collection makefile for:	Ming
# Date created:		14 October 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.4.3
PORTREVISION?=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Releases/Ming%20${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Flash 4/5 movie output library with many languages support

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		ungif.5:${PORTSDIR}/graphics/libungif \
		freetype.9:${PORTSDIR}/print/freetype2

CONFLICTS=	ja-ming-[0-9]*

USE_GNOME=	gnomehack
USE_GMAKE=	yes
USE_BISON=	build
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/ming
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

CPPFLAGS=	-I. -I.. -I${LOCALBASE}/include
LDFLAGS=	-L. -L.. -L${LOCALBASE}/lib
CFLAGS+=	${CPPFLAGS}

DOCS=		HISTORY NEWS README TODO
DOCS_UTIL=	README TIPS TODO swftoperl.html

.if defined(SLAVE_PORT)
LIB_DEPENDS+=	ming.5:${PORTSDIR}/graphics/ming
.endif

.if defined(SLAVE_PORT) && ${SLAVE_PORT}=="p5"
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
.endif

post-install:
.if !defined(SLAVE_PORT)
	${INSTALL_SCRIPT} ${WRKSRC}/util/ming-config ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/cws2fws ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/include/ming
	${INSTALL_DATA} ${WRKSRC}/*.h ${PREFIX}/include/ming
	${INSTALL_DATA} ${WRKSRC}/src/*.h ${PREFIX}/include/ming
	@${MKDIR} ${PREFIX}/include/ming/util
	${INSTALL_DATA} ${WRKSRC}/util/*.h ${PREFIX}/include/ming/util
	${INSTALL_DATA} ${WRKSRC}/util/png2dbl.c ${PREFIX}/include/ming/util
	@${MKDIR} ${PREFIX}/include/ming/blocks
	${INSTALL_DATA} ${WRKSRC}/src/blocks/*.h ${PREFIX}/include/ming/blocks
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/util
.for docs_utils in ${DOCS_UTIL}
	@${INSTALL_DATA} ${WRKSRC}/util/${docs_utils} ${DOCSDIR}/util
.endfor
.endif
.endif

.if defined(SLAVE_PORT) && ${SLAVE_PORT}=="p5"
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/examples/*.* ${EXAMPLESDIR}
.endif
.endif

pre-install:
.if defined(SLAVE_PORT) && ${SLAVE_PORT}=="p5"
	@${REINPLACE_CMD} 's/3pm/3/g' ${INSTALL_WRKSRC}/Makefile
	@${REINPLACE_CMD} 's/3pm/3/g' ${INSTALL_WRKSRC}/Makefile.perl
.for m in ${MAN3}
	${MV} ${INSTALL_WRKSRC}/blib/man3/${m}pm ${INSTALL_WRKSRC}/blib/man3/${m}
.endfor
.endif

.include <bsd.port.mk>
