# New ports collection makefile for:	skk-elisp
# Date created:		31 Oct 1998
# Whom:			Shigeyuki FUKUSHIMA <shige@kuis.kyoto-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	ddskk
PORTVERSION=	11.6.0
CATEGORIES=	japanese elisp
MASTER_SITES=	http://openlab.ring.gr.jp/skk/maintrunk/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	yoichi@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/emu/emu.el:${PORTSDIR}/editors/apel${DEPPORT_SUFFIX}

EMACS_PORT_NAME?=	emacs21
.if (${EMACS_PORT_NAME} == emacs21)
DEPPORT_SUFFIX=
.else
DEPPORT_SUFFIX=	-${EMACS_PORT_NAME}
PLIST=	${PKGDIR}/pkg-plist.${EMACS_PORT_NAME}
.endif
AMBIGUOUS_ELCS=	skk-jisx0213 skk-lookup

USE_BZIP2=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	elc info

SKK_LISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/skk
SKK_DOCS=	AUTHORS Codename Contributors FAQ.txt NEWS README
SKK_EXAMPLES=	etc/Emacs.ad etc/dot.emacs etc/dot.skk

post-install:
.for i in ${AMBIGUOUS_ELCS}
	${RM} -f ${PREFIX}/${SKK_LISPDIR}/${i}.elc
	${INSTALL_DATA} ${WRKSRC}/${i}.el ${PREFIX}/${SKK_LISPDIR}
.endfor
	${MKDIR} ${EXAMPLESDIR}
.for i in ${SKK_EXAMPLES}
	${INSTALL_DATA}	${WRKSRC}/${i} ${EXAMPLESDIR}
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${SKK_DOCS}
	${INSTALL_DATA} ${WRKSRC}/READMEs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
