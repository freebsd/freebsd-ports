# New ports collection makefile for:	abacus
# Date created:				18 August 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	abacus
PORTVERSION=	0.9.13
CATEGORIES=	deskutils
MASTER_SITES=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/ \
		http://tahoe.inesc.pt/~aml/abacus/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

PATCH_SITES=	http://people.FreeBSD.org/~steve/distfiles/
PATCHFILES=	${PKGNAME}.patch.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

ALL_TARGET=	dep tcl_interf/nxlc
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		abacus.1

pre-patch:
	@ (cd ${WRKSRC}; find -d . -name RCS -exec ${RM} -rf {} \;)

post-patch:
	@ (cd ${WRKSRC}; ${RM} canvas; ${LN} -sf canvas-tcl8.2.2 canvas)

do-install:
	@ ${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@ ${INSTALL_MAN} ${WRKSRC}/doc/${DISTNAME}.1 ${PREFIX}/man/man1
	@ ${MKDIR} ${PREFIX}/share/abacus
	@ ${MKDIR} ${PREFIX}/share/abacus/display
	@ ${INSTALL_DATA} ${WRKSRC}/display/*.tcl ${PREFIX}/share/abacus/display
	@ ${MKDIR} ${PREFIX}/share/abacus/graphics
	@ ${INSTALL_DATA} ${WRKSRC}/graphics/*.tcl ${PREFIX}/share/abacus/graphics
	@ ${MKDIR} ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/*.tcl ${PREFIX}/share/abacus/runlib
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/version ${PREFIX}/share/abacus/runlib
	@ ${MKDIR} ${PREFIX}/share/abacus/runlib/bitmaps
	@ ${INSTALL_DATA} ${WRKSRC}/runlib/bitmaps/* ${PREFIX}/share/abacus/runlib/bitmaps
	@ ${MKDIR} ${PREFIX}/share/abacus/tcl_interf
	@ ${INSTALL_PROGRAM} ${WRKSRC}/tcl_interf/nxlc ${PREFIX}/share/abacus/tcl_interf
	@ ${MKDIR} ${PREFIX}/share/examples/abacus
	@ ${INSTALL_DATA} ${WRKSRC}/regressive/* ${PREFIX}/share/examples/abacus

post-install:
.if !defined(NOPORTDOCS)
	@ ${RM} -fr ${WRKSRC}/doc/RCS ${WRKSRC}/doc/help/RCS
	@ ${MKDIR} ${PREFIX}/share/doc/abacus
	@ cd ${WRKSRC}/doc; tar --exclude ${DISTNAME}.1 -cf - . | \
		(cd ${PREFIX}/share/doc/abacus; tar --unlink -xf - )
.endif

.include <bsd.port.mk>
