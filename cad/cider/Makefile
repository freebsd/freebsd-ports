# New ports collection makefile for:	cider
# Version required:	1b1
# Date created:		1999-12-12
# Whom:			AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	cider1b1
PKGNAME=	cider-1b1
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Cider/new/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	amakawa@jp.FreeBSD.org

USE_XLIB=	yes
NO_WRKSUBDIR=	yes
MAN1=		sconvert.1 nutmeg.1 spice.1 cider.1
MAN3=		mfb.3
MAN5=		mfbcap.5
MLINKS=		spice.1 spice3.1

pre-patch:
	${CP} -f ${WRKSRC}/sim/spice/common/lib/helpdir/spice.txt ${WRKSRC}/sim/cider/common/lib/helpdir/spice.txt

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/examples/spice3
	${INSTALL_DATA} ${WRKSRC}/sim/spice/common/examples/*.cir ${PREFIX}/share/examples/spice3
	${MKDIR} ${PREFIX}/share/examples/cider
	${TAR} -cf - -C ${WRKSRC}/sim/cider/common/examples . | ${TAR} -xf - -C ${PREFIX}/share/examples/cider
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/cider
	${LN} -fs ${PREFIX}/share/spice3/scripts/spinit ${PREFIX}/share/cider/scripts
.endif

.include <bsd.port.mk>
