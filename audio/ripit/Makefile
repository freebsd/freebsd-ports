# Created by: oyvindmo@initio.no
# $FreeBSD$

PORTNAME=	ripit
PORTVERSION=	3.9.0
PORTREVISION?=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.suwald.com/ripit/

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Command line audio CD ripper

LICENSE=	GPLv2

# See pkg-message about other dependencies.
RUN_DEPENDS=	p5-CDDB_get>=0:${PORTSDIR}/audio/p5-CDDB_get \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-WebService-MusicBrainz>=0:${PORTSDIR}/www/p5-WebService-MusicBrainz \
	p5-MusicBrainz-DiscID>=0:${PORTSDIR}/audio/p5-MusicBrainz-DiscID \
	lame:${PORTSDIR}/audio/lame \
	cdparanoia:${PORTSDIR}/audio/cdparanoia

USES=		perl5 shebangfix tar:bzip2
NO_BUILD=	yes
USE_PERL5=	run
SHEBANG_FILES=	ripit.pl

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${STAGEDIR}${PREFIX}/bin/ripit
	${INSTALL_MAN} ${WRKSRC}/ripit.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${EXAMPLESDIR}/config

.include <bsd.port.mk>
