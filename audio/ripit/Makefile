# Created by: oyvindmo@initio.no

PORTNAME=	ripit
PORTVERSION=	3.9.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	https://github.com/blabber/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	Command line audio CD ripper

LICENSE=	GPLv2

DEPRECATED=	Upstream no longer maintained, use audio/abcde instead
EXPIRATION_DATE=	2021-07-17

# See pkg-message about other dependencies.
RUN_DEPENDS=	p5-CDDB_get>=0:audio/p5-CDDB_get \
	p5-libwww>=0:www/p5-libwww \
	p5-WebService-MusicBrainz>=0:www/p5-WebService-MusicBrainz \
	p5-MusicBrainz-DiscID>=0:audio/p5-MusicBrainz-DiscID \
	lame:audio/lame \
	cdparanoia:audio/cdparanoia

USES=		perl5 shebangfix tar:bzip2
USE_PERL5=	run

NO_BUILD=	yes
NO_ARCH=	yes
SHEBANG_FILES=	ripit.pl

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${STAGEDIR}${PREFIX}/bin/ripit
	${INSTALL_MAN} ${WRKSRC}/ripit.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/config ${STAGEDIR}${EXAMPLESDIR}/config

.include <bsd.port.mk>
