# New ports collection makefile for:	flac
# Date created:		Mar 18, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	flac
PORTVERSION=	1.0.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	naddy@FreeBSD.org

LIB_DEPENDS=	ogg.3:${PORTSDIR}/audio/libogg

.if defined(WITH_XMMS)
BUILD_DEPENDS+=	xmms-config:${PORTSDIR}/audio/xmms
LIB_DEPENDS+=	xmms.3:${PORTSDIR}/audio/xmms
PLIST_SUB=	XMMS=""
.else
CONFIGURE_ENV+=	XMMS_CONFIG=/usr/bin/false	# must be absolute path
PLIST_SUB=	XMMS="@comment "
.endif

.if ${MACHINE_ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+= --enable-sse --enable-3dnow
.endif

GNU_CONFIGURE=	yes
CONFIGURE_TARGET= --target=${MACHINE_ARCH}-unknown-freebsd${OSREL}
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ENV=	INCLUDES="-I${WRKSRC}/include"

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

INSTALLS_SHLIB=	yes
MAN1=		flac.1

pre-build:
	@${RM} -r ${WRKSRC}/obj

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/flac
	cd ${WRKSRC}/doc; ${INSTALL_DATA} *.html ${PREFIX}/share/doc/flac
	${MKDIR} ${PREFIX}/share/doc/flac/images
	cd ${WRKSRC}/doc/images; \
	    ${INSTALL_DATA} *.gif *.jpg ${PREFIX}/share/doc/flac/images
.endif

.include <bsd.port.mk>
