# New ports collection makefile for:	mo.rb
# Date created:		24 April 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	mo
PORTVERSION=	0.0.2
CATEGORIES=	devel ruby
MASTER_SITES=	http://homepage1.nifty.com/susho/software/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}.rb
EXTRACT_SUFX=	# none
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org

USE_RUBY=	yes
RUBY_NO_BUILD_DEPENDS=	yes

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# none
EXTRACT_AFTER_ARGS=	${WRKDIR}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME} ${RUBY_SITELIBDIR}/mo.rb

.include <bsd.port.mk>
