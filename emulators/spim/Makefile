# ex:ts=8
# New ports collection makefile for:    spim
# Version required:     5.8
# Date created:         Mon Oct 28, 1996
# Whom:                 David O'Brien (obrien@cs.ucdavis.edu)
#
# $Id$
#

DISTNAME=	spim
PKGNAME=	spim-5.8
CATEGORIES+=	emulators
MASTER_SITES=	ftp://ftp.cs.wisc.edu/pub/spim/

MAINTAINER=	obrien@cs.ucdavis.edu

PREFIX?=	${LOCALBASE}
NO_WRKSUBDIR=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
USE_IMAKE=	yes
XMKMF=		xmkmf
ALL_TARGET=	y.tab.c depend cl-spim cl-xspim


pre-configure:
	@${RM} -f ${WRKSRC}/y.tab.*
	
pre-install:
	@${MKDIR} -p ${PREFIX}/share/spim && chmod a+rx ${PREFIX}/share/spim

post-install:
	[ -e ${PREFIX}/bin/cl-spim ] &&  \
		/bin/ln -f ${PREFIX}/bin/cl-spim ${PREFIX}/bin/spim
	[ -e ${PREFIX}/bin/cl-xspim ] &&  \
		/bin/ln -f ${PREFIX}/bin/cl-xspim ${PREFIX}/bin/xspim
.if !defined(NOPORTDOCS)
	@${ECHO} "Installing spim/xspim documentation"
	@${MKDIR} -p ${PREFIX}/share/doc/spim  \
		&& chmod a+rx ${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/spim.ps  \
		${PREFIX}/share/doc/spim
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps  \
		${PREFIX}/share/doc/spim
	gzip -9nf ${PREFIX}/share/doc/spim/*.ps
.endif

.include <bsd.port.mk>
