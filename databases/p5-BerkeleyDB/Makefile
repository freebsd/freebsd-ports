# ports collection makefile for:	perl interface to Berkeley DB v3
# Date created:				3 January 2001
# Whom:					T. William Wells <bill@twwells.com>
#
# $FreeBSD$
#

PORTNAME=	BerkeleyDB
PORTVERSION=	0.25
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	BerkeleyDB
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Perl5 interface to the Berkeley DB package revision 2, 3, 4 or 4.1

# Default to db3
WITH_BDB_VER?=	3

.if ${WITH_BDB_VER} == 2
LIB_DEPENDS=	db2.0:${PORTSDIR}/databases/db2
BDB_LIB_VER=	db2
.elif ${WITH_BDB_VER} == 3
LIB_DEPENDS=	db3.3:${PORTSDIR}/databases/db3
BDB_LIB_VER=	db3
.elif ${WITH_BDB_VER} == 4
LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4
BDB_LIB_VER=	db4
.elif ${WITH_BDB_VER} == 41
LIB_DEPENDS=	db41.1:${PORTSDIR}/databases/db41
BDB_LIB_VER=	db41
.elif ${WITH_BDB_VER} == 42
LIB_DEPENDS=	db-4.2.2:${PORTSDIR}/databases/db42
BDB_LIB_VER=	db-4.2
.else
.error WITH_BDB_VER must be one between 2, 3, 4, 41 and 42
.endif

PERL_CONFIGURE=	yes

MAN3=		BerkeleyDB.3

pre-everything::
	@${ECHO} "This port defaults to use Berkeley DB 3, but you can change it"
	@${ECHO} "by setting WITH_BDB_VER to either 2, 3, 4, 41 or 42"

post-patch:
	@${ECHO} "INCLUDE = ${LOCALBASE}/include/db${WITH_BDB_VER}" > ${WRKSRC}/config.in
	@${ECHO} "LIB = ${LOCALBASE}/lib" >> ${WRKSRC}/config.in
	@${ECHO} "DBNAME = -l${BDB_LIB_VER}" >> ${WRKSRC}/config.in
	${PERL} -pi -e '$$_="" if /MAN3PODS/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
