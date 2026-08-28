PORTNAME=	pgterm
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.2
CATEGORIES=	databases

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Terminal UI that monitors multiple PostgreSQL databases
WWW=		https://pgterm.dev/ \
		https://github.com/pgrundev/pgterm

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	pgbot:databases/pgbot

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	pgrundev

PLIST_FILES=	bin/${PORTNAME} \
		${DOCSDIR}/README.md

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/Makefile.crates"
.include <bsd.port.mk>
