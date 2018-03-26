# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	multisync
PORTVERSION=	0.82
PORTREVISION=	14
CATEGORIES=	deskutils
MASTER_SITES=	SF/multisync/OldFiles
DISTNAME=	multisync-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Synchronize calendars, addressbooks, and other PIM data

USES=		autoreconf gmake libtool pathfix pkgconfig tar:bzip2
USE_GNOME=	gnomeprefix libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${FIND} ${WRKDIR} -type l -delete

.include <bsd.port.mk>
