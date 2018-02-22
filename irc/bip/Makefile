# Created by: Chess Griffin <chess@chessgriffin.com>
# $FreeBSD$

PORTNAME=	bip
PORTVERSION=	0.8.9
CATEGORIES=	irc
MASTER_SITES=	https://projects.duckcorp.org/attachments/download/61/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Simple IRC proxy with SSL support

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_SSL=	openssl-devel

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib -L${OPENSSLLIB}
CFLAGS+=	-Wno-sign-compare -Wno-error -I${OPENSSLINC}
USES=		cpe gmake ssl
CPE_VENDOR=	duckcorp
INSTALL_TARGET=	SUBDIR=src install-exec

PATCH_STRIP=	-p1
SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TODO
EXAMPLEFILES=	bip.conf bip.vim

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bip.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bipmkpw.1 ${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/bip.conf.5 ${STAGEDIR}${PREFIX}/man/man5

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
.for i in ${EXAMPLEFILES}
	${INSTALL_DATA} ${WRKSRC}/samples/${i} ${STAGEDIR}${EXAMPLESDIR}
.endfor

.include <bsd.port.mk>
