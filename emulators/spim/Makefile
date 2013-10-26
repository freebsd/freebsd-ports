# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	spim
PORTVERSION=	8.0
CATEGORIES=	emulators
MASTER_SITES=	http://pages.cs.wisc.edu/~larus/SPIM/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MIPS32 Simulator

OPTIONS_DEFINE=	GUI DOCS
OPTIONS_DEFAULT=	GUI

BUILD_WRKSRC=	${WRKSRC}/${PORTNAME}
INSTALL_WRKSRC=	${WRKSRC}/${PORTNAME}

ALL_TARGET=	${PORTNAME}

PORTDOCS=	cycle.ps.gz spim.ps.gz SPIM.html
PLIST_FILES=	bin/spim %%DATADIR%%/exceptions.s \
	man/man1/spim.1.gz
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_XORG=	x11 xaw
USES+=		imake:env
PLIST_FILES+=	bin/xspim man/man1/xspim.1.gz
.endif

post-build:
.if ${PORT_OPTIONS:MGUI}
	@(cd ${WRKSRC}/xspim && ${SETENV} ${MAKE_ENV} ${XMKMF} ${XMKMF_ARGS} && \
		${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE})
.endif

do-install:
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/spim ${STAGEDIR}${PREFIX}/bin/spim
	${INSTALL_MAN} ${WRKSRC}/Documentation/spim.man ${STAGEDIR}${MANPREFIX}/man/man1/spim.1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/CPU/exceptions.s ${STAGEDIR}${DATADIR}/exceptions.s
.if ${PORT_OPTIONS:MGUI}
	${INSTALL_PROGRAM} ${WRKSRC}/xspim/xspim ${STAGEDIR}${PREFIX}/bin/xspim
	${INSTALL_MAN} ${WRKSRC}/Documentation/xspim.man ${STAGEDIR}${MANPREFIX}/man/man1/xspim.1
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/cycle.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/TeX/spim.ps ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Documentation/SPIM.html ${STAGEDIR}${DOCSDIR}
	${GZIP_CMD} ${STAGEDIR}${DOCSDIR}/cycle.ps ${STAGEDIR}${DOCSDIR}/spim.ps

.include <bsd.port.mk>
