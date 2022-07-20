PORTNAME=	Judy
DISTVERSION=	1.0.5
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	General purpose dynamic array

LICENSE=	LGPL21

BROKEN_mips=		fails to compile: unrecognized command line option "-m32"
BROKEN_mips64=		fails to compile: unrecognized command line option "-m64"

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

WRKSRC=	${WRKDIR}/${PORTNAME:tl}-${DISTVERSION}

PORTDOCS=	COPYRIGHT README *.htm

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

.if ${ARCH:M*64*}
CONFIGURE_ARGS+=	--enable-64-bit
.else
CONFIGURE_ARGS+=	--enable-32-bit
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S!^!${WRKSRC}/doc/ext/!} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.post.mk>
