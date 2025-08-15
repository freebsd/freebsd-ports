PORTNAME=	distel
PORTVERSION=	4.1.1
PORTREVISION=	20
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	erlang@FreeBSD.org
COMMENT=	Distel extends Emacs Lisp with Erlang-style message passing
WWW=		http://www.bluetail.com/~luke/distel/

LICENSE=	MIT

BUILD_DEPENDS+=	erlc:lang/erlang

USES=		emacs
USE_GITHUB=	yes
GH_ACCOUNT=	massemanet

PLIST_SUB=	VERSION="${PORTVERSION}"

NO_ARCH=	yes

DISTEL_DOCS=	AUTHORS ChangeLog INSTALL INSTALL.WIN32 NEWS README README.ie-session
DISTEL_ROOT=	${PREFIX}/lib/erlang/lib/${PORTNAME}-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

do-build:
	@${MKDIR} ${WRKSRC}/ebin
	@cd ${WRKSRC} && erlc -W0 -o ebin/ +debug_info src/*.erl

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/elisp/*el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/${PORTNAME}

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	for FILE in ${DISTEL_DOCS}; do \
		${INSTALL_DATA} ${WRKSRC}/$${FILE} ${STAGEDIR}${DOCSDIR}; \
	done
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/doc/distel/*.html ${STAGEDIR}${DOCSDIR}/html

	@${MKDIR} ${STAGEDIR}${DISTEL_ROOT}/src
	@${MKDIR} ${STAGEDIR}${DISTEL_ROOT}/ebin
	${INSTALL_DATA} ${WRKSRC}/src/*.erl ${STAGEDIR}${DISTEL_ROOT}/src
	${INSTALL_DATA} ${WRKSRC}/ebin/*.beam ${STAGEDIR}${DISTEL_ROOT}/ebin

.include <bsd.port.mk>
