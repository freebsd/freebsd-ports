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

OPTIONS_DEFINE=	DOCS

HAS_CONFIGURE=	yes
USES=		gmake
ALL_TARGET=	# empty
PORTDOCS=	*
CONFIGURE_ARGS=	--prefix=\$${DESTDIR}${PREFIX}

.include <bsd.port.options.mk>

.if ${OSVERSION} < 1000013
USES+=		bison
.else
post-patch:
	${REINPLACE_CMD} -e "s/bison/byacc/g" ${WRKSRC}/configure
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} -R ${WRKSRC}/www/* ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manual.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
