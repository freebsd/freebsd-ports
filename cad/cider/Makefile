# New ports collection makefile for:	cider
# Date created:		1999-12-12
# Whom:			AMAKAWA Shuhei <amakawa@jp.FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cider
PORTVERSION=	1.b1
PORTREVISION=	3
CATEGORIES=	cad
MASTER_SITES=	ftp://ic.eecs.berkeley.edu/pub/Cider/new/
DISTNAME=	cider1b1

MAINTAINER=	amakawa@jp.FreeBSD.org
COMMENT=	A mixed-level circuit and device simulator (includes SPICE3)

CONFLICTS=	spice-*
WRKSRC=		${WRKDIR}/sim
USE_XLIB=	yes
MAN1=		sconvert.1 nutmeg.1 spice.1 cider.1
MAN3=		mfb.3
MAN5=		mfbcap.5
MLINKS=		spice.1 spice3.1

pre-patch:
	@${CP} -f ${WRKSRC}/spice/common/lib/helpdir/spice.txt ${WRKSRC}/cider/common/lib/helpdir/spice.txt

post-patch:
	@${LN} -fs ../../../spice/common/util/makelib.sh ${WRKSRC}/cider/common/util
	@${LN} -fs ../../../../spice/common/src/lib/sparse/spdefs.h ${WRKSRC}/cider/common/src/include
	@${CP} -f ${FILESDIR}/Makefile.spice ${WRKSRC}/spice/common/Makefile
	@${CP} -f ${FILESDIR}/Makefile.cider ${WRKSRC}/cider/common/Makefile
	@${CP} -f ${FILESDIR}/FreeBSD ${WRKSRC}/spice/common/conf
	@${CP} -f ${FILESDIR}/FreeBSD ${WRKSRC}/cider/common/conf

do-build:
	@(cd ${WRKSRC}/spice/common && ${SETENV} ${MAKE_ENV} ${MAKE})
	@(cd ${WRKSRC}/cider/common && ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	@(cd ${WRKSRC}/spice/common && ${SETENV} ${MAKE_ENV} ${MAKE} install)
	@(cd ${WRKSRC}/cider/common && ${SETENV} ${MAKE_ENV} ${MAKE} install)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/examples/spice3
	@${INSTALL_DATA} ${WRKSRC}/spice/common/examples/*.cir ${PREFIX}/share/examples/spice3
	@${MKDIR} ${PREFIX}/share/examples/cider
	@${TAR} -cf - -C ${WRKSRC}/cider/common/examples . | ${TAR} -xf - -C ${PREFIX}/share/examples/cider
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/share/examples/cider
.endif
	@${LN} -fs ${PREFIX}/share/spice3/scripts/spinit ${PREFIX}/share/cider/scripts

.include <bsd.port.mk>
