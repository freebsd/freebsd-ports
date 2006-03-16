# ex:ts=8
# New ports collection makefile for:	aleph
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	afnix
PORTVERSION=	1.2.1
CATEGORIES=	lang
MASTER_SITES=	http://www.afnix.org/ftp/%SUBDIR%/ \
		ftp://ftp.stack.nl/pub/users/johans/afnix/
MASTER_SITE_SUBDIR=	${PORTNAME}-${PORTVERSION:S,.,-,g}
DISTNAME=	${PORTNAME}-src-${PORTVERSION:S,.,-,g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	johans@stack.nl
COMMENT=	A multi-threaded functional programming language

USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	cnf/bin/afnix-setup
CONFIGURE_ARGS=		-o --prefix "${PREFIX}" --compiler freebsd
MAKE_ENV=	CXX="${CXX}" PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

PLIST_SUB=	PORTVER=${PORTVERSION:R}

MAN1=	axc.1 axd.1 axi.1 axl.1 axs.1

.include <bsd.port.pre.mk>

post-extract:
	@cd ${WRKSRC}/cnf/mak && ${CP} -f afnix-gcc-3.mak afnix-freebsd.mak

post-patch:
	@${REINPLACE_CMD} -e 's|$$(CP)|$$(BSD_INSTALL_PROGRAM)|' \
		${WRKSRC}/src/*/*/exe/Makefile

.include <bsd.port.post.mk>
