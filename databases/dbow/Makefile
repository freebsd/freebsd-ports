# New ports collection makefile for:	dbow
# Date created:				24 March 2004
# Whom:					Dermot Tynan <dtynan@kalopa.com>
#
# $FreeBSD$
#

PORTNAME=	dbow
PORTVERSION=	0.4
CATEGORIES=	databases devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	dbow

MAINTAINER=	dtynan@kalopa.com
COMMENT=	DBOW is a database object generator for C, Perl, PHP, etc

USE_MYSQL=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|example||' ${WRKSRC}/Makefile

.include <bsd.port.mk>
