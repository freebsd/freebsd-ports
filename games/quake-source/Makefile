# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	source
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	IDSOFTWARE/source
PKGNAMEPREFIX=	quake-
DISTNAME=	qcc
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake game source code

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

LATEST_LINK=	${PKGNAMEPREFIX}${PORTNAME}

OPTIONS_DEFINE=	QUAKEWORLD
OPTIONS_DEFAULT=	QUAKEWORLD

QUAKEWORLD_DESC=	Install QuakeWorld game source

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUAKEWORLD}
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/unix/:qw|}
DISTFILES+=	qwsv-2.30-glibc-i386-unknown-linux2.0${EXTRACT_SUFX}:qw
COMMENT:=	${COMMENT:S/Quake/& and QuakeWorld/}
PLIST_SUB+=	QUAKEWORLD=""
.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^\.\.,.,' ${WRKSRC}/send/v101qc/progs.src
	@${RM} ${WRKSRC}/send/v101qc/progs.src.bak

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${CP} -a ${WRKSRC}/send/v101qc ${STAGEDIR}${DATADIR}
.if ${PORT_OPTIONS:MQUAKEWORLD}
	@${MKDIR} ${STAGEDIR}${DATADIR}/qw
.  for f in *.h *.qc *.src
	@${REINPLACE_CMD} -e 's,[[:cntrl:]]*$$,,' ${WRKSRC}/qw/${f}
	${INSTALL_DATA} ${WRKSRC}/qw/${f} ${STAGEDIR}${DATADIR}/qw
.  endfor
.endif

.include "Makefile.include"
.include <bsd.port.mk>
