# New ports collection makefile for:	cue2toc
# Date created:				24th September 2003
# Whom:					Pav Lucistnik <pav@oook.cz>
#
# $FreeBSD$
#

PORTNAME=	cue2toc
PORTVERSION=	0.1
CATEGORIES=	audio perl5
MASTER_SITES=	http://www.tuxcoder.com/cue2toc/download/ \
		http://www.oook.cz/bsd/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl script that converts CUE files into TOC files for cdrdao

RUN_DEPENDS=	p5-Audio-Wav>=0:${PORTSDIR}/audio/p5-Audio-Wav

NO_BUILD=	yes
PLIST_FILES=	bin/cue2toc.pl
USE_PERL5=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's|use warnings;||' ${WRKDIR}/cue2toc

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/cue2toc ${PREFIX}/bin/cue2toc.pl

.include <bsd.port.mk>
