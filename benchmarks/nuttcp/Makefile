# Created by: Andy Clark <andrewclarkii@gmail.com>
# $FreeBSD$

PORTNAME=	nuttcp
PORTVERSION=	6.1.2
CATEGORIES=	benchmarks net
MASTER_SITES=	ftp://ftp.lcp.nrl.navy.mil/pub/${PORTNAME}/ \
		ftp://ftp.lcp.nrl.navy.mil/pub/${PORTNAME}/beta/:beta
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${NUTTSCPDISTFILE}:beta
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	andrewclarkii@gmail.com
COMMENT=	TCP/UDP network testing tool

USES=		shebangfix
SHEBANG_FILES=	../nuttscp
USE_BZIP2=	yes
MAKEFILE=	/dev/null
ALL_TARGET=	${PORTNAME}

NUTTSCPVERSION=	1.7
NUTTSCPDISTFILE=nuttscp-${NUTTSCPVERSION}

OPTIONS_DEFINE=	NUTTSCP
OPTIONS_DEFAULT=	NUTTSCP

NUTTSCP_DESC=	Install script for copying files over nuttcp
OPTIONS_SUB=	yes
NUTTSCP_USES=	perl5

.include <bsd.port.options.mk>

post-extract:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/${NUTTSCPDISTFILE} ${WRKDIR}/nuttscp

post-patch:
	${FIND} ${WRKSRC}/ -type f -exec \
		${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' {} +

do-install:
.	if ${PORT_OPTIONS:MNUTTSCP}
		${INSTALL_SCRIPT} ${WRKDIR}/nuttscp ${STAGEDIR}${PREFIX}/bin/
		( cd ${STAGEDIR}${PREFIX}/bin; ${LN} -sf nuttscp nuttrcp )
.	endif

	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

	${MKDIR} ${STAGEDIR}${DATADIR}/
.	for file in LICENSE README examples.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}/
.	endfor

	${MKDIR} ${STAGEDIR}${PREFIX}/etc/xinetd.d/
.	for file in ${PORTNAME} ${PORTNAME}4 ${PORTNAME}6
		${INSTALL_DATA} ${WRKSRC}/xinetd.d/${file} \
			${STAGEDIR}${PREFIX}/etc/xinetd.d/
.	endfor

.include <bsd.port.mk>
