# New ports collection makefile for:	x-face.el
# Date created:                17 Feb 2002
# Whom:                        Yoichi NAKAYAMA <yoichi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xface.el
PORTVERSION=	1.3.6.24
PORTREVISION=	1
CATEGORIES=	graphics elisp
MASTER_SITES=	ftp://ftp.jpl.org/pub/elisp/ \
		ftp://ftp.opaopa.org/pub/mirror/elisp/jpl/elisp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	x-face-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		x-face-e21.el.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	yoichi@FreeBSD.org
COMMENT=	X-Face encoder/decoder/viewer for Emacsen

RUN_DEPENDS=	compface:${PORTSDIR}/mail/faces

EMACS_PORT_NAME?=	emacs21

LISP_FILES=	x-face
.if (${EMACS_PORT_NAME} == emacs21)
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/x-face
LISP_FILES+=	x-face-e21
PLIST_SUB+=	E21_ONLY="" \
		XEMACS_ONLY="@comment "
.elif (${EMACS_PORT_NAME} == xemacs21 || ${EMACS_PORT_NAME} == xemacs21-mule)
LISPDIR=	${EMACS_SITE_LISPDIR}/x-face
LISP_FILES+=	x-face-xmas
PLIST_SUB+=	E21_ONLY="@comment " \
		XEMACS_ONLY=""
.else
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/x-face
PLIST_SUB+=	E21_ONLY="@comment " \
		XEMACS_ONLY="@comment "
.endif
PLIST_SUB+=	LISPDIR=${LISPDIR} \
		DOCSDIR=share/doc/${PORTNAME}

post-extract:
.if (${EMACS_PORT_NAME} == emacs21)
	${CP} ${DISTDIR}/x-face-e21.el.gz ${WRKSRC}
	${GUNZIP_CMD} ${WRKSRC}/x-face-e21.el.gz
.endif
post-build:
.if (${EMACS_PORT_NAME} == emacs21)
	(cd ${WRKSRC}; \
	${EMACS_CMD} -batch -q -no-site-file \
	-f batch-byte-compile x-face-e21.el)
.endif
do-install:
	${MKDIR} ${PREFIX}/${LISPDIR}
.for i in ${LISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${WRKSRC}/${i}.elc ${PREFIX}/${LISPDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in METHOD.ja README.ja README-Anim.ja TODO.ja
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
