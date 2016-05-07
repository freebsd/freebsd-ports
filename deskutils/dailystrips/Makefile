# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	dailystrips
PORTVERSION=	1.0.28
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	deskutils www
MASTER_SITES=	SF

MAINTAINER=	jgh@FreeBSD.org
COMMENT=	Utility to download or view your favorite online comic strips daily

LICENSE=	GPLv2

RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww \
		p5-TimeDate>=0:devel/p5-TimeDate

NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	${WRKSRC}/dailystrips*

PORTSCOUT=	limit:^1\.0\.

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} ' s!/usr/share/dailystrips/strips.def!${DATADIR}/strips.def!' \
		${WRKSRC}/dailystrips ${WRKSRC}/dailystrips-clean \
		${WRKSRC}/dailystrips-update

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips-clean ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips-update ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/strips.def ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in README README.DEFS README.LOCAL README.dailystrips-clean \
	README.dailystrips-update
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
