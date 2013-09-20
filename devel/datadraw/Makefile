# Created by: ijliao
# $FreeBSD$

PORTNAME=	datadraw
PORTVERSION=	3.1.1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Feature rich persistent database generator

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
ALL_TARGET=	# empty

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000013
USES+=		bison
.else
post-patch:
	${REINPLACE_CMD} -e "s/bison/byacc/g" ${WRKSRC}/configure
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*

post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/www/* ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
