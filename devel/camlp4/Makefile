# New ports collection makefile for:   brs
# Date created:        12 July 2000
# Whom:                Kim Scarborough <user@unknown.nu>
#
# $FreeBSD$
#

PORTNAME=	camlp4
PORTVERSION=	3.00
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/cristal/camlp4/ \
		http://www.unknown.nu/ports/

MAINTAINER=	user@unknown.nu

BUILD_DEPENDS=	ocamlc.opt:${PORTSDIR}/lang/ocaml

HAS_CONFIGURE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/config
CONFIGURE_SCRIPT=	configure_batch
CONFIGURE_ENV=	PREFIX=${PREFIX}
ALL_TARGET=	world bootstrap opt

MAN1=		camlp4.1
MLINKS=	camlp4.1 camlp4o.1 camlp4.1 camlp4r.1 camlp4.1 mkcamlp4.1 \
		camlp4.1 ocpp.1 camlp4.1 camlp4o.1 camlp4.1 camlp4r.opt.1 \
		camlp4.1 camlp4o.opt.1

.include <bsd.port.mk>
