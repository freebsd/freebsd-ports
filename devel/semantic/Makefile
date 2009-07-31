# New ports collection makefile for:   semantic
# Date created:                30 December 2001
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	semantic
PORTVERSION=	1.4.4
PORTREVISION=	5
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://dryice.name/computer/FreeBSD/distfiles/
MASTER_SITE_SUBDIR=	cedet
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}
#DISTNAME=       ${PORTNAME}-${PORTVERSION:S/.b/beta/}

MAINTAINER=	dryice@dryice.name
COMMENT=	A lexer, parser-generator, and parser for Emacs

USE_EMACS=	yes
EMACS_PORT_NAME?=	emacs21

.if ${EMACS_PORT_NAME} != "emacs21"
PORTNAMESUFFIX=	${PKGNAMESUFFIX}
.endif

BUILD_DEPENDS=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/eieio/eieio.el:${PORTSDIR}/devel/eieio${PORTNAMESUFFIX} \
		${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}/speedbar/speedbar.el:${PORTSDIR}/editors/speedbar${PORTNAMESUFFIX}
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
MAKE_ARGS=	LOADPATH=
CONFLICTS=	cedet*
INFO=		semantic

LISPDIR=	${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/semantic

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "New version of semantic is now in devel/cedet."
	@${ECHO_MSG} "Hit C-c now if you want the new version."
	@${ECHO_MSG} ""

do-install:
	${MKDIR} ${LISPDIR}
.for i in *.el *.elc *.bnf
	${INSTALL_DATA} ${WRKSRC}/${i} ${LISPDIR}
.endfor
	${INSTALL_DATA} ${WRKSRC}/semantic.info* ${PREFIX}/info

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in INSTALL NEWS
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
