# New ports collection makefile for:    ruby
# Version required:     1.2.2
# Date created:         04 September 1997
# Whom:                 Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $Id: Makefile,v 1.8 1998/09/22 03:22:47 jkoshy Exp $
#

DISTNAME=	ruby-1.2.2
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/${BRANCH_NAME}/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/${BRANCH_NAME}/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/${BRANCH_NAME}/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/${BRANCH_NAME}/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/${BRANCH_NAME}/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/${BRANCH_NAME}/

MAINTAINER=	yasuf@big.or.jp

GNU_CONFIGURE=	yes
#USE_AUTOCONF=	yes
MAN1=		ruby.1

BRANCH_NAME=	1.2

post-install:
	strip ${PREFIX}/bin/ruby

test:
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
