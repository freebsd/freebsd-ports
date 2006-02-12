# Ports collection makefile for:	git
# Date created:				7 Feb 2006
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	git
PORTVERSION=	1.1.6
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.kernel.org/pub/software/scm/git/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	Distributed source code management tool

BUILD_DEPENDS=	curl:${PORTSDIR}/ftp/curl
RUN_DEPENDS=	curl:${PORTSDIR}/ftp/curl \
		wish8.4:${PORTSDIR}/x11-toolkits/tk84
LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2

USE_PERL5=	yes
USE_PYTHON=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
CFLAGS+=	-I${LOCALBASE}/include
MAKE_ENV+=	CURLDIR=${LOCALBASE} \
		NEEDS_LIBICONV=yes \
		LDFLAGS="-L${LOCALBASE}/lib" \
		PYTHON_PATH=${LOCALBASE}/bin/python
MAKE_ARGS+=	prefix="${PREFIX}"

.include <bsd.port.mk>
