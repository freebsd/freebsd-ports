# Created by: Tony Maher <tonym@biolateral.com.au>
# $FreeBSD$

PORTNAME=	primer3
PORTVERSION=	2.3.5
CATEGORIES=	biology
MASTER_SITES=	SF

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Primer3 helps to choose primers for PCR reactions

LICENSE=	GPLv2

USES=		gmake
MAKE_ARGS=	CC=${CC} CPP=${CXX}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/src
PLIST_FILES=	bin/primer3

post-patch:
	@${REINPLACE_CMD} \
		-e 's#^CFLAGS.*#CFLAGS  += \$$\(CC_OPTS\)#;' \
		-e 's#CC_OPTS = -g#CC_OPTS =#;' \
		-e 's#LDFLAGS = -g#LDFLAGS +=#;' \
		-e 's#^WHITEHEAD_SPECIFIC_HACK.*##;' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/primer3_core \
		${STAGEDIR}${PREFIX}/bin/primer3

.include <bsd.port.mk>
