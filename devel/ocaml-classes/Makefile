PORTNAME=	classes
PORTVERSION=	4.00
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/dist/
PKGNAMEPREFIX=	ocaml-
DISTNAME=	ocaml-${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ocaml Object interface for ocaml's standard library modules
WWW=		http://wwwfun.kurims.kyoto-u.ac.jp/soft/olabl/classes/

LICENSE=	LGPL21

USE_OCAML=	yes
USE_OCAML_FINDLIB=	yes
USE_OCAMLFIND_PLIST=	yes
MAKE_ENV=	INSTALL="${INSTALL_DATA}"

.include <bsd.port.mk>
