# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	1.0.5
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer for the Raspberry Pi

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	f5b0c0d

MAKE_ARGS=	FULLPREFIX="${STAGEDIR}${PREFIX}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dcf77pi
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/readpin
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif
	if [ ! -f ${ETCDIR}/config.txt ] ; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/config.txt.sample ${STAGEDIR}${ETCDIR}/config.txt ; \
	fi

.include <bsd.port.mk>
