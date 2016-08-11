# Created by: Michael Grünewald <michipili@gmail.com>
# $FreeBSD$

PORTNAME=	camlp4
PORTVERSION=	4.02.1+1
PORTREVISION=	1
CATEGORIES=	devel
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	michipili@gmail.com
COMMENT=	Camlp4 is a system for writing extensible parsers for OCaml

LICENSE=	LGPL20

USE_GITHUB=	yes
GH_ACCOUNT=	ocaml

USES=		gmake
USE_OCAML=	yes
HAS_CONFIGURE=	yes
MAKE_ENV+=	DESTDIR="${STAGEDIR}"
MAKE_JOBS_UNSAFE=yes
ALL_TARGET=	all camlp4/META
INSTALL_TARGET=	install install-META

post-stage:
.for f in camlp4o camlp4of camlp4oof camlp4orf camlp4r camlp4rf
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}.opt
.endfor

.include <bsd.port.mk>
