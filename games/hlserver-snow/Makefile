# New ports collection makefile for:	Snow War Server
# Date created:				Fri Oct 5 01:13:28 BRT 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snow
PORTVERSION=	1.0
MASTER_SITES=	http://ftp.gigabell.net/pub/exp/hl/mod/snowwar/ \
		ftp://ftp2.extreme-players.de/hl/mod/snowwar/ \
		ftp://ftp.task.gda.pl/mirror/ftp.extreme-players.de/exp/hl/mod/snowwar/
DISTFILES=	sw10.zip 10linux.zip
DIST_SUBDIR=	snow

MAINTAINER=	lioux@FreeBSD.org

USE_ZIP=	yes

slaveport-post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/hl_i386.so ${WRKSRC}/dlls

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
