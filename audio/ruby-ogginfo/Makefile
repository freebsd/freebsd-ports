# New ports collection makefile for:	Ruby/ogginfo
# Date created:		29 June 2004
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ogginfo
PORTVERSION=	0.1
CATEGORIES=	audio ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/821/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	${PORTNAME}.rb-${PORTVERSION}	# any file name is ok
DIST_SUBDIR=	ruby
EXTRACT_ONLY=	# none

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby library to access to information on ogg files

USE_RUBY=	yes
USE_RUBY_FEATURES=	iconv

NO_BUILD=	yes

post-extract:
	${CP} ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} ${WRKDIR}/ogginfo.rb

do-install:
	${INSTALL_DATA} ${WRKDIR}/ogginfo.rb ${RUBY_SITELIBDIR}/

.include <bsd.port.mk>
