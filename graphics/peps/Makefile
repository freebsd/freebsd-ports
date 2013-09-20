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

MAN1=		peps.1
PORTDOCS=	peps.pdf
PLIST_FILES=	bin/peps \
		etc/peps.mime


.if defined(WITHOUT_X11)
ALL_TARGET=	peps
.else
PLIST_FILES+=	bin/xpeps
.endif

NO_STAGE=	yes
do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/peps ${PREFIX}/bin
.if !defined(WITHOUT_X11)
	${INSTALL_PROGRAM} ${WRKSRC}/xpeps ${PREFIX}/bin
.endif
	${INSTALL_MAN} ${WRKSRC}/peps.1 ${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/peps.mime ${PREFIX}/etc
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/peps.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
