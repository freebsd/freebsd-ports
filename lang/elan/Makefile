# Created by: Ed Schouten <ed@fxq.nl>
# $FreeBSD$

PORTNAME=	elan
PORTVERSION=	1.7c
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.cs.ru.nl/pub/vb/elan/
DISTNAME=	${PORTNAME}-1.7

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Compiler for the Elan Programming Environment

LIB_DEPENDS=	libdcg.so:${PORTSDIR}/devel/mimir

WRKSRC=		${WRKDIR}/${DISTNAME}

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/liberts.so.1.0.7
.if !defined (NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/compiler/comp.ps \
		${STAGEDIR}${DOCSDIR}/elan-compiler.ps
	${INSTALL_DATA} ${WRKSRC}/manuals/language/elan.ps \
		${STAGEDIR}${DOCSDIR}/elan-language.ps
.endif

.include <bsd.port.post.mk>
