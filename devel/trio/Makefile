# Created by: ijliao
# $FreeBSD$

PORTNAME=	trio
PORTVERSION=	1.16
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/c${PORTNAME}/${PORTNAME}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	Fully matured and stable set of printf and string functions

LICENSE=	BSD2CLAUSE

USES=		uidfix

MAKEFILE=	${FILESDIR}/BSDmakefile

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${FIND} doc | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${STAGEDIR}${DOCSDIR}
.endif

do-test:
	${CC} -o ${WRKSRC}/regression ${WRKSRC}/regression.c \
		-L${WRKSRC} -ltrio -Wl,-rpath=${WRKSRC}
	${WRKSRC}/regression



.include <bsd.port.mk>
