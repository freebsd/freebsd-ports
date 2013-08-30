# Created by: Martin Matuska <mm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nszlib
PORTVERSION=	1.1
PORTREVISION=	2
CATEGORIES=	archivers www
MASTER_SITES=	ftp://ftp.crystalballinc.com/pub/vlad/
MASTER_SITE_SUBDIR=	aolserver
PKGNAMEPREFIX=	aolserver-
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	aolserver

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Zlib library interface for AOLserver

LICENSE=	MPL GPLv1
LICENSE_COMB=	dual

AOLSERVERBASE?=	aolserver

BUILD_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver
RUN_DEPENDS+=	${LOCALBASE}/${AOLSERVERBASE}/bin/nsd:${PORTSDIR}/www/aolserver

USES=		gmake

MAKE_ARGS=	AOLSERVER="${LOCALBASE}/${AOLSERVERBASE}" \
		DLLLIBS="-lz" MODLIBS="-lz"

PLIST_FILES=	${AOLSERVERBASE}/bin/nszlib.so \
		${AOLSERVERBASE}/lib/libnszlib.a \
		${AOLSERVERBASE}/lib/libnszlib.so

PORTDOCS=	ChangeLog README example.tcl

.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -e 's/^MODLIBS  =/MODLIBS +=/g' \
		-e '/^OBJS     =.*/{n;s/.*/MODOBJS  = $$(OBJS)/g;G;}' \
		${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@ ${MKDIR} ${DOCSDIR}
.for FILE in ${PORTDOCS}
	@ ${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
