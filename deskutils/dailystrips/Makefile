# Created by: Pete Fritchman <petef@databits.net>
# $FreeBSD$

PORTNAME=	dailystrips
PORTVERSION=	1.1.0
CATEGORIES=	deskutils www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to download or view your favorite online comic strips daily

LICENSE=	GPLv2

RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate

NO_BUILD=	yes
USE_PERL5=	yes

PORTDOCS=	*
PLIST_FILES=	bin/getstrips.pl \
		bin/makepage.pl \
		bin/shared_functions.pl \
		share/dailystrips/strips.def
PLIST_DIRS=	share/dailystrips

post-patch-script:
	@${REINPLACE_CMD} 's|^#!/usr/bin/perl|#!${PERL}|; \
		s!strips.def!${DATADIR}/strips.def!; \
		s!robotman!!; \
		s!shared_functions.pl!${PREFIX}/bin/shared_functions.pl!' \
		${WRKSRC}/getstrips.pl ${WRKSRC}/makepage.pl \
		${WRKSRC}/strips.def

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/strips.def ${DATADIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in README README.DEFS README.LOCAL archive.html
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
