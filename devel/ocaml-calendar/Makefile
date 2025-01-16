PORTNAME=	calendar
PORTVERSION=	2.04
CATEGORIES=	devel
MASTER_SITES=	https://download.ocamlcore.org/calendar/calendar/${PORTVERSION}/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Date and time library for OCaml
WWW=		http://calendar.forge.ocamlcore.org/

LICENSE=	LGPL21

USES=		gmake ocaml:findplist

GNU_CONFIGURE=	yes

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

.include <bsd.port.mk>
