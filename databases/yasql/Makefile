# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	yasql
PORTVERSION=	1.83
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Yet Another SQL*Plus Replacement

LICENSE=	GPLv2

RUN_DEPENDS=	p5-DBD-Oracle>0:databases/p5-DBD-Oracle \
		p5-Term-ReadLine-Gnu>0:devel/p5-Term-ReadLine-Gnu

NO_ARCH=	yes

USES=		perl5
GNU_CONFIGURE=	yes
ALL_TARGET=	default

SUB_FILES=	pkg-message

OPTIONS_DEFINE=		CSV HIRES READKEY

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
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} yasql \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} yasql.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	(cd ${WRKSRC} && ${INSTALL_MAN} yasql.conf.sample \
		${STAGEDIR}${PREFIX}/etc)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} README yasql.html \
		${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
