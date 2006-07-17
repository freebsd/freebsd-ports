# ex:ts=8
# Ports collection makefile for:  spim
# Date created:			  Mon Oct 28, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	spim
PORTVERSION=	7.2.1
CATEGORIES=	emulators
MASTER_SITES=	http://www.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	jkoshy@FreeBSD.org
COMMENT=	MIPS R2000 Simulator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		spim.1

PORTDOCS=	cycle.ps.gz spim.ps.gz SPIM.html
PLIST_FILES=	bin/spim %%DATADIR%%/exceptions.s
PLIST_DIRS=	%%DATADIR%%

OPTIONS=	GUI "Graphical user interface" on

.include <bsd.port.pre.mk>

.if defined(WITH_GUI)
USE_XLIB=	yes
BUILD_DEPENDS+=			imake:${X_IMAKE_PORT}
PLIST_FILES+=	bin/xspim
MAN1+=		xspim.1
.endif

do-configure:

do-build:
	cd ${WRKSRC}/spim && ${MAKE}
.if defined(WITH_GUI)
	cd ${WRKSRC}/xspim && ${XMKMF} && ${MAKE}
.endif

do-install:
	cd ${WRKSRC}/spim && ${MAKE} ${INSTALL_TARGET}
.if defined(WITH_GUI)
	cd ${WRKSRC}/xspim && ${MAKE} ${INSTALL_TARGET}
	${INSTALL_MAN} ${WRKSRC}/Documentation/xspim.man ${PREFIX}/man/man1/xspim.1
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/cycle.ps ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/spim.ps ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/SPIM.html ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/cycle.ps ${DOCSDIR}/spim.ps
.endif

.include <bsd.port.post.mk>
