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

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USES=		perl5

PORTDOCS=	*
PLIST_FILES=	bin/dailystrips \
		bin/dailystrips-clean \
		bin/dailystrips-update \
		share/dailystrips/strips.def
PLIST_DIRS=	share/dailystrips

PORTSCOUT=	limit:^1\.0\.

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} 's|^#!/usr/bin/perl|#!${PERL}|; \
		s!/usr/share/dailystrips/strips.def!${DATADIR}/strips.def!' \
		${WRKSRC}/dailystrips ${WRKSRC}/dailystrips-clean \
		${WRKSRC}/dailystrips-update

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips-clean ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/dailystrips-update ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/strips.def ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in README README.DEFS README.LOCAL README.dailystrips-clean \
	README.dailystrips-update
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
