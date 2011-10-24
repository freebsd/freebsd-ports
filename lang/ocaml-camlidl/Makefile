# New ports collection makefile for:	camlidl
# Date created:		2006-07-31
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $MBSDlabs$
# $FreeBSD$
#

PORTNAME=	camlidl
PORTVERSION=	1.05
PORTREVISION=	2
CATEGORIES=	lang
MASTER_SITES=	http://caml.inria.fr/distrib/bazar-ocaml/
PKGNAMEPREFIX=	ocaml-
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}.doc.html.tar.gz
EXTRACT_ONLY=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A stub code generator for using C/C++ libraries from ocaml

USE_OCAML=	yes

DOCSDIR=	${PREFIX}/share/doc/ocaml/${PORTNAME}

.include <bsd.port.pre.mk>

post-extract:
	@${REINPLACE_CMD} -e "s,^\(OCAMLLIB=\).*,\1${PREFIX}/lib/ocaml,g" \
		-e "s,^\(BINDIR=\).*,\1${PREFIX}/bin,g" \
		-e "s,^CFLAGS=.*,#\&,g" \
		-e "s,^\(CPP=\).*,\1/usr/bin/cpp,g" \
		${WRKSRC}/config/Makefile.unix

	@${REINPLACE_CMD} -e \
		"/^install/,/^$$/s,\([ \t]*\)cp,\1${INSTALL_SCRIPT},g" \
		${WRKSRC}/compiler/Makefile

	@${REINPLACE_CMD} -e \
		"/^install/,/^$$/s,\([ \t]*\)cp,\1${INSTALL_DATA},g" \
		${WRKSRC}/lib/Makefile ${WRKSRC}/runtime/Makefile.unix

	@${LN} -sf ${WRKSRC}/config/Makefile.unix ${WRKSRC}/config/Makefile

pre-install:
.if !exists(${PREFIX}/lib/ocaml/caml)
	${MKDIR} ${PREFIX}/lib/ocaml/caml
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${GZCAT} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}.doc.html.tar.gz \
		| ${TAR} -C ${DOCSDIR} -xf -
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
	${FIND} ${DOCSDIR}/ -type f -exec ${CHMOD} ${SHAREMODE} {} \;
.endif

test:
	@${ECHO_CMD} "Testing IDL library"
	@${REINPLACE_CMD} -e "s,^\(CCPP=\).*,\1${CXX},g" \
		${WRKSRC}/tests/Makefile
	cd ${WRKSRC}/tests && ${SETENV} ${MAKE_ENV} ${MAKE} all

.include <bsd.port.post.mk>
