# $FreeBSD$

PORTNAME=	distel
PORTVERSION=	2012.05.28
CATEGORIES=	devel elisp

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Distel extends Emacs Lisp with Erlang-style message passing

BUILD_DEPENDS+=	erlc:${PORTSDIR}/lang/erlang

USE_GITHUB=     yes
GH_ACCOUNT=     massemanet
GH_COMMIT=      ecc8581
GH_TAGNAME=	${GH_COMMIT}

PLIST_SUB=	VERSION="${PORTVERSION}"

USE_EMACS=	yes

DISTEL_DOCS=	AUTHORS ChangeLog INSTALL INSTALL.WIN32 NEWS README README.ie-session
DISTEL_ROOT=	${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}

do-build:
	@${MKDIR} ${WRKSRC}/ebin
	@cd ${WRKSRC} && erlc -W0 -o ebin/ +debug_info src/*.erl

do-install:
	@${MKDIR} ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/elisp/*el ${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@for FILE in ${DISTEL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${DOCSDIR}; \
	done
	@${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${DOCSDIR}
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
