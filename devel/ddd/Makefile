# ex:ts=8
# Ports collection makefile for:  ddd
# Version required:     	  2.0
# Date created:			  Tue Jan 28, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $Id: Makefile,v 1.7 1998/11/14 22:37:37 obrien Exp $
#

DISTNAME=	ddd-3.0.92
CATEGORIES=	devel
MASTER_SITES=	ftp://Xftp.ips.cs.tu-bs.de/pub/local/softech/ddd/src/  \
		ftp://richb-pc.acc.qc.edu/pub/ddd/src/  \
		ftp://ftp.gre.ac.uk/pub/tools/debuggers/ddd/src/  \
		ftp://uiarchive.cso.uiuc.edu/pub/packages/ddd/src/  \
		ftp://ftp.th-darmstadt.de/pub/programming/tools/ddd/src/

MAINTAINER=     obrien@NUXI.com

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
REQUIRES_MOTIF=	yes
MAN1=		ddd.1

post-configure:
	echo "LIBXM = ${MOTIFLIB}" >> ${WRKSRC}/ddd/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/PROBLEMS ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/README ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd-paper.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/ddd.man.ps ${PREFIX}/share/doc/ddd
	${INSTALL_DATA} ${WRKSRC}/doc/sample.dddinit ${PREFIX}/share/doc/ddd
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd-paper.ps
	${GZIP_CMD} ${PREFIX}/share/doc/ddd/ddd.man.ps
.endif

check:
	(cd ${WRKSRC} ; ${GMAKE} check)

.include <bsd.port.mk>
