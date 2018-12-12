# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	plproxy
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	2_8
PORTREVISION=	1
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PL/Proxy - Function-based sharding for PostgreSQL

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		bison gmake pgsql
LLD_UNSAFE=	yes
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^#ifdef/ s| SYS_| HAVE_SYS_|' ${WRKSRC}/src/execute.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plproxy.so

.include <bsd.port.mk>
