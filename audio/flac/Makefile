# ex:ts=8
# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	1.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	naddy@FreeBSD.org

.if defined(WITH_XMMS)
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS+=	xmms.2:${PORTSDIR}/audio/xmms
PLIST_SUB=	XMMS=""
.else
PLIST_SUB=	XMMS="@comment "
.endif

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

USE_AUTOMAKE_VER=14
AUTOMAKE_ARGS=	--include-deps
USE_LIBTOOL=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

INSTALLS_SHLIB=	yes
MAN1=		flac.1

post-extract:
	@${RM} -r ${WRKSRC}/obj

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/flac
	${MKDIR} ${PREFIX}/share/doc/flac/images
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${PREFIX}/share/doc/flac
.for file in 1x1.gif cafebug.gif logo.jpg
	${INSTALL_DATA} ${WRKSRC}/doc/images/${file} ${PREFIX}/share/doc/flac/images
.endfor
.endif

.include <bsd.port.mk>
