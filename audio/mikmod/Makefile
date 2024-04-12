PORTNAME=	mikmod
DISTVERSION=	3.2.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Mod player which plays MTM, STM, XM, MOD, S3M, ULT, UNI, and IT mods
WWW=		https://mikmod.sourceforge.net/

LICENSE=	GPLv2

LIB_DEPENDS=	libmikmod.so:audio/libmikmod

USES=				gmake ncurses
GNU_CONFIGURE=			yes

PLIST_FILES=	%%DATADIR%%/mikmodrc \
		bin/mikmod \
		share/man/man1/mikmod.1.gz
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
