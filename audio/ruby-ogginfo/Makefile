# New ports collection makefile for:	Ruby/ogginfo
# Date created:		29 June 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ogginfo
PORTVERSION=	0.1
CATEGORIES=	audio ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}.rb
DIST_SUBDIR=	ruby/ogginfo-0.1
EXTRACT_ONLY=	# none

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A Ruby library to access to information on ogg files

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv

NO_BUILD=	yes

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}/ogginfo.rb

do-install:
	${INSTALL_DATA} ${WRKDIR}/ogginfo.rb ${RUBY_SITELIBDIR}/

.include <bsd.port.mk>
