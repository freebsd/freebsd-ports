PORTNAME=	aspostit
PORTVERSION=	1.3
PORTREVISION=	6
CATEGORIES=	deskutils
MASTER_SITES=	AFTERSTEP/apps/aspostit

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	AfterStep dockable version of XPostIt

LICENSE=	GPLv2+

USES=		gmake jpeg xorg
USE_XORG=	xpm xaw xext x11

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/aspostit man/man1/aspostit.1.gz

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-extract:
	@${LN} -sf aspostit.man ${WRKSRC}/aspostit.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/aspostit ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/aspostit.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.post.mk>
