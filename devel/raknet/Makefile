# New ports collection makefile for:	RakNet
# Date created:				11 October 2005
# Whom:					Andrew Baznikin <dikiy@scn.ru>
#
# $FreeBSD$
#

PORTNAME=	raknet
PORTVERSION=	3.5.2
PORTEPOCH=	1
CATEGORIES=	devel net
MASTER_SITES=	http://www.jenkinssoftware.com/raknet/downloads/ \
		SF
MASTER_SITE_SUBDIR=	raknetjenkinsso
DISTNAME=	RakNet-3.52

MAINTAINER=	ganael.laplanche@martymac.com
COMMENT=	Networking API that provides reliable UDP primarily for online games

USE_ZIP=	yes
NO_WRKSUBDIR=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 autoconf:262 automake:110 libtool:15
AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} \
	-I ${LOCALBASE}/share/aclocal \
	-I ${WRKDIR}/autotools/m4
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
				LDFLAGS="-L${LOCALBASE}/lib"

USE_DOS2UNIX=	yes
DOS2UNIX_REGEX=	.*\.(cpp|h)

OPTIONS=	RAKVOICE "Build Rakvoice" off \
			AUTOPATCHER "Build autopatcher" off

.include <bsd.port.pre.mk>

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
	@${MKDIR} ${WRKSRC}/autotools/build

pre-configure:
	@(cd ${WRKSRC}/ && \
		${LIBTOOLIZE} --force --copy --automake)

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
