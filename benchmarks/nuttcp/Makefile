# Created by: Andy Clark <andrewclarkii@gmail.com>
# $FreeBSD$

PORTNAME=	nuttcp
PORTVERSION=	7.3.2
CATEGORIES=	benchmarks net
MASTER_SITES=	http://nuttcp.net/nuttcp/beta/ http://nuttcp.net/nuttcp/latest/:latest
DISTFILES=	${PORTNAME}-${PORTVERSION}.c ${NUTTSCPDISTFILE} ${PORTNAME}.8:latest examples.txt:latest LICENSE:latest README:latest
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	# none

MAINTAINER=	pi@FreeBSD.org
COMMENT=	TCP/UDP network testing tool

NO_WRKSUBDIR=	yes
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
	${CP} ${_DISTDIR}/${NUTTSCPDISTFILE} ${WRKSRC}/nuttscp
	${CP} ${_DISTDIR}/${PORTNAME}-${PORTVERSION}.c ${WRKSRC}
	${CP} ${_DISTDIR}/${PORTNAME}.8 ${WRKSRC}
	${CP} ${_DISTDIR}/LICENSE ${WRKSRC}
	${CP} ${_DISTDIR}/README ${WRKSRC}
	${CP} ${_DISTDIR}/examples.txt ${WRKSRC}

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o ${PORTNAME} nuttcp-${PORTVERSION}.c

do-install-NUTTSCP-on:
	${INSTALL_SCRIPT} ${WRKSRC}/nuttscp ${STAGEDIR}${PREFIX}/bin/
	( cd ${STAGEDIR}${PREFIX}/bin; ${LN} -sf nuttscp nuttrcp )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${MAN8PREFIX}/man/man8/

	${MKDIR} ${STAGEDIR}${DATADIR}/
.	for file in LICENSE README examples.txt
		${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DATADIR}/
.	endfor

.include <bsd.port.mk>
