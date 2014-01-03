# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	1.1.2
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer for the Raspberry Pi

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	c13fd2c

MAKE_ARGS=	FULLPREFIX="${STAGEDIR}${PREFIX}"

PORTDOCS=	README.md

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/dcf77pi
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/readpin
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	if [ ! -f ${ETCDIR}/config.txt ] ; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/config.txt.sample ${STAGEDIR}${ETCDIR}/config.txt ; \
	fi

.include <bsd.port.mk>
