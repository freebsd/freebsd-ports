# New ports collection makefile for:    irb
# Date created:         19 April 1999
# Whom:                 Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	irb
PORTVERSION=	0.6.1
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.netlab.co.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/contrib/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/contrib/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/contrib/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/contrib/ \
		ftp://mirror.nucba.ac.jp/mirror/ruby/contrib/
EXTRACT_SUFX=	.tgz

MAINTAINER=	yasuf@big.or.jp

RUN_DEPENDS=	ruby:${PORTSDIR}/lang/ruby

WRKSRC=		${WRKDIR}/irb
PLIST_SUB+=	RUBY_VER="${RUBY_VER}"

RUBY=		${LOCALBASE}/bin/ruby
RUBY_VER=	1.4

post-patch:
	${RM} -f ${WRKSRC}/instirb.rb

do-build:
	( cd ${WRKSRC}; \
	  ${MV} irb.rb irb.tmpl; \
	  ${SED} -e '1s,^#!.*$$,#!${RUBY},' irb.tmpl > irb )

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/irb ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/ruby/${RUBY_VER}/irb
	${INSTALL_DATA} ${WRKSRC}/*.rb ${PREFIX}/lib/ruby/${RUBY_VER}/irb
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/ruby/irb
	${INSTALL_DATA} ${WRKSRC}/README* ${PREFIX}/share/doc/ruby/irb
.endif

.include <bsd.port.mk>
