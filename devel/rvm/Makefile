PORTNAME=	rvm
DISTVERSION=	1.20
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		http://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.coda.cs.cmu.edu/pub/rvm/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Persistent VM library
WWW=		http://www.coda.cs.cmu.edu/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	liblwp.so:devel/lwp

USES=		libtool pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
