# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	ruby-magic
PORTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	File Magic in ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-mini_portile2-25>=2.5.0<2.6:devel/rubygem-mini_portile2-25

USES=		gem
USE_RUBY=	yes
CONFIGURE_ARGS+=	--use-system-libraries

post-install:
	@${ECHO_CMD} "@dir ${GEM_LIB_DIR}/ports" >> ${TMPPLIST}

.include <bsd.port.mk>
