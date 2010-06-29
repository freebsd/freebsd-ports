# New ports collection makefile for:	MIT-Scheme
# Date created:		Mar 26 1995
# Whom:			jmacd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mit-scheme
PORTVERSION=	9.0.1
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	mit-scheme/stable.pkg/${PORTVERSION}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	MIT Scheme: includes runtime, compiler, and edwin binaries

ONLY_FOR_ARCHS=	i386
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/mit-scheme-${PORTVERSION}/src/

.include <bsd.port.pre.mk>

MIT_SCHEME_ARCH=i386

DISTNAME=	${PORTNAME}-${PORTVERSION}-${MIT_SCHEME_ARCH}
PLIST_SUB+=	MIT_SCHEME_ARCH=${MIT_SCHEME_ARCH}

MAN1=	scheme.1

post-build:
	@${FIND} ${WRKDIR} -type d -empty | ${XARGS} ${RMDIR}

do-build:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src/microcode && ${GMAKE}

do-install:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src && ${GMAKE} install
	@${INSTALL_MAN} ${WRKDIR}/mit-scheme-${PORTVERSION}/doc/scheme.1 ${MAN1PREFIX}/man/man1/
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/lib/mit-scheme-i386

.include <bsd.port.post.mk>
