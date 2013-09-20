# Created by: Filippo Natali <filippo.natali@gmail.com>
# $FreeBSD$

PORTNAME=	tinystats
PORTVERSION=	1.1
CATEGORIES=	dns ipv6
MASTER_SITES=	http://www.morettoni.net/bsd/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DJB's tinydns statistics generator

WRKSRC=		${WRKDIR}/${PORTNAME}
ALL_TARGET=

OPTIONS_DEFINE=	IPV6 DOCS

PLIST_FILES=	bin/tinystats \
		%%EXAMPLESDIR%%/tinydns.log.run.sample \
		%%EXAMPLESDIR%%/tinydns.sh.sample \
		%%EXAMPLESDIR%%/update_slave.sh.sample \
		%%EXAMPLESDIR%%/start_slave.sh.sample \
		%%EXAMPLESDIR%%/Makefile.sample
PLIST_DIRS=	%%EXAMPLESDIR%%
PORTDOCS=	README LICENSE THANKS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
MAKE_ARGS+=	-DWITH_IPV6
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tinystats ${PREFIX}/bin
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/tinydns.sh.sample ${WRKSRC}/tinydns.log.run.sample \
			${WRKSRC}/update_slave.sh.sample ${WRKSRC}/start_slave.sh.sample ${WRKSRC}/Makefile.sample ${EXAMPLESDIR}
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/LICENSE ${WRKSRC}/THANKS ${DOCSDIR}
.endif

.include <bsd.port.mk>
