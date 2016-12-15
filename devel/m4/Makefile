# Created by: mr
# $FreeBSD$

PORTNAME=	m4
PORTVERSION=	1.4.17
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	GNU m4

USES=		makeinfo tar:bzip2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"

INFO=	m4

EXAMPLESDIR=	share/examples/gm4

OPTIONS_DEFINE=			LIBSIGSEGV EXAMPLES
LIBSIGSEGV_DESC=		Use alternative page fault handler (GNU libsigsegv)
LIBSIGSEGV_LIB_DEPENDS=		libsigsegv.so:devel/libsigsegv
LIBSIGSEGV_CONFIGURE_ON=	--with-libsigsegv-prefix=${LOCALBASE}
LIBSIGSEGV_CONFIGURE_OFF=	--without-libsigsegv-prefix

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 \
		${STAGEDIR}${PREFIX}/${EXAMPLESDIR}

.include <bsd.port.mk>
