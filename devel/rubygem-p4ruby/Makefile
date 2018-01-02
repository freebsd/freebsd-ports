#	$FreeBSD$

PORTNAME=	p4ruby
PORTVERSION=	2017.1.1599185
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	brd@FreeBSD.org
COMMENT=	Ruby bindings for the Perforce API

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS+=	${LOCALBASE}/lib/perforce/libclient.a:devel/p4api
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_RUBY=	yes
USES=		gem

CONFIGURE_ARGS=	--with-p4api-dir=${LOCALBASE} --with-p4api-lib=${LOCALBASE}/lib/perforce

.include	<bsd.port.mk>
