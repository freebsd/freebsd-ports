# New ports collection makefile for:	irchat-pj (for emacs20)
# Date Created:		2 May 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	irchat-pj
PORTVERSION=	2.5.5
CATEGORIES=	irc elisp
MASTER_SITES=	ftp://ftp.fan.gr.jp/pub/elisp/irchat-pj/2.5/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	irchat-pj-${PORTVERSION}p

MAINTAINER=	yoichi@eken.phys.nagoya-u.ac.jp

BUILD_DEPENDS=	${LOCALBASE}/${LISPDIR:S,/${PORTNAME}$,/pure,}/pure-make.el:${PORTSDIR}/irc/pure-${EMACS_PORT_NAME}
RUN_DEPENDS=	${LOCALBASE}/${LISPDIR:S,/${PORTNAME}$,/pure,}/pure-make.el:${PORTSDIR}/irc/pure-${EMACS_PORT_NAME} \
		${LOCALBASE}/bin/dcc:${PORTSDIR}/irc/dcc

EMACS_PORT_NAME?=	emacs20
LISPDIR?=	${EMACS_LIBDIR}/site-lisp/${PORTNAME}
ETCDIR=		share/doc/${PORTNAME}

LDFLAGS=	${PTHREAD_LIBS}
CFLAGS+=	${PTHREAD_CFLAGS} -DUSE_PTHREAD -DENABLE_PTHREAD_ATTR
MAKE_ENV+=	LDFLAGS="${LDFLAGS}"

DOCS=		README.25 doc24/CHANGELOG doc24/FAQ-about-jp24.txt\
		doc24/FAQ-irchat-PJ.txt doc24/INSTALL.irchat-pj\
		doc24/README.browse-url-plus doc24/README.irchat-pj\
		doc24/browse-url-plus-init.el doc24/dot.irchat_vars.el

PLIST_SUB=	LISPDIR=${LISPDIR} \
		ETCDIR=${ETCDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/${ETCDIR}
.for f in ${DOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${PREFIX}/${ETCDIR}
.endfor
.endif
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
	${RMDIR} ${PREFIX}/${EMACS_LIBDIR}/site-packages/etc/irchat-pj
.endif

.include <bsd.port.mk>
