# New ports collection makefile for:	abuse
# Date created:				11 May 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	abuse
PORTVERSION=	2.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.pardus.org.tr/pub/source/2007/ \
		ftp://mirror.euronet.nl/pub/mirrors/FreeBSD/distfiles/ \
		ftp://166.111.8.205/mirror/gentoo/distfiles/ \
		http://globalfilesearch.com/download/mirror.euronet.nl/pub/mirrors/tucows/linux/files/
DISTFILES=	abuse_datafiles.tar.gz
EXTRACT_ONLY=	# empty

MAINTAINER=	chris@officialunix.com
COMMENT=	The classic 2D action game Abuse

RUN_DEPENDS=	abuse.sdl:${PORTSDIR}/games/abuse_sdl

NO_BUILD=	YES

do-configure:
	${SED} -e 's,%%DATADIR%%,${DATADIR},' \
		${FILESDIR}/abuse.sh >${WRKDIR}/abuse

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/abuse ${PREFIX}/bin
	${MKDIR} ${DATADIR}
.for DISTFILE in ${DISTFILES}
	${TAR} zxf ${DISTDIR}/${DISTFILE} -C ${DATADIR}
.endfor

.include <bsd.port.mk>
