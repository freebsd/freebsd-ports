PORTNAME=	ruby-magic
PORTVERSION=	0.6.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	File Magic in ruby
WWW=		https://github.com/kwilczynski/ruby-magic

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mini_portile2>=2.8<3:devel/rubygem-mini_portile2

USES=		gem
CONFIGURE_ARGS+=	--use-system-libraries

post-install:
	${RMDIR} ${STAGEDIR}${PREFIX}/${GEM_LIB_DIR}/ports

.include <bsd.port.mk>
