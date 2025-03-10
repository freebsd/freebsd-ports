PORTNAME=	xstr
PORTVERSION=	0.2.1
PORTREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	http://download.camlcity.org/download/
PKGNAMEPREFIX=	ocaml-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Thread-safe implementation of string searching/matching
WWW=		http://projects.camlcity.org/projects/xstr.html

LICENSE=	MIT

USES=		gmake ocaml:findplist

WRKSRC=		${WRKDIR}/${PORTNAME}

ALL_TARGET=	all opt

.include <bsd.port.options.mk>

.if ${ARCH} == powerpc
USE_BINUTILS=	yes
.endif

.include <bsd.port.mk>
