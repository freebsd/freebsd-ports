# New ports collection makefile for:	yudit
# Date created:		October 3, 1998
# Whom:			rch@richard.eu.org
#
# $FreeBSD$
#

PORTNAME=	yudit
PORTVERSION=	2.7.6
CATEGORIES=	editors converters print
MASTER_SITES=	http://yudit.org/download/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= apps/editors/X
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	jkoshy@freebsd.org
COMMENT=	Multi-lingual unicode text editor with TTF support

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext-old

USE_BZIP2=	YES
USE_XLIB=	YES
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include" \
		LDFLAGS="-L${X11BASE}/lib" \
		LC_ALL=
GNU_CONFIGURE=	YES
MAKE_ENV=	LC_ALL=
MAN1=		mytool.1 uniconv.1 uniprint.1
USE_GMAKE=	YES

.include <bsd.port.mk>
