# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$
#

PORTNAME=	xstr
PORTVERSION=	0.2.1
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thread-safe implementation of string searching/matching

LICENSE=	MIT


WRKSRC=		${WRKDIR}/${PORTNAME}

USE_OCAML=	yes
USE_OCAML_FINDLIB=yes
USE_OCAMLFIND_PLIST=yes

USE_GMAKE=	yes
ALL_TARGET=	all opt

.include <bsd.port.mk>
