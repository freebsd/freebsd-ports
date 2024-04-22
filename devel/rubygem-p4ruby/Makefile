PORTNAME=	p4ruby
PORTVERSION=	2023.1.2544327
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Ruby bindings for the Perforce API
WWW=		https://github.com/perforce/p4ruby

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/perforce/libclient.a:devel/p4api \
		rubygem-net-ftp>0:ftp/rubygem-net-ftp
RUN_DEPENDS=	rubygem-net-ftp>0:ftp/rubygem-net-ftp

USES=		gem

CONFIGURE_ARGS=	--with-p4api-dir=${LOCALBASE} --with-p4api-lib=${LOCALBASE}/lib/perforce

post-patch:
	@${REINPLACE_CMD} 's|#include \"p4/|#include \"perforce/|g; s|#include <p4/|#include <perforce/|g' \
		${WRKSRC}/ext/P4/clientprogressruby.cpp \
		${WRKSRC}/ext/P4/clientuserruby.cpp \
		${WRKSRC}/ext/P4/p4clientapi.cpp

.include	<bsd.port.mk>
