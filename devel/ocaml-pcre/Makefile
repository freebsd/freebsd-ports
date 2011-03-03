# New ports collection makefile for:   ocaml-pcre
# Date created:        21 April 2002
# Whom:                Henrik Motakef <henrik.motakef@web.de>
#
# $FreeBSD$
#

PORTNAME=	pcre
PORTVERSION=	6.2.2
CATEGORIES=	devel
MASTER_SITES=	http://hg.ocaml.info/release/pcre-ocaml/archive/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	release-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Perl compatible regular expressions for Objective Caml

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre
WRKSRC=		${WRKDIR}/pcre-ocaml-${DISTNAME}

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAML_LDCONFIG=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	LIBDIRS="${LOCALBASE}/lib"

USE_GMAKE=	yes
EXAMPLESDIR=	${OCAML_EXAMPLESDIR}/${PORTNAME}

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}/)
.endif

.include <bsd.port.mk>
