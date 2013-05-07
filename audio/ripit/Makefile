# Created by: oyvindmo@initio.no
# $FreeBSD$

PORTNAME=	ripit
PORTVERSION=	3.9.0
PORTREVISION?=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.suwald.com/ripit/

MAINTAINER=	tobias.rehbein@web.de
COMMENT=	A command line audio CD ripper

# See pkg-message about other dependencies.
RUN_DEPENDS=	p5-CDDB_get>=0:${PORTSDIR}/audio/p5-CDDB_get \
	p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
	p5-WebService-MusicBrainz>=0:${PORTSDIR}/www/p5-WebService-MusicBrainz \
	p5-MusicBrainz-DiscID>=0:${PORTSDIR}/audio/p5-MusicBrainz-DiscID \
	lame:${PORTSDIR}/audio/lame \
	cdparanoia:${PORTSDIR}/audio/cdparanoia \

USES=	shebangfix
NO_BUILD=	yes
PLIST_FILES=	bin/ripit
MAN1=		ripit.1
PORTEXAMPLES=	config
USE_PERL5_RUN=	yes
USE_BZIP2=	yes
SHEBANG_FILES=	ripit.pl
perl_OLD_CMD=	/usr/bin/env perl

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/ripit.pl ${PREFIX}/bin/ripit
	${INSTALL_MAN} ${WRKSRC}/ripit.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/config ${EXAMPLESDIR}/config
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
