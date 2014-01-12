# Created by: Yoshiaki Uchikawa
# $FreeBSD$

PORTNAME=	mikmod
PORTVERSION=	3.2.5
CATEGORIES=	audio
MASTER_SITES=	SF \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Mod player which plays MTM, STM, XM, MOD, S3M, ULT, UNI, and IT mods

LICENSE=	GPLv2

LIB_DEPENDS=	libmikmod.so:${PORTSDIR}/audio/libmikmod

USES=		gmake
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/mikmod \
		man/man1/mikmod.1.gz \
		%%DATADIR%%/mikmodrc
PLIST_DIRS=	%%DATADIR%%
PORTDOCS=	AUTHORS NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
