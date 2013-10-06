# Created by: mr
# $FreeBSD$

PORTNAME=	m4
PORTVERSION=	1.4.17
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"

INFO=	m4

EXAMPLESDIR=	share/examples/gm4

OPTIONS_DEFINE=		LIBSIGSEGV
LIBSIGSEGV_DESC=	Use libsigsegv for better diagnostics

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 \
		${STAGEDIR}${PREFIX}/${EXAMPLESDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MLIBSIGSEGV}
LIB_DEPENDS+=		libsigsegv.so:${PORTSDIR}/devel/libsigsegv
CONFIGURE_ARGS+=	--with-libsigsegv-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libsigsegv-prefix
.endif

.include <bsd.port.mk>
