# New ports collection makefile for:	irb
# Date created:		19 April 1999
# Whom:			Yasuhiro Fukuma <yasuf@big.or.jp>
#
# $FreeBSD$
#

PORTNAME=	irb
PORTVERSION=	0.6.1
CATEGORIES=	lang ruby
MASTER_SITES=	${MASTER_SITE_RUBY}
MASTER_SITE_SUBDIR=	contrib
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	yasuf@big.or.jp

RUBY_VER=	1.4

USE_RUBY=	yes

RUBY_SHEBANG_FILES=	${WRKSRC}/irb.rb

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	${RM} -f ${WRKSRC}/instirb.rb

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/irb.rb ${PREFIX}/bin/irb${_RUBY_SUFFIX}
	${LN} -fs irb${_RUBY_SUFFIX} ${PREFIX}/bin/irb
	${MKDIR} ${RUBY_LIBDIR}/irb
	${INSTALL_DATA} ${WRKSRC}/*.rb ${RUBY_LIBDIR}/irb
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_DOCDIR}/irb
	${INSTALL_DATA} ${WRKSRC}/README* ${RUBY_DOCDIR}/irb
.endif

.include <bsd.port.mk>
