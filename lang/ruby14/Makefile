# New ports collection makefile for:    ruby
# Version required:     1.0-971225
# Date created:         04 September 1997
# Whom:                 Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $Id: Makefile,v 1.7 1998/09/09 01:22:59 jkoshy Exp $
#

DISTNAME=	ruby-1.0-971225
PKGNAME=	ruby-1.0
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/1.0/

MAINTAINER=	usagi@clave.gr.jp

GNU_CONFIGURE=	yes
MAN1=		ruby.1

test:
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
