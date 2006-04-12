# New ports collection makefile for:	p5-DBD-SQLite
# Date created:				2002/03/30
# Whom:					nork@cityfujisawa.ne.jp
#
# $FreeBSD$
#

PORTNAME=	DBD-SQLite
PORTVERSION=	1.12
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBD
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Provides access to SQLite3 databases through the DBI

# We use sqlite3's own library & headers since it is more recent
# than the bundled version and has an incompatible DB file format.
# In this way we can be sure DBD::SQLite can interoperate with
# databases/sqlite3.
BUILD_DEPENDS=	sqlite>=3.3.3:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CONFIGURE_ARGS+=	USE_LOCAL_SQLITE=0
CONFIGURE_ARGS+=	SQLITE_LOCATION=${LOCALBASE}

MAN3=		DBD::SQLite.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI-137
.else
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
.endif

post-patch:
	${RM} -f ${WRKSRC}/getsqlite.pl
	${PERL} -pi -e 's/\$$Config{d_usleep}/1/' ${WRKSRC}/Makefile.PL
	${PERL} -pi -e '$$_="" if m|getsqlite.pl|' ${WRKSRC}/MANIFEST

.include <bsd.port.post.mk>
