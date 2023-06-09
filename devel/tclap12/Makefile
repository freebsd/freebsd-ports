PORTNAME=	tclap
PORTVERSION=	1.2.5
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}
PKGNAMESUFFIX=	12

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Verbose replacement for getopt (stable version)
WWW=		https://tclap.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe
CPE_VENDOR=	${PORTNAME}_project
GNU_CONFIGURE=	yes
TEST_TARGET=	check

CONFLICTS_INSTALL=	tclap

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '1s,/bin/bash,/bin/sh,' \
		${WRKSRC}/tests/test88.sh ${WRKSRC}/tests/test89.sh \
		${WRKSRC}/tests/test90.sh ${WRKSRC}/tests/test91.sh

.include <bsd.port.mk>
