# New ports collection makefile for:   libical
# Date created:        4 November 2002
# Whom:                Joe Kelsey
#
# $FreeBSD$
#

PORTNAME=	libical
PORTVERSION=	0.23
CATEGORIES=	devel
MASTER_SITES=	http://softwarestudio.org/download/

MAINTAINER=	joe@zircon.seattle.wa.us

BUILD_DEPENDS=	perl:${PORTSDIR}/lang/perl5

USE_REINPLACE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_PYTHON)
CONFIGURE_ARGS=	--enable-python-bindings=yes
USE_PYTHON=	yes
PLIST_SUB+=     PYTHON:=""
.else
CONFIGURE_ARGS=	--enable-python-bindings=no
PLIST_SUB+=     PYTHON:="@comment "
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc\.h>|<stdlib.h>|g'

.include <bsd.port.mk>
