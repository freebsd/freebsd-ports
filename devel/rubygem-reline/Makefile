# $FreeBSD$

PORTNAME=	reline
PORTVERSION=	0.2.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	yasu@utahime.org
COMMENT=	Alternative GNU Readline or Editline implementation by pure Ruby

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/COPYING

RUN_DEPENDS=	rubygem-io-console>=0.5<1:devel/rubygem-io-console

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
