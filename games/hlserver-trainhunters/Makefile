# New ports collection makefile for:	Train Hunters Server
# Date created:				Wed Nov 13 06:26:08 UTC 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	trainhunters
PORTVERSION=	2.0.b0
MASTER_SITES=	http://th.fragoff.net/files/:WAD
DISTFILES=	thb20.tar.gz \
		spraypaint.wad:WAD
EXTRACT_ONLY=	thb20.tar.gz

MAINTAINER=	lioux@FreeBSD.org

_DONT_INCLUDE_MK_=yes

HALFLIFE_COUNTERSTRIKE_MASTER=	${.CURDIR}/../hlserver-cs

.include "${HALFLIFE_COUNTERSTRIKE_MASTER}/Makefile"

slaveport-post-extract:
	@cp -f ${DISTDIR}/spraypaint.wad ${WRKSRC}

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/thb20.tar.gz)
IGNORE=		You must manually fetch the Linux Port distfile\
		(${DISTFILES:M*tar.gz}) from http://www.fileplanet.com/dl/dl.asp?/planethalflife/svinstagib/${DISTFILES:M*tar.gz},\
		place it in ${DISTDIR} and then run make again
.endif

.include <bsd.port.post.mk>
