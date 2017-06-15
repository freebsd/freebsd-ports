# $FreeBSD$

PORTNAME=	rice
PORTVERSION=	2.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	C++ interface to Rubys C API

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USE_RUBY=	yes
USES=		gem
USE_AUTOTOOLS=	aclocal autoconf
INSTDIR=	${PREFIX}/${GEM_LIB_DIR}

# Fixup path in mkmf-rice.rb so things that build using it can find -lrice.
post-install:
	${REINPLACE_CMD} -e 's,${STAGEDIR}${INSTDIR},${INSTDIR},g' \
		${STAGEDIR}${INSTDIR}/ruby/lib/mkmf-rice.rb

.include <bsd.port.mk>
