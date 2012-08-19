# New ports collection makefile for:	insub
# Date created:			27 Dec 2003
# Whom:				Alfred Perlstein <alfred@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	insub
PORTVERSION=	15.0
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://cloud.github.com/downloads/cjones/insub/

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Some scripts for expressing how you feel on IRC and the web

RUN_DEPENDS=	cowsay:${PORTSDIR}/games/cowsay \
		figlet:${PORTSDIR}/misc/figlet

NO_BUILD=	YES

USE_BZIP2=	YES
USE_PERL5=	5.6+

SCRIPT=	${PORTNAME}.pl

COWLIST=	2bear ahnold apple ass baa bendover bendover2 bigcow blam \
			cack cake canada chick1 chocobo clippy clover cockasaur copter \
			dance dick doggies duck erect ferret fish flag flagasaur goatse \
			gobble heart invdragon ipedo jesus limp lobster missle nascar \
			nuke nuke2 pedo peek peepees penii penis penisbird pez pig pman \
			point poland pr8 psyduck puffy pumpkin puppy retard santa santa2 \
			saq satan shark shlong smpez spam spider standtall stud1 stud2 \
			tampon turkey-penis urinal usa wang weed wtc wtf-pony wtf wtf2 zig

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${SCRIPT} ${PREFIX}/bin/${SCRIPT:R}
	${MKDIR} ${PREFIX}/share/irssi/scripts/
	${INSTALL_DATA} ${WRKSRC}/${SCRIPT} \
		${PREFIX}/share/irssi/scripts/${SCRIPT}
	${MKDIR} ${PREFIX}/share/cows/
.for c in ${COWLIST}
	@${INSTALL_DATA} ${WRKSRC}/cows/${c}.cow ${PREFIX}/share/cows
.endfor
#	cd ${WRKSRC} && \
#		${FIND} cows | ${CPIO} -pdmu ${PREFIX}/share/

.include <bsd.port.mk>
