# New ports collection makefile for:	MIT-Scheme
# Date created:		Mar 26 1995
# Whom:			jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mit-scheme
PORTVERSION=	7.7.1
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp.swiss.ai.mit.edu/pub/mit-scheme/7.7/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION} OLD/${PORTVERSION}
DISTNAME=	scheme-${PORTVERSION}-src-ucode
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		scheme-${PORTVERSION}-ix86-freebsd.tar.gz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	MIT Scheme: includes runtime, compiler, and edwin binaries

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
WRKSRC=		${WRKDIR}/scheme-${PORTVERSION}/src/microcode
ALL_TARGET=	default-target

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scheme ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bchscheme ${PREFIX}/bin
	@cd ${WRKDIR}/lib && ${PAX} -rw mit-scheme ${PREFIX}/lib
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mit-scheme

.include <bsd.port.mk>
