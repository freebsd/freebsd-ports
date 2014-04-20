# Created by: Jaap Boender <jaapb@kerguelen.org>
# $FreeBSD$

PORTNAME=	pgocaml
PORTVERSION=	1.5
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://forge.ocamlcore.org/frs/download.php/850/
PKGNAMEPREFIX=	ocaml-
EXTRACT_SUFX=	.tgz

MAINTAINER=	tcrimi@gmail.com
COMMENT=	An OCaml interface to PostgreSQL

BROKEN=		Fails to build

BUILD_DEPENDS=	${LOCALBASE}/${OCAML_SITELIBDIR}/extlib:${PORTSDIR}/devel/ocaml-extlib \
		${LOCALBASE}/${OCAML_SITELIBDIR}/pcre:${PORTSDIR}/devel/ocaml-pcre \
		${LOCALBASE}/${OCAML_SITELIBDIR}/calendar:${PORTSDIR}/devel/ocaml-calendar \
		${LOCALBASE}/${OCAML_SITELIBDIR}/csv:${PORTSDIR}/textproc/ocaml-csv

USE_GMAKE=	yes
USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes

INSTALL_TARGET=	findlib_install

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/camlp4o.byte)
post-patch:
	${REINPLACE_CMD} 's/-pp "camlp4o/-pp "camlp4o.byte/g' ${WRKSRC}/Makefile
.endif

pre-build:
	cd ${WRKSRC}; ${GMAKE} depend

.include <bsd.port.post.mk>
