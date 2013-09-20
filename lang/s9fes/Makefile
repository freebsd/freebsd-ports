# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	s9fes
PORTVERSION=	20121005
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.t3x.org/s9fes/

MAINTAINER=	nmh@t3x.org
COMMENT=	Portable Scheme interpreter with a Unix interface

LICENSE=	public
LICENSE_NAME=	Public Domain
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIBDIR=		${DATADIR}
MAKE_ARGS=	${MAKE_ENV}
WRKSRC=		${WRKDIR}/s9

MAN1=		s9.1
MANCOMPRESSED=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
