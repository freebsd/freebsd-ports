PORTNAME=	BDB
PORTVERSION=	1.92
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MLEHMANN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Asynchronous Berkeley DB access

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-common-sense>=0:devel/p5-common-sense

USES=		bdb perl5
USE_PERL5=	configure

CFLAGS+=	-I${BDB_INCLUDE_DIR}
LDFLAGS+=	-lpthread

PORTSCOUT=	skipv:1.801

post-patch:
	@${REINPLACE_CMD} -e 's|-ldb|-l${BDB_LIB_NAME}|' ${WRKSRC}/Makefile.PL

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/BDB/BDB.so

.include <bsd.port.mk>
