# New ports collection makefile for:	Gauche-kakasi
# Date created:				12 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	0.0
CATEGORIES=	japanese textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gauche
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KAKASI binding for Gauche

BROKEN=		Broken dependency

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	kakasi.3:${PORTSDIR}/japanese/kakasi

WRKSRC=		${WRKDIR}/Gauche-${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kakasi=${PREFIX}
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PLIST_SUB=	VERSION="`gauche-config -V`" \
		TARGET="${CONFIGURE_TARGET}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.eucjp ${DOCSDIR}
.endif

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}gauche-

.include <bsd.port.post.mk>
