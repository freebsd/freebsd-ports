# New ports collection makefile for:	MIT-Scheme
# Date created:		Mar 26 1995
# Whom:			jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mit-scheme
PORTVERSION=	7.7.1
PORTREVISION=	4
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	mit-scheme/stable.pkg/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-ucode
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-${PORTVERSION}-ix86-freebsd.tar.gz

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	MIT Scheme: includes runtime, compiler, and edwin binaries

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/scheme-${PORTVERSION}/src/microcode
ALL_TARGET=	default-target

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/scheme ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bchscheme ${PREFIX}/bin
	@cd ${WRKDIR}/lib && ${PAX} -rw mit-scheme ${PREFIX}/lib
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mit-scheme

.include <bsd.port.mk>
