PORTNAME=	BerkeleyDB
PORTVERSION=	0.65
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl5 interface to the Berkeley DB package

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

TEST_DEPENDS=	p5-MLDBM>=0:databases/p5-MLDBM \
		p5-Test-Pod>=1:devel/p5-Test-Pod

USES=		bdb perl5 shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	mkconsts.pl

post-patch:
	@${ECHO_CMD} "INCLUDE = ${BDB_INCLUDE_DIR}" > ${WRKSRC}/config.in
	@${ECHO_CMD} "LIB = ${LOCALBASE}/lib" >> ${WRKSRC}/config.in
	@${ECHO_CMD} "DBNAME = -l${BDB_LIB_NAME}" >> ${WRKSRC}/config.in

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/BerkeleyDB/BerkeleyDB.so

.include <bsd.port.mk>
