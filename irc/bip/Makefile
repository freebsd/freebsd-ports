# Created by: Chess Griffin <chess@chessgriffin.com>
# $FreeBSD$

PORTNAME=	bip
PORTVERSION=	0.8.9
CATEGORIES=	irc
MASTER_SITES=	https://projects.duckcorp.org/attachments/download/61/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Simple IRC proxy with SSL support

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS+=	-Wno-sign-compare -Wno-error
USES=	gmake
INSTALL_TARGET=	SUBDIR=src install-exec

USE_OPENSSL=	yes

PATCH_STRIP=	-p1
SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TODO
EXAMPLEFILES=	bip.conf bip.vim

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

post-install:
	@cd ${WRKSRC} && ${INSTALL} bip.1 ${STAGEDIR}${PREFIX}/man/man1
	@cd ${WRKSRC} && ${INSTALL} bipmkpw.1 ${STAGEDIR}${PREFIX}/man/man1
	@cd ${WRKSRC} && ${INSTALL} bip.conf.5 ${STAGEDIR}${PREFIX}/man/man5

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR}  ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EXAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/samples/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
