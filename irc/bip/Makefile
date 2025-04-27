PORTNAME=	bip
DISTVERSION=	0.9.2
CATEGORIES=	irc
MASTER_SITES=	https://projects.duckcorp.org/attachments/download/103/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Simple IRC proxy with SSL support
WWW=		https://bip.milkypond.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe gmake localbase:ldflags ssl
CPE_VENDOR=	duckcorp

GNU_CONFIGURE=	yes

INSTALL_TARGET=	SUBDIR=src install-exec
TEST_TARGET=	check

CFLAGS+=	-Wno-sign-compare -Wno-error -I${OPENSSLINC}
LDFLAGS+=	-L${OPENSSLLIB}

PATCH_STRIP=	-p1
SUB_FILES=	pkg-message

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TODO

EXAMPLEFILES=	bip.conf bip.vim

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	${INSTALL_MAN} ${WRKSRC}/bip.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/bipmkpw.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/bip.conf.5 ${STAGEDIR}${PREFIX}/share/man/man5

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
