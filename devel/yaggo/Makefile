PORTNAME=	yaggo
PORTVERSION=	1.5.11
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Generate command line parser using getopt_long
WWW=		https://github.com/gmarcais/yaggo

LICENSE=	GPLv3

USES=		ruby
USE_GITHUB=	yes

GH_ACCOUNT=	gmarcais

NO_ARCH=	yes

PLIST_FILES=	bin/yaggo share/man/man1/yaggo.1.gz share/doc/yaggo/README.md

pre-configure:
	@${REINPLACE_CMD} -e 's|/usr/bin/env ruby|${PREFIX}/bin/ruby|g' \
		${WRKSRC}/bin/create_yaggo_one_file

.include <bsd.port.mk>
