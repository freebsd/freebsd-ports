# New ports collection makefile for:	FreeBASE
# Date created:		16 June 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	freebase
PORTVERSION=	0.7.0
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/1208/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	freeride-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT=	Plugin subsystem of FreeRIDE

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_RUBY=	yes
NO_BUILD=	yes

do-install:
	cd ${WRKSRC}; ${RUBY} bin/install.rb

.include <bsd.port.mk>
