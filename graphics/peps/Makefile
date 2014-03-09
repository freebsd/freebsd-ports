# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	peps
PORTVERSION=	2.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://peps.redprince.net/peps/ \
		ftp://ftp.peps.redprince.net/unix/peps/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Converts EPS images to anti-aliased bitmaps

USE_GHOSTSCRIPT_RUN=	yes
MAKE_ENV=	GSPATH="${LOCALBASE}/bin/gs" GZPATH="/usr/bin/gzip" \
		ETC="${PREFIX}/etc"

PLIST_FILES=	bin/peps \
		etc/peps.mime \
		man/man1/peps.1.gz
PORTDOCS=	peps.pdf

OPTIONS_DEFINE=	DOCS X11
OPTIONS_DEFAULT=	X11

X11_PLIST_FILES=	bin/xpeps

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MX11}
ALL_TARGET=	peps
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/peps ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/xpeps ${STAGEDIR}${PREFIX}/bin
.endif
	${INSTALL_MAN} ${WRKSRC}/peps.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/peps.mime ${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/peps.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
