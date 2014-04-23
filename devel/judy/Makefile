# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Judy
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose dynamic array

LICENSE=	LGPL21

USES=		gmake libtool:keepla
GNU_CONFIGURE=	yes
USE_LDCONFIG=	YES
MAKE_JOBS_UNSAFE=	yes

WRKSRC=	${WRKDIR}/${PORTNAME:L}-${PORTVERSION}

PORTDOCS=	COPYRIGHT README *.htm

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-32-bit
.elif ${ARCH} == "amd64" || ${ARCH} == "ia64" || ${ARCH} == "sparc64" || ${ARCH} == "alpha"
CONFIGURE_ARGS+=	--enable-64-bit
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S!^!${WRKSRC}/doc/ext/!} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
