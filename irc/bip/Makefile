# Created by: Chess Griffin <chess@chessgriffin.com>
# $FreeBSD$

PORTNAME=	bip
PORTVERSION=	0.8.8
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	https://projects.duckcorp.org/attachments/download/39/

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	A simple IRC proxy with SSL support

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib
USE_GMAKE=	yes
INSTALL_TARGET=	SUBDIR=src install-exec

USE_OPENSSL=	yes

PATCH_STRIP=	-p1
PLIST_FILES=	bin/bip bin/bipmkpw
SUB_FILES=	pkg-message
MAN1=		bip.1 bipmkpw.1
MAN5=		bip.conf.5

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TODO

PORTEXAMPLES=	bip.conf bip.vim

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${DOCSDIR}
.endfor
.endif

.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for examples in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/samples/${examples} ${EXAMPLESDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
