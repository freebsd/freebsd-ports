# New ports collection makefile for:	dbow
# Date created:				24 March 2004
# Whom:					Dermot Tynan <dtynan@kalopa.com>
#
# $FreeBSD$
#

PORTNAME=	dbow
PORTVERSION=	0.7
CATEGORIES=	databases devel
MASTER_SITES=	SF

MAINTAINER=	dtynan@kalopa.com
COMMENT=	DBOW is a database object generator for C, Perl, PHP, etc

MAKE_ENV+=	MYSQL_INC=${LOCALBASE}/include/mysql \
		MYSQL_LIB=${LOCALBASE}/lib/mysql

USE_MYSQL=	yes

MAN1=		dbow.1

post-patch:
	@${REINPLACE_CMD} -e "s|CFLAGS=|CFLAGS+=|g" \
			-e "s|^MYSQL_INC=|MYSQL_INC?=|" \
			-e "s|^MYSQL_LIB=|MYSQL_LIB?=|" \
		${WRKSRC}/example/Makefile ${WRKSRC}/lib/Makefile \
		${WRKSRC}/src/Makefile

.include <bsd.port.mk>
