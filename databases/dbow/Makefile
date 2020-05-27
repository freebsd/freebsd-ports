# Created by: Dermot Tynan <dtynan@kalopa.com>
# $FreeBSD$

PORTNAME=	dbow
PORTVERSION=	0.7
PORTREVISION=	1
CATEGORIES=	databases devel
MASTER_SITES=	SF

MAINTAINER=	dtynan@kalopa.com
COMMENT=	Database object generator for C, Perl, PHP, etc.

USES=		mysql
MAKE_ENV+=	MYSQL_INC=${LOCALBASE}/include/mysql \
		MYSQL_LIB=${LOCALBASE}/lib/mysql

post-patch:
	@${REINPLACE_CMD} -e "s|CFLAGS=|CFLAGS+=|g" \
			-e "s|^MYSQL_INC=|MYSQL_INC?=|" \
			-e "s|^MYSQL_LIB=|MYSQL_LIB?=|" \
		${WRKSRC}/example/Makefile ${WRKSRC}/lib/Makefile \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
