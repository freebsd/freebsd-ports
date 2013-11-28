# Created by: Vladimir Kondratiev <wulf@mail.mipt.ru>
# $FreeBSD$

PORTNAME=	debugger
PORTVERSION=	1.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	wulf@cicgroup.ru
COMMENT=	Fast implementation of the standard Ruby debugger

LICENSE=	BSD

FETCH_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/${RUBY_PORT}:patch
RUN_DEPENDS=	rubygem-columnize>=0.3.1:${PORTSDIR}/devel/rubygem-columnize \
		rubygem-debugger-linecache>=1.2.0:${PORTSDIR}/devel/rubygem-debugger-linecache

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rdebug man/man1/rdebug.1.gz

CONFIGURE_ARGS=	--with-ruby-include=${WRKDIR}/ruby

post-extract:
	@${LN} -sf `cd ${PORTSDIR}/${RUBY_PORT}; make -V WRKSRC` ${WRKDIR}/ruby

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/rdebug.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
