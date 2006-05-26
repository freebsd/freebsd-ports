# New ports collection makefile for:    sipp
# Date created:         15 Jun 2004
# Whom:                 jesper@jdn.dk
#
# $FreeBSD$
#

PORTNAME=	sipp
PORTVERSION=	1.1.r5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	sipp
DISTNAME=	${PORTNAME}-1.1rc5

MAINTAINER=	tut@nhamon.com.ua
COMMENT=	SIP testing tool

WRKSRC=		${WRKDIR}/${PORTNAME}.cumulus.2006-03-20

PLIST_FILES=	bin/sipp
MAN1=		sipp.1

MAKE_ENV+=	CPP="${CXX}" CPPFLAGS="${CXXFLAGS}" CCLINK="${CXX}"

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile - patch needed by someone who can test it
.endif

.if !defined(WITHOUT_DIGEST_AUTH)
ALL_TARGET=ossl
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${FILESDIR}/sipp.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
