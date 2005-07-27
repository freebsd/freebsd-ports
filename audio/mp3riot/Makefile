# New ports collection makefile for:	mp3riot
# Date created:			29 July 2003
# Whom:				Francisco Gomez <francisco@gomezmarin.com>
#
# $FreeBSD$
#

PORTNAME=	mp3riot
PORTVERSION=	1.3
CATEGORIES=	audio
MASTER_SITES=	http://www.linuxsecure.de/f2html/

MAINTAINER=	francisco@gomezmarin.com
COMMENT=	Mp3riot creates mp3 playlists, HTML files, etc

RUN_DEPENDS=	${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info

NO_BUILD=	yes
USE_ZIP=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	example.unix groupfile CHANGELOG MANUAL mp3table.sql README repl.dat TODO utf.dat
PLIST_FILES=	bin/mp3riot

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp3riot ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for item in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${item} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
