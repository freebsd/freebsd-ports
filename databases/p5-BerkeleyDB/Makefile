# ports collection makefile for:	perl interface to Berkeley DB v3
# Date created:				3 January 2001
# Whom:					T. William Wells <bill@twwells.com>
#
# $FreeBSD$
#

PORTNAME=	BerkeleyDB
PORTVERSION=	0.19
CATEGORIES=	databases perl5
MASTER_SITES=	$(MASTER_SITE_PERL_CPAN)
MASTER_SITE_SUBDIR=	BerkeleyDB
PKGNAMEPREFIX=	p5-

MAINTAINER=	bill@twwells.com

LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3

PERL_CONFIGURE=	yes
ALL_TARGET=	all test

MAN3=		BerkeleyDB.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-patch:
	@${ECHO} "INCLUDE = ${LOCALBASE}/include/db3" > ${WRKSRC}/config.in
	@${ECHO} "LIB = ${LOCALBASE}/lib" >> ${WRKSRC}/config.in
	@${ECHO} "DBNAME = -ldb3" >> ${WRKSRC}/config.in
	${PERL} -pi -e '$$_="" if /MAN3PODS/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
