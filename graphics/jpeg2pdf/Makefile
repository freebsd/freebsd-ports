# New ports collection makefile for:	jpeg2pdf
# Date created:		2005-01-22
# Whom:			<ports@c0decafe.net>
#
# $FreeBSD$
#

PORTNAME=	jpeg2pdf
PORTVERSION=	0.12
CATEGORIES=	graphics converters
MASTER_SITES=	http://koan.studentenweb.org/software/

MAINTAINER=	ports@c0decafe.net
COMMENT=	Converts a directory of JPEG (JPG) files to a PDF file

USE_BZIP2=	yes
USE_RUBY=	yes
USE_RUBY_SETUP=	yes
RUBY_SETUP=	install.rb
CONFIGURE_ARGS=	--prefix=${PREFIX}

pre-install:
	@${RM} ${WRKSRC}/bin/test.rb

.include <bsd.port.pre.mk>

.if ${RUBY_VER} == 1.9
BROKEN=	does not work with ruby 1.9
.endif

.include <bsd.port.post.mk>
