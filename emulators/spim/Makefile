# ex:ts=8
# Ports collection makefile for:  spim
# Date created:			  Mon Oct 28, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	spim
PORTVERSION=	7.0
CATEGORIES=	emulators
MASTER_SITES=	http://www.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIPS R2000 Simulator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_XLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure
MAKEFILE=	Makefile.std
ALL_TARGET=	spim xspim
MAN1=		spim.1 xspim.1

PORTDOCS=	cycle.ps.gz
PLIST_FILES=	bin/spim bin/xspim %%DATADIR%%/exceptions.s
PLIST_DIRS=	%%DATADIR%%

post-build:

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/cycle.ps ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/cycle.ps
.endif

.include <bsd.port.mk>
