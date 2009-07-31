# New ports collection makefile for:   mhc (for emacs21)
# Date Created:		6 Mar 2001
# Whom:			Yoichi NAKAYAMA <yoichi@eken.phys.nagoya-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	mhc
PORTVERSION=	20051120
PORTREVISION=	2
CATEGORIES=	deskutils elisp
MASTER_SITES=	http://www.quickhack.net/mhc/arc/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}-current-snap${PORTVERSION}

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	Message Harmonized Calendaring system

WRKSRC=		${WRKDIR}/${DISTNAME}/emacs
USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

.include <bsd.port.pre.mk>

.if (${EMACS_PORT_NAME} == "xemacs21-mule")
ALL_TARGET=	package
INSTALL_TARGET=	install-package
LISPDIR=	${EMACS_LIBDIR}/site-packages/lisp/${PORTNAME}
ICONDIR=	${EMACS_LIBDIR}/site-packages/etc/${PORTNAME}
IMG_SUFFIX=	xpm
XEMACS_ONLY=	""
EMACS_ONLY=	"@comment "
EMACS21_ONLY=	"@comment "
.else
ALL_TARGET=	elc
MAKE_ARGS+=	INST_OPTS="--with-lispdir=${PREFIX}/${LISPDIR}"
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
ICONDIR=	${EMACS_LIBDIR}/etc/${PORTNAME}/icons
XEMACS_ONLY=	"@comment "
EMACS_ONLY=	""
.if (${EMACS_PORT_NAME} == "emacs21")
IMG_SUFFIX=	xpm
EMACS21_ONLY=	""
.else
IMG_SUFFIX=	xbm
EMACS21_ONLY=	"@comment "
.endif
.endif

PLIST_SUB+=	LISPDIR=${LISPDIR} \
		ICONDIR=${ICONDIR} IMG_SUFFIX=${IMG_SUFFIX} \
		XEMACS_ONLY=${XEMACS_ONLY} \
		EMACS_ONLY=${EMACS_ONLY} \
		EMACS21_ONLY=${EMACS21_ONLY}

DOCS=	00copyright 00readme 00readme.jis emacs/00usage.jis

DOCSDIR=	${PREFIX}/share/doc/mhc

post-install:
.if (${EMACS_PORT_NAME} == "emacs20") || (${EMACS_PORT_NAME} == "emacs21")
	${MKDIR} ${PREFIX}/${ICONDIR}
	${INSTALL_DATA} ${WRKSRC}/../icons/*.${IMG_SUFFIX} ${PREFIX}/${ICONDIR}
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/../${i} ${DOCSDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/../samples/DOT.schedule.sample.jp ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
