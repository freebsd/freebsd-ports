# New ports collection makefile for:	abuse_frabs
# Date created:				11 May 2002
# Whom:					des
#
# $FreeBSD$
#

PORTNAME=	frabs
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.cs.uidaho.edu/~cass0664/fRaBs/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The fRaBs (Free Abuse) data files for the Abuse game engine

RUN_DEPENDS=	abuse.sdl:${PORTSDIR}/games/abuse_sdl

USE_ZIP=	YES
NO_BUILD=	YES

WRKSRC=		${WRKDIR}/fRaBs${PORTVERSION:S/.//g}
ABUSEDATA=	sfx register netlevel music lisp levels art addon abuse.lsp

do-patch:
	(cd ${WRKSRC} && ${SH} ${SCRIPTDIR}/fixup.sh ${ABUSEDATA})

do-configure:
	${SED} -e 's,%%DATADIR%%,${DATADIR},' \
		${FILESDIR}/frabs.sh >${WRKDIR}/frabs

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/frabs ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	(cd ${WRKSRC} && ${TAR} cf - ${ABUSEDATA} | ${TAR} xf - -C ${DATADIR})

.include <bsd.port.mk>
