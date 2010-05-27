# New ports collection makefile for:	m4
# Date created:		25 October 1994
# Whom:			mr
#
# $FreeBSD$
#

PORTNAME=	m4
PORTVERSION=	1.4.14
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	m4

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU m4

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--program-prefix=g
CONFIGURE_ENV=	MAKEINFO="makeinfo --no-split"

.if defined(WITH_CHANGEWORD)
CONFIGURE_ARGS+=	--enable-changeword
.endif

INFO=	m4
MAN1=	gm4.1

EXAMPLESDIR=	share/examples/gm4

OPTIONS=	LIBSIGSEGV "Use libsigsegv for better diagnostics" Off

post-install:
	@${MKDIR} ${PREFIX}/${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.m4 ${PREFIX}/${EXAMPLESDIR}

.include <bsd.port.pre.mk>

.if defined(WITH_LIBSIGSEGV)
LIB_DEPENDS+=	sigsegv:${PORTSDIR}/devel/libsigsegv
CONFIGURE_ARGS+=	--with-libsigsegv-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=	--without-libsigsegv-prefix
.endif

.include <bsd.port.post.mk>
