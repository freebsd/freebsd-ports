# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer for the Raspberry Pi

LICENSE=	BSD

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	3e51be2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${DOCSDIR}
.endif
	if [ ! ${ETCDIR}/hardware.txt ] ; then \
		${CP} -p ${ETCDIR}/hardware.txt.sample ${ETCDIR}/hardware.txt ; \
	fi

.include <bsd.port.mk>
