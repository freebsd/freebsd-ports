PORTNAME=	dbm
PORTVERSION=	1.3
DISTVERSIONPREFIX=	camldbm-
CATEGORIES=	databases
PKGNAMEPREFIX=	ocaml-

EXTRA_PATCHES=	${PATCHDIR}/3bb91d6-revised-configuration:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OCaml binding to the NDBM and GDBM database library
WWW=		https://github.com/ocaml/dbm

LICENSE=	LGPL20 # with a special exception to clause 6

USE_GITHUB=	yes
USE_OCAML=	yes
GH_ACCOUNT=	ocaml
USE_OCAML_LDCONFIG=	yes

DOCSDIR=	${OCAML_DOCSDIR}/${PORTNAME}
HAS_CONFIGURE=	yes
MAKE_ENV+=	LIBDIR="${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dbm" \
		STUBLIBDIR="${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dbm"

post-patch:
	@${REINPLACE_CMD} \
		-E 's/^(LIBDIR|STUBLIBDIR)=/\1?=/' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} \
		-e 's/^version =.*/version = "${PORTVERSION}"/' ${WRKSRC}/META

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dbm

post-install:
	@${STRIP_CMD} \
		${STAGEDIR}${PREFIX}/${OCAML_SITELIBDIR}/dbm/dllcamldbm.so
	@${INSTALL_DATA} ${WRKSRC}/META \
		${STAGEDIR}${PREFIX}/lib/ocaml/site-lib/dbm

.include <bsd.port.mk>
