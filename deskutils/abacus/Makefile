# New ports collection makefile for:	abacus
# Version required:			0.9.13
# Date created:				18 August 1998
# Whom:					Andrey Zakhvatov
#
# $Id: Makefile,v 1.3 1998/09/25 10:07:44 asami Exp $
#

DISTNAME=	abacus
PKGNAME=	abacus-0.9.13
CATEGORIES=	deskutils
MASTER_SITES=	http://www-cad.eecs.berkeley.edu/HomePages/aml/abacus/ \
		http://tahoe.inesc.pt/~aml/abacus/
EXTRACT_SUFX=	.tgz

MAINTAINER=	andy@icc.surw.chel.su

LIB_DEPENDS=	tcl80.1:${PORTSDIR}/lang/tcl80 \
		tk80.1:${PORTSDIR}/x11-toolkits/tk80

ALL_TARGET=	dep tcl_interf/nxlc
USE_GMAKE=	yes
USE_X_PREFIX=	yes
WRKSRC=		${WRKDIR}/${PKGNAME}

MAN1=		abacus.1

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
