# Created by: Andy Clark <andrewclarkii@gmail.com>
# $FreeBSD$

PORTNAME=	nuttcp
PORTVERSION=	7.3.2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://nuttcp.net/nuttcp/
DISTFILES=	beta/${PORTNAME}-${PORTVERSION}.c beta/${NUTTSCPDISTFILE} latest/${PORTNAME}.8 latest/examples.txt latest/LICENSE latest/README
EXTRACT_ONLY=	# none
WRKSRC=		${WRKDIR}

MAINTAINER=	pi@FreeBSD.org
COMMENT=	TCP/UDP network testing tool

USES=		shebangfix
SHEBANG_FILES=	nuttscp

NUTTSCPVERSION=	2.2
NUTTSCPDISTFILE=nuttscp-${NUTTSCPVERSION}

OPTIONS_DEFINE=	NUTTSCP
OPTIONS_DEFAULT=NUTTSCP

NUTTSCP_DESC=	Install script for copying files over nuttcp
OPTIONS_SUB=	yes
NUTTSCP_USES=	perl5

post-extract:
	${CP} ${DISTDIR}/beta/${NUTTSCPDISTFILE} ${WRKDIR}/nuttscp
	${CP} ${DISTDIR}/beta/${PORTNAME}-${PORTVERSION}.c ${WRKDIR}/
	${CP} ${DISTDIR}/latest/${PORTNAME}.8 ${WRKDIR}/
	${CP} ${DISTDIR}/latest/LICENSE ${WRKDIR}/
	${CP} ${DISTDIR}/latest/README ${WRKDIR}/
	${CP} ${DISTDIR}/latest/examples.txt ${WRKDIR}/

do-build:
	cd ${WRKDIR} && ${CC} -o ${PORTNAME} nuttcp-${PORTVERSION}.c

do-install-NUTTSCP-on:
	${INSTALL_SCRIPT} ${WRKDIR}/nuttscp ${STAGEDIR}${PREFIX}/bin/
	( cd ${STAGEDIR}${PREFIX}/bin; ${LN} -sf nuttscp nuttrcp )

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKDIR}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

	${MKDIR} ${STAGEDIR}${DATADIR}/
.	for file in LICENSE README examples.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}/
.	endfor

.include <bsd.port.mk>
