# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	spim
PORTVERSION=	8.0
CATEGORIES=	emulators
MASTER_SITES=	http://pages.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIPS32 Simulator

LICENSE=	BSD3CLAUSE

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

ALL_TARGET=	${PORTNAME}

PORTDOCS=	cycle.ps.gz spim.ps.gz SPIM.html
PLIST_FILES=	bin/spim %%DATADIR%%/exceptions.s \
		man/man1/spim.1.gz

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=GUI

GUI_USE=	XORG=x11,xaw
GUI_USES=	imake:env xorg
GUI_PLIST_FILES=bin/xspim man/man1/xspim.1.gz

post-build-GUI-on:
	@(cd ${WRKSRC}/xspim && ${SETENV} ${MAKE_ENV} ${XMKMF} ${XMKMF_ARGS} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE})

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/spim ${STAGEDIR}${PREFIX}/bin/spim
	${INSTALL_MAN} ${WRKSRC}/Documentation/spim.man ${STAGEDIR}${MANPREFIX}/man/man1/spim.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CPU/exceptions.s ${STAGEDIR}${DATADIR}/exceptions.s

do-install-GUI-on:
	${INSTALL_PROGRAM} ${WRKSRC}/xspim/xspim ${STAGEDIR}${PREFIX}/bin/xspim
	${INSTALL_MAN} ${WRKSRC}/Documentation/xspim.man ${STAGEDIR}${MANPREFIX}/man/man1/xspim.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/cycle.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/spim.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/SPIM.html ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/cycle.ps ${STAGEDIR}${DOCSDIR}/spim.ps

.include <bsd.port.mk>
