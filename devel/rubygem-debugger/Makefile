# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	debugger
PORTVERSION=	1.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Fast implementation of the standard Ruby debugger

LICENSE=	BSD2CLAUSE

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch
RUN_DEPENDS=	rubygem-columnize>=0.3.1:${PORTSDIR}/devel/rubygem-columnize \
		rubygem-debugger-linecache>=1.2.0:${PORTSDIR}/devel/rubygem-debugger-linecache

BROKEN_RUBY21=	yes
BROKEN_RUBY22=	yes
DEPRECATED=	This port is for Ruby 1.9 only. Upstream stopped maintenance.
EXPIRATION_DATE=2015-10-31

CONFIGURE_ARGS=	--with-ruby-include=${WRKDIR}/ruby
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/rdebug man/man1/rdebug.1.gz

post-extract:
	@${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; make -V WRKSRC` ${WRKDIR}/ruby

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/rdebug.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
