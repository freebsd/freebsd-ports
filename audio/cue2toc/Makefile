# New ports collection makefile for:	cue2toc
# Date created:				24th September 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	cue2toc
PORTVERSION=	0.0
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.tuxcoder.com/cue2toc/download/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Perl script that converts CUE files into TOC files for cdrdao

RUN_DEPENDS=	${SITE_PERL}/Audio/Wav.pm:${PORTSDIR}/audio/p5-Audio-Wav

NO_BUILD=	yes
PLIST_FILES=	bin/cue2toc
USE_REINPLACE=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|use warnings;||' ${WRKSRC}/cue2toc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cue2toc ${PREFIX}/bin/cue2toc

.include <bsd.port.mk>
