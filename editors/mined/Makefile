# New ports collection makefile for:	mined
# Date created:		24 December 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	mined
PORTVERSION=	2000.10
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support

MAKEFILE=	makefile

.if defined(NOPORTDOCS)
ALL_TARGET=	mined manual
.else
PORTDOCS=	cancel.html changes.html combined.png combining.png contact.html	\
		design.html dollar.gif donate.html download.html euro1.gif features.html\
		handr.gif haninfo-big5.png haninfo-menu.png haninfo-utf8.png header.html\
		index-dl.html index.html logo.gif menu.png mined-html.png mined-uni.png	\
		mined.html mnemodoc.html navigate.html new-rot.gif new.gif overview.html\
		paypal_donate.gif paypal_logo.gif paypal_payments.gif picklist.png	\
		script-arabic.gif script-cyrillic.gif script-greek.gif script-han.gif	\
		script-hebrew.gif script-highlighting.png script-hiragana.gif		\
		script-thai.gif	separated.png thankyou.html unicode.html
.endif

USE_GMAKE=	YES
MAKE_ARGS=	GMAKE=${GMAKE} CC=${CC:T} OPT="${CFLAGS}"
INSTALL_TARGET=	localinstall

MAN1=		mined.1

pre-build:
	@${MV} ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.cc.bak
	@${CP} ${WRKSRC}/src/mkinclud.gcc ${WRKSRC}/src/mkinclud.cc
	@(if [ ! -f ${WRKSRC}/src/mkinclud.${CC:T} ] ; then	\
	${LN} -sf ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.${CC:T} ; \
	fi)
	@${ECHO_MSG}
	@${ECHO_MSG} "Warning: conversion of all keyboard mapping tables may take a long time!"
	@${ECHO_MSG}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
