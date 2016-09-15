# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	yasql
PORTVERSION=	1.83
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another SQL*Plus Replacement

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	p5-DBD-Oracle>0:databases/p5-DBD-Oracle \
		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu

USES=		perl5
GNU_CONFIGURE=	yes
ALL_TARGET=	default

NO_ARCH=	yes

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		CSV HIRES READKEY DOCS

CSV_DESC=		Support for in/out CSV files
CSV_BUILD_DEPENDS=	p5-Text-CSV_XS>0:textproc/p5-Text-CSV_XS
HIRES_DESC=		Support for high resolution benchmarking
HIRES_BUILD_DEPENDS=	p5-Time-HiRes>0:devel/p5-Time-HiRes
READKEY_DESC=		Better input and output control
READKEY_BUILD_DEPENDS=	p5-Term-ReadKey>0:devel/p5-Term-ReadKey

post-patch:
	@${REINPLACE_CMD} -e \
		's| /bin/more| /usr/bin/more|' ${WRKSRC}/yasql.conf

post-build:
	@${LN} -sf yasql.conf ${WRKSRC}/yasql.conf.sample

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/yasql ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yasql.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/yasql.conf.sample ${STAGEDIR}${PREFIX}/etc

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/yasql.html \
		${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
