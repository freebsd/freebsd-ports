PORTNAME=	spellcast
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.eblong.com/zarf/ftp/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Multiplayer fight with spells turn based game for X Window System
WWW=		https://www.eblong.com/zarf/spellcast.html

LICENSE=	MIT

USES=		xorg
USE_XORG=	x11

CFLAGS+=	-Wno-return-type

PLIST_FILES=	bin/spellcast man/man6/spellcast.6.gz
PORTDOCS=	README spelllist.ps

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} >= 1400079
CFLAGS+=	-Wno-error=int-conversion
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/spellcast ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/spellcast.6 ${STAGEDIR}${PREFIX}/man/man6

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
