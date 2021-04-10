# Created by: Jov amutu@amutu.com

PORTNAME=	ora2pg
PORTVERSION=	21.1
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Oracle to PostgreSQL database schema converter

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Class-DBI-Pg>=0:databases/p5-Class-DBI-Pg \
		p5-Class-DBI-mysql>=0:databases/p5-Class-DBI-mysql \
		p5-Class-DBI-Oracle>=0:databases/p5-Class-DBI-Oracle
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
USE_GITHUB=	yes

GH_ACCOUNT=	darold
NO_ARCH=	yes
DOCS=		changelog README

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/install_all :/,/};/s=$$CONFDIR=${STAGEDIR}${ETCDIR}=g' \
		-e '/install_all :/,/};/s=$$DOCDIR=${STAGEDIR}${DOCSDIR}=g' \
		${WRKSRC}/Makefile.PL

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
	${RM} ${STAGEDIR}${DOCSDIR}/INSTALL

.include <bsd.port.mk>
