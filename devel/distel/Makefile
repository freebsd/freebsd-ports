# New ports collection makefile for:	distel
# Date Created:				11 November 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	distel
PORTVERSION=	3.3
PORTREVISION=	3
CATEGORIES=	devel elisp
MASTER_SITES=	http://www.bluetail.com/%7Eluke/distel/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	distel
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTEL_MANUALS}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Distel extends Emacs Lisp with Erlang-style message passing

BUILD_DEPENDS+=	erlc:${PORTSDIR}/lang/erlang
RUN_DEPENDS+=	${LOCALBASE}/lib/erlang/lib/syntax_tools/ebin/erl_syntax.beam:${PORTSDIR}/devel/syntax_tools

PLIST_SUB=	VERSION="${PORTVERSION}"

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	base
EMACS_PORT_NAME?=	emacs21

DISTEL_MANUALS=	distel-euc.pdf distel-euc.ps.gz \
		distel-user-3.3.pdf distel-user-3.3.ps.gz \
		distel-3.1.pdf
DISTEL_DOCS=	config/emacs-init-snippet.el AUTHORS ChangeLog NEWS README README.ie-session
DISTEL_ROOT=	${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/c/dec32 ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/elisp/*el ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/elisp/*elc ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/elisp/*elc ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${DISTEL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
	@for FILE in ${DISTEL_MANUALS}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${FILE} ${DOCSDIR}; \
	done
	@${MKDIR} ${DISTEL_ROOT}
	@${MKDIR} ${DISTEL_ROOT}/src
	@${MKDIR} ${DISTEL_ROOT}/ebin
	@${INSTALL_DATA} ${WRKSRC}/erl/*.erl ${DISTEL_ROOT}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${DISTEL_ROOT}/ebin
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
