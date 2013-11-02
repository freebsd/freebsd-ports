# Created by: Kurt Jaeger <fbsd-ports@opsec.eu>
# $FreeBSD$

PORTNAME=	DBD-cego
PORTVERSION=	1.2.8
CATEGORIES=	databases perl5
MASTER_SITES=	http://www.lemke-it.com/
PKGNAMEPREFIX=	p5-

MAINTAINER=	fbsd-ports@opsec.eu
COMMENT=	Cego DBI driver for Perl 5

LICENSE=	GPLv3

BUILD_DEPENDS=	p5-DBI>=1.628:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	p5-DBI>=1.628:${PORTSDIR}/databases/p5-DBI
LIB_DEPENDS=	libcego.so:${PORTSDIR}/databases/cego

.if defined(.PARSEDIR)
USES=		gmake
.endif

USES+=		perl5
USE_PERL5=	configure
CC:=		${CXX}

post-configure:
	@${REINPLACE_CMD} -e 's|fno-strict-aliasing|& -fpermissive|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
