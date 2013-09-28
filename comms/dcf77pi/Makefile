# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	1.0.4
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer for the Raspberry Pi

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	75f6f04

MAKE_ARGS=	FULLPREFIX="${STAGEDIR}${PREFIX}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
.endif
	if [ ! -f ${ETCDIR}/hardware.txt ] ; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/hardware.txt.sample ${STAGEDIR}${ETCDIR}/hardware.txt ; \
	fi

.include <bsd.port.mk>
