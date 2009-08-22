# New ports collection makefile for:	TilEm
# Date created:				5 Sep 2006
# Whom:					Alexey Dokuchaev <danfe@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	tilem
PORTVERSION=	0.973
PORTREVISION=	4
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-devel/${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An emulator for the Z80 series of Texas Instruments calculators

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk20

OPTIONS=	TICABLES "Use ticables2 library for external linking" off

.include <bsd.port.pre.mk>

.if defined(WITH_TICABLES)
LIB_DEPENDS+=	ticables2.1:${PORTSDIR}/comms/libticables2
.else
CONFIGURE_ARGS+=	--without-ticables
.endif

post-extract:
# Set more sane permissions for main executable
	@${REINPLACE_CMD} -e 's,711,555,' \
		${WRKSRC}/src/tilem/Makefile.in
# Honor CFLAGS
	@${REINPLACE_CMD} -e 's,CPPFLAGS) -O.,CPPFLAGS),' \
		${WRKSRC}/src/tilem/Makefile.in
	@${REINPLACE_CMD} -e 's,-Wall,${CFLAGS},' \
		${WRKSRC}/src/utils/Makefile.in
# Remove conflicting prototype
	@${REINPLACE_CMD} '5,13d' ${WRKSRC}/src/tilem/core/dep/link.h

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/neosign ${WRKSRC}/bin/tcc \
		${PREFIX}/bin

.include <bsd.port.post.mk>
