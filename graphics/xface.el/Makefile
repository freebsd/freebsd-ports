# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xface.el
PORTVERSION=	1.3.6.24
PORTREVISION=	13
CATEGORIES=	graphics elisp
MASTER_SITES=	http://www.jpl.org/ftp/pub/elisp/ \
		ftp://ftp.jpl.org/pub/elisp/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	x-face-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz \
		x-face-e21.el.gz
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X-Face encoder/decoder/viewer for Emacsen

EMACS_PORT_NAME?=	emacs24

RUN_DEPENDS=	compface:mail/faces

USE_EMACS=	yes

LISP_FILES=	x-face
.if (${EMACS_PORT_NAME} == xemacs21 || ${EMACS_PORT_NAME} == xemacs21-mule)
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

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LISPDIR}
.for i in ${LISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${WRKSRC}/${i}.elc \
		${STAGEDIR}${PREFIX}/${LISPDIR}
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} METHOD.ja README.ja README-Anim.ja \
		TODO.ja ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
