# New ports collection makefile for:    ruby
# Version required:     1.2.5
# Date created:         04 September 1997
# Whom:                 Eiji-usagi-MATSUmoto <usagi@ruby.club.or.jp>
#
# $FreeBSD$
#

DISTNAME=	ruby-1.2.5
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
PLIST_SUB+=	RUBY_ARCH="${RUBY_ARCH}"

RUBY_ARCH=	${ARCH}-freebsd${OSREL}

# lib/mkmf.rb requires that the name of the install program will be
# specified with absolute path.
INSTALL=	/usr/bin/install

BRANCH_NAME=	1.2

post-patch:
	${RM} -f ${WRKSRC}/ext/tcltklib/MANIFEST
	${RM} -f ${WRKSRC}/ext/tk/MANIFEST

post-install:
	strip ${PREFIX}/bin/ruby
	${MKDIR} ${PREFIX}/share/examples/ruby
	${INSTALL_DATA} ${WRKSRC}/sample/* ${PREFIX}/share/examples/ruby

test:
	@(cd ${WRKSRC}; make test)

.include <bsd.port.mk>
