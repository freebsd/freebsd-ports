# New ports collection makefile for:	distel
# Date Created:				11 November 2002
# Whom:				 	olgeni@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	distel
PORTVERSION=	2009.08.02
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	olgeni
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTEL_MANUALS}
DIST_SUBDIR=	erlang
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Distel extends Emacs Lisp with Erlang-style message passing

BUILD_DEPENDS+=	erlc:${PORTSDIR}/lang/erlang

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_EMACS=	yes

DISTEL_MANUALS=	distel-euc.pdf distel-euc.ps.gz \
		distel-user-3.3.pdf distel-user-3.3.ps.gz \
		distel-3.1.pdf
DISTEL_DOCS=	AUTHORS ChangeLog INSTALL INSTALL.WIN32 NEWS README README.ie-session
DISTEL_ROOT=	${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}

do-build:
	@cd ${WRKSRC} && erlc -W0 -o ebin/ +debug_info src/*.erl

do-install:
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/elisp/*el ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${DISTEL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
	@for FILE in ${DISTEL_MANUALS}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${FILE} ${DOCSDIR}; \
	done
	@${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
	@for FILE in ${DISTEL_MANUALS}; do \
		${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/$${FILE} ${DOCSDIR}; \
	done
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/doc/distel/*.html ${DOCSDIR}/html
	@${MKDIR} ${DISTEL_ROOT}
.endif
	@${MKDIR} ${DISTEL_ROOT}/src
	@${MKDIR} ${DISTEL_ROOT}/ebin
	@${INSTALL_DATA} ${WRKSRC}/src/*.erl ${DISTEL_ROOT}/src
	@${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${DISTEL_ROOT}/ebin
	@${LN} -sf ${DISTNAME} ${PREFIX}/lib/erlang/lib/${PORTNAME}

.include <bsd.port.mk>
