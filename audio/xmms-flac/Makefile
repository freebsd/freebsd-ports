# New ports collection makefile for:	xmms-flac
# Date created:		2003-06-10
# Whom:			Christian Weisgerber <naddy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xmms-flac
PORTVERSION=	1.1.2
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:sf/} \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	flac/:sf naddy/:local
DISTNAME=	flac-${PORTVERSION}
DISTFILES=	${EXTRACT_ONLY}:sf flac-alloc.h:local
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	naddy@FreeBSD.org
COMMENT=	XMMS input plugin for playing FLAC files

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		FLAC.7:${PORTSDIR}/audio/flac

USE_AUTOTOOLS=	libtool:15
CONFIGURE_ARGS=	--with-libiconv-prefix="${LOCALBASE}" \
		--with-ogg="${LOCALBASE}" \
		--with-xmms-prefix="${X11BASE}"
MAKE_ARGS=	LIBTOOL="${LIBTOOL} --tag=disable-static"
MAKE_ENV=	MAKEOBJDIR=/nonexistent		# ignore ${WRKSRC}/obj
MAKEFILE=	${FILESDIR}/Makefile

post-extract:
	@${CP} ${DISTDIR}/flac-alloc.h ${WRKSRC}/include/share/alloc.h

# XXX
post-install:
	${RM} ${PREFIX}/lib/xmms/Input/libxmms-flac.la

.include <bsd.port.mk>
