# New ports collection makefile for:   mhc
# Date Created:		6 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mhc
PORTVERSION=	20010321
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://www.quickhack.net/mhc/arc/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-current-snap${PORTVERSION}

MAINTAINER?=	yoichi@eken.phys.nagoya-u.ac.jp

WRKSRC=		${WRKDIR}/${DISTNAME}/emacs
EMACS_PORT_NAME?=	emacs20

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "emacs20")
ALL_TARGET=	elc
.endif
.if (${EMACS_PORT_NAME} == "xemacs21-mule")
ALL_TARGET=	package
INSTALL_TARGET=	install-package
PLIST=	${PKGDIR}/pkg-plist.xemacs21-mule
.endif

DOCS=	00copyright 00readme 00readme.jis emacs/00usage.jis

DOCSDIR=	${PREFIX}/share/doc/mhc

post-install:
.if (${EMACS_PORT_NAME} == "emacs20")
	${MKDIR} ${PREFIX}/${EMACS_LIBDIR}/site-lisp/mhc/icons
	${INSTALL_DATA} ${WRKSRC}/../icons/*.xbm ${PREFIX}/${EMACS_LIBDIR}/site-lisp/mhc/icons
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/../samples/DOT.schedule.sample.jp ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
