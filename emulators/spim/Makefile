# ex:ts=8
# Ports collection makefile for:  spim
# Date created:			  Mon Oct 28, 1996
# Whom:				  David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

PORTNAME=	spim
PORTVERSION=	7.5
CATEGORIES=	emulators
MASTER_SITES=	http://pages.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIPS32 Simulator

OPTIONS=	GUI "Graphical user interface" on

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

ALL_TARGET=	${PORTNAME}

MAN1=		spim.1
PORTDOCS=	cycle.ps.gz spim.ps.gz SPIM.html
PLIST_FILES=	bin/spim %%DATADIR%%/exceptions.s
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GUI)
USE_XORG=	x11 xaw
BUILD_DEPENDS+=			imake:${PORTSDIR}/devel/imake
PLIST_FILES+=	bin/xspim
MAN1+=		xspim.1
.endif

post-build:
.if !defined(WITHOUT_GUI)
	@(cd ${WRKSRC}/xspim && ${XMKMF} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE})
.endif

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/spim ${PREFIX}/bin/spim
	${INSTALL_MAN} ${WRKSRC}/Documentation/spim.man ${MANPREFIX}/man/man1/spim.1
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CPU/exceptions.s ${DATADIR}/exceptions.s
.if !defined(WITHOUT_GUI)
	${INSTALL_PROGRAM} ${WRKSRC}/xspim/xspim ${PREFIX}/bin/xspim
	${INSTALL_MAN} ${WRKSRC}/Documentation/xspim.man ${MANPREFIX}/man/man1/xspim.1
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/cycle.ps ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/spim.ps ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/SPIM.html ${DOCSDIR}
	${GZIP_CMD} ${DOCSDIR}/cycle.ps ${DOCSDIR}/spim.ps
.endif

.include <bsd.port.post.mk>
