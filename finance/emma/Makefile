# New ports collection makefile for:	emma
# Date created:				7 November 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	emma
PORTVERSION=	0.8.2
PORTREVISION=	1
CATEGORIES=	finance gnome python
MASTER_SITES=	http://rainbow.mimuw.edu.pl/~la181249/emma/packages/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A personal finance manager for Gnome

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/mx/DateTime/DateTime.py:${PORTSDIR}/lang/py-mx-base

USE_X_PREFIX=	yes
USE_PYTHON=	yes
USE_GNOME=	gnomehack gnomelibs gnomeprefix
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

pre-configure:
	@${RM} -f ${WRKSRC}/config.cache

.include <bsd.port.mk>
