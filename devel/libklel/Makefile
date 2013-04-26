# $FreeBSD$

PORTNAME=	libklel
PORTVERSION=	1.1.0
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	klm@uidzero.org
COMMENT=	KoreLogic Expression Language library

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre

GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=--with-pcre=${LOCALBASE}

MAN1=		klel-expr.1
MAN3=		klelapi.3 klellang.3 klelstdlib.3 kleltut.3

.include <bsd.port.mk>
