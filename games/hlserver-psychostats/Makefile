# New ports collection makefile for:	Half Life Psychostats
# Date created:				Sun Oct 14 14:34:20 CEST 2001
# Whom:					martin@tradex.sk
#
# $FreeBSD$
#

PORTNAME=	psychostats
PORTVERSION=	1.9.1
CATEGORIES=	games www
MASTER_SITES=	ftp://ftp.thaiguy.net/ \
		http://www.psychostats.com/dl/ \
		http://www.realityslap.com/downloads/ \
		http://fratello-server.com/downloads/serveur/ \
		http://mirrors.voyager.net/games/halflife/stats/psychostats/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	martin@tradex.sk
COMMENT=	Popular player statistics generator for Half-Life (cs/dod)

WRKSRC=		${WRKDIR}/${DISTNAME}

# files which should be installed with executable perms
EXECUTABLES=	stats.pl install.pl

post-patch:
.for files in ${EXECUTABLES}
	@${PERL} -pi -e 's|/usr/bin/perl|${PERL}|' \
		${WRKSRC}/${files}
.endfor
	@${PERL} -pi -e 's|%%PREFIX%%|${PREFIX}|; \
		s|%%LOCALBASE%%|${LOCALBASE}|; \
		s|%%HLDSDIR%%|${HLDSDIR}|' \
		${WRKSRC}/stats.cfg

slaveport-post-install:
.for files in ${EXECUTABLES}
	 @${CHMOD} u+x ${PREFIX}${HLDSDIR}${DISTNAME}/${files}
.endfor

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
