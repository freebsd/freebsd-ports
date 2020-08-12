# Created by: Yoichi NAKAYAMA <yoichi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xface.el
PORTVERSION=	1.3.6.24
PORTREVISION=	19
CATEGORIES=	graphics elisp
MASTER_SITES=	http://www.jpl.org/ftp/pub/elisp/ \
		ftp://ftp.jpl.org/pub/elisp/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}
DISTNAME=	x-face-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X-Face encoder/decoder/viewer for Emacsen

LICENSE=	GPLv2+

.if ${FLAVOR:U} != devel && ${FLAVOR:U} != devel_nox
# http://pkg.awarnach.mathstat.dal.ca/data/11i386-default/2018-05-30_07h36m11s/logs/errors/xface.el-emacs26-1.3.6.24_18.log
BROKEN=		fails to build
.endif

RUN_DEPENDS=	compface:mail/faces

USES=		emacs
EMACS_FLAVORS_EXCLUDE=	devel_full devel_nox # fail to build

LISP_FILES=	x-face
LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/x-face
PLIST_SUB+=	LISPDIR=${LISPDIR} \
		DOCSDIR=share/doc/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${LISPDIR}
.for i in ${LISP_FILES}
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${WRKSRC}/${i}.elc \
		${STAGEDIR}${PREFIX}/${LISPDIR}
.endfor

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} METHOD.ja README.ja README-Anim.ja \
		TODO.ja ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
