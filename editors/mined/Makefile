# New ports collection makefile for:	mined
# Date created:		24 December 2004
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	mined
PORTVERSION=	2000.9
CATEGORIES=	editors
MASTER_SITES=	http://towo.net/mined/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text mode editor with Unicode support

MAKEFILE=	makefile

.if defined(NOPORTDOCS)
ALL_TARGET=	mined manual
.else
PORTDOCS=	cancel.html changes.html contact.html dollar.gif donate.html	\
		download.html euro1.gif features.html handr.gif header.html	\
		index-dl.html index.html logo.gif mined-small.gif mined.gif	\
		mined.html mined.lsm mined.uni.gif mnemodoc.html navigate.html	\
		new-rot.gif new.gif overview.html paypal_donate.gif		\
		paypal_logo.gif paypal_payments.gif script-arabic.gif		\
		script-cyrillic.gif script-greek.gif script-han.gif		\
		script-hebrew.gif script-hiragana.gif script-thai.gif		\
		thankyou.html unicode.html
EXAMPLES=	configure-xterm mterm uterm
.endif

USE_GMAKE=	YES
MAKE_ARGS=	GMAKE=${GMAKE} CC=${CC:T}

MAN1=		mined.1

pre-build:
	@(if [ ! -f ${WRKSRC}/src/mkinclud.${CC:T} ] ; then	\
	${LN} -sf ${WRKSRC}/src/mkinclud.cc ${WRKSRC}/src/mkinclud.${CC:T} ; \
	fi)

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/mined
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXAMPLES:S|^|${WRKSRC}/doc/|} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
