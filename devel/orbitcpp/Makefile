# New ports collection makefile for:	orbitcpp
# Date created:		30 August 2001
# Whom:	      	  Thomas Hentschel <thomas at hentschel dot net>
#
# $FreeBSD$
#

PORTNAME=	orbitcpp
PORTVERSION=	0.30.4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Does not build"

LIB_DEPENDS=	ORBit.2:${PORTSDIR}/devel/ORBit

USE_GLIB=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

INSTALL_CMD=	/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${PERL} -pi -e \
		's|\@INSTALL\@|${INSTALL_CMD}|g'

.include <bsd.port.mk>
