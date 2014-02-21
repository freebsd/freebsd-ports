# Created by: rene@FreeBSD.org
# $FreeBSD$

PORTNAME=	dcf77pi
PORTVERSION=	2.0.1
CATEGORIES=	comms

MAINTAINER=	rene@FreeBSD.org
COMMENT=	DCF77 receiver/logger/analyzer for the Raspberry Pi

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	rene0
GH_COMMIT=	9865afc

USES=		ncurses

PORTDOCS=	README.md

INSTALL_TARGET=	install-strip

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	if [ ! -f ${ETCDIR}/config.txt ] ; then \
		${CP} -p ${STAGEDIR}${ETCDIR}/config.txt.sample ${STAGEDIR}${ETCDIR}/config.txt ; \
	fi

.include <bsd.port.mk>
