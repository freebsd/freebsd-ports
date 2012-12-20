# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	aifad
PORTVERSION=	2.0.2
CATEGORIES=	devel
MASTER_SITES=	http://cdn.bitbucket.org/mmottl/aifad/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Machine learning system

LICENSE=	GPLv3

BUILD_DEPENDS=	menhir:${PORTSDIR}/devel/menhir \
		ocaml-cfg>0:${PORTSDIR}/devel/ocaml-cfg \
		ocaml-pcre>0:${PORTSDIR}/devel/ocaml-pcre \
		ocaml-res>0:${PORTSDIR}/devel/ocaml-res
LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

USE_OCAML=	yes
NO_OCAML_RUNDEPENDS=yes

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix ${PREFIX}

PORTDOCS=	*
PORTEXAMPLES=	*
PLIST_FILES=	bin/${PORTNAME}

post-install:
	@${STRIP_CMD} ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in AUTHORS.txt CHANGES.txt README.md TODO.md
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/examples && ${INSTALL_DATA} * ${EXAMPLESDIR})
.endif

.include <bsd.port.mk>
