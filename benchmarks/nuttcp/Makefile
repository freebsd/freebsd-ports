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

USE_BZIP2=	yes
MAKEFILE=	/dev/null
ALL_TARGET=	${PORTNAME}
MAN8=		${PORTNAME}.8

NUTTSCPVERSION=	1.7
NUTTSCPDISTFILE=nuttscp-${NUTTSCPVERSION}

OPTIONS_DEFINE=	NUTTSCP
OPTIONS_DEFAULT=	NUTTSCP

NUTTSCP_DESC=	Install script for copying files over nuttcp

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNUTTSCP}
USES+=		perl5
PLIST_SUB+=	NUTTSCP=""
.else
PLIST_SUB+=	NUTTSCP="@comment "
.endif

.include <bsd.port.pre.mk>

post-extract:	.SILENT
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${NUTTSCPDISTFILE} ${WRKDIR}/nuttscp

post-patch:	.SILENT
	${FIND} ${WRKSRC}/ -type f -exec \
		${REINPLACE_CMD} 's|/usr/local|${PREFIX}|g' {} +
	${REINPLACE_CMD} 's|/usr/bin/perl|${PERL}|g' ${WRKDIR}/nuttscp

do-install:
.	if ${PORT_OPTIONS:MNUTTSCP}
		${INSTALL_SCRIPT} ${WRKDIR}/nuttscp ${PREFIX}/bin/
		( cd ${PREFIX}/bin; ${LN} -sf nuttscp nuttrcp )
.	endif

	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${MAN8PREFIX}/man/man8/

	${MKDIR} ${DATADIR}/
.	for file in LICENSE README examples.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${DATADIR}/
.	endfor

	${MKDIR} ${PREFIX}/etc/xinetd.d/
.	for file in ${PORTNAME} ${PORTNAME}4 ${PORTNAME}6
		${INSTALL_DATA} ${WRKSRC}/xinetd.d/${file} \
			${PREFIX}/etc/xinetd.d/
.	endfor

.include <bsd.port.post.mk>
