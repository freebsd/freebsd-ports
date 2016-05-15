# $FreeBSD$

PORTNAME=	rice
PORTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	A C++ interface to Rubys C API

USE_RUBY=	yes
USES=		gem
USE_AUTOTOOLS=	aclocal autoconf
INSTDIR=	${PREFIX}/${GEM_LIB_DIR}

# Fixup path in mkmf-rice.rb so things that build using it can find -lrice.
post-stage:
	${REINPLACE_CMD} -e 's,${STAGEDIR}${INSTDIR},${INSTDIR},g' \
		${STAGEDIR}${INSTDIR}/ruby/lib/mkmf-rice.rb

.include <bsd.port.mk>
