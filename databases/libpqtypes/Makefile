PORTNAME=	libpqtypes
PORTVERSION=	1.5.1
PORTREVISION=	3
CATEGORIES=	databases
MASTER_SITES=	http://pgfoundry.org/frs/download.php/3484/

MAINTAINER=	dg@fastmail.co.uk
COMMENT=	Extension to libpq parameter handling
WWW=		http://libpqtypes.esilo.com/

LICENSE=	BSD2CLAUSE

USES=		gmake libtool pgsql autoreconf

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
