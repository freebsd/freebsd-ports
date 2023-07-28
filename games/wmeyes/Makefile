PORTNAME=	wmeyes
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://bstern.org/wmeyes/ \
		http://vault.101011010.xyz/distfiles/ \
		http://freebsd.nsu.ru/distfiles/ LOCAL/danfe

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	World's most useless Window Maker dockapp
WWW=		https://bstern.org/wmeyes/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		imake:noman xorg
USE_XORG=	ice sm x11 xext xmu xpm xt

PLIST_FILES=	bin/wmeyes
PORTDOCS=	ChangeLog README

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|Target(|TargetNoMan(|g' ${WRKSRC}/Imakefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
