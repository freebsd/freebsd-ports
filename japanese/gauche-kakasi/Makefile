# New ports collection makefile for:	Gauche-kakasi
# Date created:				12 April 2003
# Whom:					Kimura Fuyuki <fuyuki@hadaly.org>
#
# $FreeBSD$
#

PORTNAME=	kakasi
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	japanese textproc scheme
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gauche
DISTNAME=	Gauche-${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KAKASI binding for Gauche

BUILD_DEPENDS=	gosh:${PORTSDIR}/lang/gauche
RUN_DEPENDS=	${BUILD_DEPENDS}
LIB_DEPENDS=	kakasi.3:${PORTSDIR}/japanese/kakasi

BROKEN=		deinstalls file not installed by this port

.include <bsd.port.pre.mk>

.if ${ARCH}==amd64
BROKEN=does not compile on amd64
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-kakasi=${PREFIX}
DOCSDIR=	${PREFIX}/share/doc/gauche/${PORTNAME}
PLIST_SUB=	VERSION="`gauche-config -V`" \
		TARGET="${CONFIGURE_TARGET}"
PORTDOCS=	README.eucjp

post-patch:
	${REINPLACE_CMD} -e "s/\(@LDFLAGS@\) \(@KAKASI_LIBDIR@\)/\2 \1/" \
		${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}gauche-

test:
	cd ${WRKSRC}; ${MAKE} check

.include <bsd.port.post.mk>
