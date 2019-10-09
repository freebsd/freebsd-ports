# Created by: Filippo Natali <filippo.natali@gmail.com>
# $FreeBSD$

PORTNAME=	tinystats
PORTVERSION=	1.1
CATEGORIES=	dns
MASTER_SITES=	http://www.morettoni.net/bsd/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	DJB's tinydns statistics generator

LICENSE=	BSD2CLAUSE

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=

OPTIONS_DEFINE=	IPV6 EXAMPLES DOCS

PLIST_FILES=	bin/tinystats
PORTEXAMPLES=	*
PORTDOCS=	README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	-DWITH_IPV6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinystats ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tinydns.sh.sample      \
			${WRKSRC}/tinydns.log.run.sample \
			${WRKSRC}/update_slave.sh.sample \
			${WRKSRC}/start_slave.sh.sample  \
			${WRKSRC}/Makefile.sample        \
				${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
