# New ports collection makefile for:	Vampire Slayer Server
# Date created:				Sun Sep 23 03:23:31 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	vs
PORTVERSION=	2.0.0b
MASTER_SITES=	http://www.dnagames.net/files/half-life/vampireslayer/ \
		ftp://fileplanet.ngi.it/fileplanet2/planethalflife/vampire/ \
		ftp://ftp.netgames-uk.net/pub/local.games/halflife/mods/vampire_slayer/ \
		http://194.195.228.132/exp/hl/mod/vampier/ \
		ftp://ftp.gigabell.net/pub/exp/hl/mod/vampier/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/vampier/ \
		http://ftp2.extreme-players.de/exp/hl/mod/vampier/ \
		http://xferla.fileplanet.com/planethalflife/vampire/ \
		http://xfer.fileplanet.com/planethalflife/vampire/
DISTFILES=	vs_l-2.0_full.tgz vs_l-2.0b_so.tgz
EXTRACT_ONLY=	vs_l-2.0_full.tgz

MAINTAINER=	lioux@FreeBSD.org

WRKSRC=		${WRKDIR}/VS

post-extract:
	@${TAR} -C ${WRKSRC}/dlls/ -xzf \
		${DISTDIR}/${DISTFILES:S/${EXTRACT_ONLY}//}

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
