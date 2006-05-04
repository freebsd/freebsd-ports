# New ports collection makefile for:	abacus
# Date created:				18 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	abacus
PORTVERSION=	0.9.13
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/ \
		http://tahoe.inesc.pt/~aml/abacus/

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	steve
PATCHFILES=	${PORTNAME}-${PORTVERSION}.patch.gz

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Spread sheet for X Window System

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

USE_X_PREFIX=	yes
USE_GMAKE=	yes
MAKE_ENV=	CXX="${CXX}" CXXFLAGS="${CXXFLAGS} -Wno-deprecated" LFLAGS="${LDFLAGS}"
LDFLAGS+=	-L$(X11BASE)/lib -L$(LOCALBASE)/lib
ALL_TARGET=	dep tcl_interf/nxlc

MAN1=		abacus.1

post-extract:
	@(cd ${WRKSRC}; ${FIND} -d . -name RCS -exec ${RM} -rf {} \;)
	@(cd ${WRKSRC}; ${RM} canvas; ${LN} -sf canvas-tcl8.2.2 canvas)

post-patch:
	@${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/abacus

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abacus ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/abacus.1 ${PREFIX}/man/man1
	@${MKDIR} ${PREFIX}/share/abacus
	@${MKDIR} ${PREFIX}/share/abacus/display
	${INSTALL_DATA} ${WRKSRC}/display/*.tcl ${PREFIX}/share/abacus/display
	@${MKDIR} ${PREFIX}/share/abacus/graphics
	${INSTALL_DATA} ${WRKSRC}/graphics/*.tcl ${PREFIX}/share/abacus/graphics
	@${MKDIR} ${PREFIX}/share/abacus/runlib
	${INSTALL_DATA} ${WRKSRC}/runlib/*.tcl ${PREFIX}/share/abacus/runlib
	${INSTALL_DATA} ${WRKSRC}/runlib/version ${PREFIX}/share/abacus/runlib
	@${MKDIR} ${PREFIX}/share/abacus/runlib/bitmaps
	${INSTALL_DATA} ${WRKSRC}/runlib/bitmaps/* ${PREFIX}/share/abacus/runlib/bitmaps
	@${MKDIR} ${PREFIX}/share/abacus/tcl_interf
	${INSTALL_PROGRAM} ${WRKSRC}/tcl_interf/nxlc ${PREFIX}/share/abacus/tcl_interf
	@${MKDIR} ${PREFIX}/share/abacus/doc
	${TAR} -C ${WRKSRC} --exclude abacus.1 -cf - doc | \
		${TAR} -C ${PREFIX}/share/abacus --unlink -xf -
	@${MKDIR} ${PREFIX}/share/examples/abacus
	${INSTALL_DATA} ${WRKSRC}/regressive/* ${PREFIX}/share/examples/abacus

.include <bsd.port.mk>
