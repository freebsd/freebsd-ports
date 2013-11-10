# Created by: T. William Wells <bill@twwells.com>
# $FreeBSD$

PORTNAME=	BerkeleyDB
PORTVERSION=	0.54
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:PMQS
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the Berkeley DB package

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-MLDBM>=0:${PORTSDIR}/databases/p5-MLDBM \
		p5-Test-Pod>=1:${PORTSDIR}/devel/p5-Test-Pod

USES=		perl5 shebangfix
USE_PERL5=	configure
USE_BDB=	47+

SHEBANG_FILES=	mkconsts.pl

post-patch:
	@${ECHO} "INCLUDE = ${BDB_INCLUDE_DIR}" > ${WRKSRC}/config.in
	@${ECHO} "LIB = ${LOCALBASE}/lib" >> ${WRKSRC}/config.in
	@${ECHO} "DBNAME = -l${BDB_LIB_NAME}" >> ${WRKSRC}/config.in

.include <bsd.port.mk>
