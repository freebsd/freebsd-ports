# New ports collection makefile for:   semantic
# Date created:                30 December 2001
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	semantic
PORTVERSION=	1.4.4
PORTREVISION=	2
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	cedet
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
#DISTNAME=       ${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A lexer, parser-generator, and parser for Emacs

EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/eieio/eieio.el:${PORTSDIR}/devel/eieio${PORTNAMESUFFIX} \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/speedbar/speedbar.el:${PORTSDIR}/editors/speedbar${PORTNAMESUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
MAKE_ARGS=	LOADPATH=

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/semantic

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc *.bnf
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/semantic.info* ${PREFIX}/info
	install-info ${PREFIX}/info/semantic.info ${PREFIX}/info/dir

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in INSTALL NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
