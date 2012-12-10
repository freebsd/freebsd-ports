# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	aifad
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/mmottl/aifad/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system

BUILD_DEPENDS=	${SA_DIR}/pcre/pcre.a:${PORTSDIR}/devel/ocaml-pcre \
		${SA_DIR}/res/res.a:${PORTSDIR}/devel/ocaml-res \
		${SA_DIR}/cfg/cfg.a:${PORTSDIR}/devel/ocaml-cfg \
		omake:${PORTSDIR}/devel/omake	\
		menhir:${PORTSDIR}/devel/menhir

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes

SA_DIR=		${LOCALBASE}/${OCAML_SITELIBDIR}

DOCS=	README.txt TODO

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}/
.endif

.include <bsd.port.post.mk>
