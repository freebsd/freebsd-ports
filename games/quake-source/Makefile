# New ports collection makefile for:	quake-source
# Date created:				15 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	source
PORTVERSION=	1.01
CATEGORIES=	games
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/:s \
		ftp://ftp.fasta.fh-dortmund.de/mirror/idstuff/source/:s
PKGNAMEPREFIX=	quake-
DISTNAME=	qcc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:s

MAINTAINER=	alejandro@varnet.biz
COMMENT=	Quake and QuakeWorld source

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	QUAKEWORLD "Install QuakeWorld source" on

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_QUAKEWORLD)
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/quakeworld/unix/:qw \
		ftp://ftp.fasta.fh-dortmund.de/mirror/idstuff/quakeworld/unix/:qw
DISTFILES+=	qwsv-2.30-glibc-i386-unknown-linux2.0${EXTRACT_SUFX}:qw
USE_REINPLACE=	yes
PLIST_SUB+=	QUAKEWORLD=""
.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif

do-install:
	@${MKDIR} ${DATADIR}
	@${CP} -R ${WRKSRC}/send/v101qc ${DATADIR}
.if defined(WITH_QUAKEWORLD)
	@${MKDIR} ${DATADIR}/qw
.   for f in *.h *.qc *.src
	@${REINPLACE_CMD} -e "s|`${ECHO_CMD} -e '\r'`$$||" ${WRKSRC}/qw/${f}
	@${INSTALL_DATA} ${WRKSRC}/qw/${f} ${DATADIR}/qw
.   endfor
.endif

.include <bsd.port.post.mk>
