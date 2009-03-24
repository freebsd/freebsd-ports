# New ports collection makefile for:	RakNet
# Date created:				11 October 2005
# Whom:					Andrew Baznikin <dikiy@scn.ru>
#
# $FreeBSD$
#

PORTNAME=	raknet
PORTVERSION=	3.10
PORTREVISION=	1
CATEGORIES=	devel net
MASTER_SITES=	SF/raknetjenkinsso
DISTNAME=	${PORTNAME}-3.1

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Networking API that provides reliable UDP primarily for online games

USE_LDCONFIG=	yes
USE_FORTRAN=	yes
USE_AUTOTOOLS=	libltdl:15 libtool:15 autoconf:262
USE_GCC=	3.4
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(cpp|h)

OPTIONS=	RAKVOICE "Build Rakvoice" off \
		AUTOPATCHER "Build autopatcher" off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700000
BROKEN=		Does not compile
.endif

.if defined(WITH_RAKVOICE)
CONFIGURE_ARGS+=	--enable-rakvoice
BUILD_DEPENDS+=	${LOCALBASE}/lib/libspeex.so:${PORTSDIR}/audio/speex
RUN_DEPENDS+=	${LOCALBASE}/lib/libspeex.so:${PORTSDIR}/audio/speex
PLIST_SUB+=	PL_RAKVOICE=""
.else
CONFIGURE_ARGS+=	--disable-rakvoice
PLIST_SUB+=	PL_RAKVOICE="@comment "
.endif

.if defined(WITH_AUTOPATCHER)
CONFIGURE_ARGS+=	--enable-autopatcher
USE_PGSQL=	yes
PLIST_SUB+=	PL_AUTOPATCHER=""
.else
CONFIGURE_ARGS+=	--disable-autopatcher
PLIST_SUB+=	PL_AUTOPATCHER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|2.61|2.62|g' ${WRKSRC}/aclocal.m4

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/Help
	(cd ${WRKSRC}/Help/ && ${COPYTREE_SHARE} \* ${DOCSDIR}/Help)
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${DOCSDIR}/
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/Samples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

.include <bsd.port.post.mk>
