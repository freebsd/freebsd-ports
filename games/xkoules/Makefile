# New ports collection makefile for:	xkoules
# Date created:				11 March 1998
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	xkoules
PORTVERSION=	1.4
CATEGORIES=	games
MASTER_SITES=	http://www.paru.cas.cz/~hubicka/koules/packages/ \
		${MASTER_SITE_SUNSITE}
DISTNAME=	koules${PORTVERSION}
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

.if ${MACHINE_ARCH} == "alpha"
PLIST=		${PKGDIR}/PLIST.alpha
.endif

USE_IMAKE=	yes
MAN6=		xkoules.6
MANCOMPRESSED=	no

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xkoules ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/xkoules
.if ${MACHINE_ARCH} == "i386"
	${INSTALL_PROGRAM} ${WRKSRC}/koules.sndsrv.freebsd ${PREFIX}/share/xkoules
.endif
	${INSTALL_DATA} ${WRKSRC}/sounds/*.raw ${PREFIX}/share/xkoules
	${INSTALL_MAN} ${WRKSRC}/xkoules.6 ${PREFIX}/man/man6
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/xkoules
.for file in ANNOUNCE BUGS Card ChangeLog Koules.FAQ TODO
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/xkoules
.endfor
.endif

.include <bsd.port.mk>
