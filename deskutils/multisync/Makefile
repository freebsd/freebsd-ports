# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME?=	multisync
PORTVERSION=	0.82
PORTREVISION=	12
CATEGORIES=	deskutils
MASTER_SITES=	SF/multisync/OldFiles
DISTNAME=	multisync-${PORTVERSION}

MAINTAINER?=	ports@FreeBSD.org
COMMENT?=	Synchronize calendars, addressbooks, and other PIM data

USE_GNOME=	gnomeprefix libgnomeui
USES=		gmake libtool pathfix pkgconfig tar:bzip2
USE_AUTOTOOLS=	libtoolize aclocal autoconf autoheader automake
AUTOMAKE_ARGS=	-a -c -f
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

pre-configure:
	@${FIND} ${WRKDIR} -type l -delete

.include <bsd.port.mk>
