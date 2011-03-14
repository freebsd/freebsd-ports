# New ports collection makefile for:	quake-source
# Date created:				15 Sep 2005
# Whom:					Alejandro Pulver <alejandro@varnet.biz>
#
# $FreeBSD$
#

PORTNAME=	source
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	source
PKGNAMEPREFIX=	quake-
DISTNAME=	qcc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake and QuakeWorld source

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	QUAKEWORLD "Install QuakeWorld source" on

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

.include "Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_QUAKEWORLD)
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/unix/:qw|}
DISTFILES+=	qwsv-2.30-glibc-i386-unknown-linux2.0${EXTRACT_SUFX}:qw
PLIST_SUB+=	QUAKEWORLD=""
.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${FILE} | \
		${GREP} 'CRLF' | ${SED} -e 's/:.*//' | \
		${XARGS} ${REINPLACE_CMD} -i "" -e "s/`${PRINTF} '\r'`$$//"

post-patch:
	@${RM} ${WRKSRC}/send/v101qc/progs.src.orig

do-install:
	${MKDIR} ${DATADIR}
	${CP} -R ${WRKSRC}/send/v101qc ${DATADIR}
.if !defined(WITHOUT_QUAKEWORLD)
	${MKDIR} ${DATADIR}/qw
.   for f in *.h *.qc *.src
	@${REINPLACE_CMD} -e "s|`${ECHO_CMD} -e '\r'`$$||" ${WRKSRC}/qw/${f}
	${INSTALL_DATA} ${WRKSRC}/qw/${f} ${DATADIR}/qw
.   endfor
.endif

.include <bsd.port.post.mk>
