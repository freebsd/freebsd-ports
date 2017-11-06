# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	Judy
PORTVERSION=	1.0.5
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose dynamic array

LICENSE=	LGPL21

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/${PORTNAME:tl}-${PORTVERSION}

PORTDOCS=	COPYRIGHT README *.htm

.include <bsd.port.pre.mk>

.if ${ARCH} == armv6 || ${ARCH} == armv7 || ${ARCH} == i386 || ${ARCH} == mips || ${ARCH} == powerpc
CONFIGURE_ARGS+=	--enable-32-bit
.else
CONFIGURE_ARGS+=	--enable-64-bit
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S!^!${WRKSRC}/doc/ext/!} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
