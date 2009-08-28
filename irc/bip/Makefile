# New ports collection makefile for:   bip
# Date created:        23 October 2007
# Whom:                Chess Griffin <chess@chessgriffin.com>
#
# $FreeBSD$
#

PORTNAME=	bip
PORTVERSION=	0.8.0
CATEGORIES=	irc
MASTER_SITES=	http://bip.t1r.net/downloads/ \
		http://distfiles.gentoo.org/distfiles/ \
		LOCAL/beech

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple IRC proxy with SSL support

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALL_TARGET=	SUBDIR=src install-exec

USE_OPENSSL=	yes

PLIST_FILES=	bin/bip bin/bipmkpw
SUB_FILES=	pkg-message
MAN1=		bip.1 bipmkpw.1
MAN5=		bip.conf.5

PORTDOCS=	AUTHORS BUGS ChangeLog NEWS README TODO

PORTEXAMPLES=	bip.conf bip.vim

.include <bsd.port.pre.mk>

post-install:
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN5} ${MANPREFIX}/man/man5

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.if !defined(NOPORTEXAMPLES)
	@${INSTALL} -d ${EXAMPLESDIR}
	@cd ${WRKSRC}/samples && ${INSTALL_DATA} ${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
