# New ports collection makefile for:    ruby
# Version required:     1.0-971225
# Date created:         04 September 1997
# Whom:                 Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $Id: Makefile,v 1.4 1997/12/01 08:09:37 vanilla Exp $
#

DISTNAME=	ruby-1.0-971225
PKGNAME=	ruby-1.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/

MAINTAINER=	usagi@ruby.club.or.jp

GNU_CONFIGURE=	yes
MAN1=		ruby.1

test:
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
