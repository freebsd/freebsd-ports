# New ports collection makefile for:	Half Life Psychostats
# Date created:				Sun Oct 14 14:34:20 CEST 2001
# Whom:					martin@tradex.sk
#
# $FreeBSD$
#

PORTNAME=	psychostats
PORTVERSION=	1.7
CATEGORIES=	games www
MASTER_SITES=	ftp://ftp.psychostats.com/psychostats/ \
		http://www.madeagle.ru/apps/stats/psychostats/linux/1.7/ \
		http://www.realityslap.com/downloads/ \
		http://www.freebooters.org/ps/ \
		http://www.cool-squad.com/downloads/ \
		http://www.green-goblin.de/psychostats/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	martin@tradex.sk

WRKSRC=		${WRKDIR}/${DISTNAME}

# files which should be installed with executable perms
EXECUTABLES=	stats install.pl

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
