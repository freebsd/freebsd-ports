# Created by: Stanislav Sedov <ssedov@mbsd.msk.ru>
# $FreeBSD$

PORTNAME=	docs
PORTVERSION=	1.4.3
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The gEDA's documentation

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
DOCSDIR=	${PREFIX}/share/doc/geda

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
NO_ARCH=	yes

.include <bsd.port.mk>
