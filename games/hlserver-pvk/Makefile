# New ports collection makefile for:	Pirates, Vikings & Knights Server
# Date created:			Sun Sep 30 18:09:54 BRT 2001
# Whom:		Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pvk
PORTVERSION=	2.2.b
MASTER_SITES=	ftp://fileplanet.ngi.it/fileplanet2/planethalflife/ \
		http://www.pvkmod.net/files/

DISTFILES=	pvk_2.1_full.tar.gz pvkb22so.gz
EXTRACT_ONLY=	pvk_2.1_full.tar.gz

MAINTAINER=	lioux@FreeBSD.org

post-extract:
	@${GZCAT} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES:S/${EXTRACT_ONLY}//} \
		> ${WRKSRC}/dlls/pvk_i386.so

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"
