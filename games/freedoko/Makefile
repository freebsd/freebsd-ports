# New ports collection makefile for:	FreeDoko
# Date created:		02 Jun 2004
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	freedoko
PORTVERSION=	0.6.8
#PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	free-doko
DISTNAME=	FreeDoko_${PORTVERSION}.src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Play the card game Doppelkopf

LIB_DEPENDS=	gtkmm-2.0.6:${PORTSDIR}/x11-toolkits/gtk--2

USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:C/\.src$//}/src
USE_REINPLACE=	yes
USE_GMAKE=	yes
MAKE_ENV=	OSTYPE=linux-gnu DATADIR=${DATADIR}

CPIOFLAGS=	--quiet -pdum -R ${SHAREOWN}:${SHAREGRP}
DATASUBDIRS=	ai backgrounds cardsets rules translations

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on FreeBSD 4.x"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/FreeDoko ${PREFIX}/bin
	${LN} ${PREFIX}/bin/FreeDoko ${PREFIX}/bin/freedoko
	@${MKDIR} ${DATADIR}
	@cd ${WRKSRC}/../data && \
	 ${FIND} ${DATASUBDIRS} ! -name Makefile\* \
	 | ${CPIO} ${CPIOFLAGS} ${DATADIR}
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/../doc && \
	 ${FIND} . ! -name Makefile\* | ${CPIO} ${CPIOFLAGS} ${DOCSDIR}

.include <bsd.port.post.mk>
