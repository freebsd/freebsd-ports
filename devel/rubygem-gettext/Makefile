# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	gettext
PORTVERSION=	3.2.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby implementation of the gettext library

LICENSE=	RUBY LGPL3
LICENSE_COMB=	dual

RUN_DEPENDS=	rubygem-locale>=2.0.5:devel/rubygem-locale \
		rubygem-text>=1.3.0:textproc/rubygem-text

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/rmsgcat bin/rmsgfmt bin/rmsginit bin/rmsgmerge bin/rxgettext

SHEBANG_FILES=	samples/*.rb samples/cgi/*.rb

.include <bsd.port.mk>
