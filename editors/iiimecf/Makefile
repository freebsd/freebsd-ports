# New ports collection makefile for:	IIIMECF for GNU Emacs 20
# Date created:		11 Sep 2000
# Whom:			OKAZAKI Tetsurou
#
# $FreeBSD$
#

PORTNAME=	iiimecf
PORTVERSION=	0.3
CATEGORIES=	editors elisp
MASTER_SITES=	ftp://ftp.kddlabs.co.jp/Japan/m17n.org/mule/IIIM/ \
		ftp://ftp.etl.go.jp/pub/mule/IIIM/ \
		ftp://ftp.win.or.jp/pub/word/mule/IIIM/ \
		ftp://ftp.m17n.org/pub/mule/IIIM/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	IIIMECF-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Internet/Intranet Input Method Emacs Client Framework for GNU Emacs 20

BUILD_DEPENDS=	${UN_DEFINE}:${PORTSDIR}/converters/mule-ucs-emacs20
RUN_DEPENDS=	${UN_DEFINE}:${PORTSDIR}/converters/mule-ucs-emacs20

EMACS_PORT_NAME=	emacs20

UN_DEFINE=	${LOCALBASE}/${EMACS_LIBDIR_WITH_VER}/site-lisp/mule-ucs/un-define.el
PLIST_SUB=	PORTDOCDIR=${PORTDOCDIR}
PORTDOCDIR=	share/doc/iiimecf
IIIMECF_DESTDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/iiimecf
EMACS_ARGS=	-q --no-site-file -batch

do-build:
	cd ${WRKSRC}; \
	    ${EMACS_CMD} ${EMACS_ARGS} -l iiimcf-comp.el

do-install:
	@${MKDIR} ${IIIMECF_DESTDIR}
	cd ${WRKSRC}/lisp; \
		${INSTALL_DATA} *.el *.elc ${IIIMECF_DESTDIR}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/${PORTDOCDIR}
	cd ${WRKSRC} ; \
	for i in lisp/ChangeLog README* ; do \
		${INSTALL_DATA} $${i} ${PREFIX}/${PORTDOCDIR} ; \
	done
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
