PORTNAME=	p4ruby
PORTVERSION=	2017.1.1599185
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby bindings for the Perforce API
WWW=		http://www.perforce.com/perforce/loadsupp.html

LICENSE=	BSD2CLAUSE

BUILD_DEPENDS=	${LOCALBASE}/lib/perforce/libclient.a:devel/p4api \
		rubygem-net-ftp>0:ftp/rubygem-net-ftp
RUN_DEPENDS=	rubygem-net-ftp>0:ftp/rubygem-net-ftp

USES=		gem

CONFIGURE_ARGS=	--with-p4api-dir=${LOCALBASE} --with-p4api-lib=${LOCALBASE}/lib/perforce

.include	<bsd.port.mk>
