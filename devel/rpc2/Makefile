# Created by: jaharkes
# $FreeBSD$

PORTNAME=	rpc2
PORTVERSION=	2.10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		http://ftp.wu-wien.ac.at/pub/systems/coda/src/ \
		ftp://ftp.coda.cs.cmu.edu/pub/rpc2/src/ \
		ftp://ftp.wu-wien.ac.at/pub/systems/coda/src/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interprocess communication library

LICENSE=	LGPL20

LIB_DEPENDS=	liblwp.so:devel/lwp

USES=		gmake libtool pathfix perl5 pkgconfig
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
