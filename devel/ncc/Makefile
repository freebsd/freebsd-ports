# Ports collection makefile for:  ncc
# Date created:			  February 1, 2006
# Whom:				  Volker Stolz <vs@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ncc
PORTVERSION=	2.8
CATEGORIES=	devel
MASTER_SITES=	http://students.ceid.upatras.gr/~sxanth/ncc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program analysis tool and call-graph navigator

ALL_TARGET=	# empty
MAKE_ARGS+=	CC="${CXX}" LCFLAGS="${CFLAGS}"

CFLAGS+=	-DNOGNU='\"${PREFIX}/include/ncc/nognu\"' -fpermissive

PLIST_FILES=	bin/ncc bin/nccnav bin/nccnavi bin/ncc-gengraph.py \
		${LINKS:S+^+bin/+} include/ncc/nognu
PLIST_DIRS=	include/ncc
PORTDOCS=	*

LINKS=		nccar nccld nccc++ nccg++
MAN1=		ncc.1

post-patch:
	@${REINPLACE_CMD} -e '/NOGNU/d' ${WRKSRC}/config.h
	@${REINPLACE_CMD} -e '/#include <alloca.h>/d' ${WRKSRC}/dbstree.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/objdir/ncc ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/gengraph.py ${PREFIX}/bin/ncc-gengraph.py
	${INSTALL_PROGRAM} ${WRKSRC}/nccnav/nccnav ${PREFIX}/bin
.for i in ${LINKS}
	${LN} -sf ${PREFIX}/bin/ncc ${PREFIX}/bin/$i
.endfor
	${LN} -sf ${PREFIX}/bin/nccnav ${PREFIX}/bin/nccnavi
	${MKDIR} ${PREFIX}/include/ncc
	${INSTALL_DATA}	${WRKSRC}/doc/nognu ${PREFIX}/include/ncc
	${INSTALL_MAN} ${WRKSRC}/ncc.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
