# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	plproxy
DISTVERSIONPREFIX=	${PORTNAME}_
DISTVERSION=	2_7
CATEGORIES=	databases
PKGNAMEPREFIX=	postgresql-

MAINTAINER=	tz@FreeBSD.org
COMMENT=	PL/Proxy - database partitioning system

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		bison gmake pgsql

USE_GITHUB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		'/^#ifdef/s| SYS_| HAVE_SYS_|' ${WRKSRC}/src/execute.c

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/postgresql/plproxy.so

.include <bsd.port.post.mk>
