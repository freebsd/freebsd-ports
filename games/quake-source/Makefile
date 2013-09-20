# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	source
PORTVERSION=	1.01
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_IDSOFTWARE}
MASTER_SITE_SUBDIR=	source
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MQUAKEWORLD}
MASTER_SITES+=	${MASTER_SITE_IDSOFTWARE:S|$|quakeworld/unix/:qw|}
DISTFILES+=	qwsv-2.30-glibc-i386-unknown-linux2.0${EXTRACT_SUFX}:qw
COMMENT:=	${COMMENT:S/Quake/& and QuakeWorld/}
PLIST_SUB+=	QUAKEWORLD=""
.else
PLIST_SUB+=	QUAKEWORLD="@comment "
.endif

pre-patch:
# CRLF -> LF conversion (XXX why not USE_DOS2UNIX?)
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${FILE} | \
		${GREP} 'CRLF' | ${SED} -e 's/:.*//' | ${XARGS} \
			${REINPLACE_CMD} -i "" -e "s/`${PRINTF} '\r'`$$//"

post-patch:
	@${REINPLACE_CMD} -e 's,^\.\.,.,' ${WRKSRC}/send/v101qc/progs.src
	@${RM} ${WRKSRC}/send/v101qc/progs.src.bak

do-install:
	@${MKDIR} ${DATADIR}
	${CP} -a ${WRKSRC}/send/v101qc ${DATADIR}
.if ${PORT_OPTIONS:MQUAKEWORLD}
	@${MKDIR} ${DATADIR}/qw
.  for f in *.h *.qc *.src
	@${REINPLACE_CMD} -e "s|`${ECHO_CMD} -e '\r'`$$||" ${WRKSRC}/qw/${f}
	${INSTALL_DATA} ${WRKSRC}/qw/${f} ${DATADIR}/qw
.  endfor
.endif

.include "Makefile.include"
.include <bsd.port.mk>
