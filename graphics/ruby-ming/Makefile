# New ports collection makefile for:	Ruby/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.2a
CATEGORIES=	graphics ruby
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	${SWIG}:${PORTSDIR}/devel/swig13 \
		${NONEXISTENT}:${PORTSDIR}/graphics/ming:patch
LIB_DEPENDS=	ming.3:${PORTSDIR}/graphics/ming

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

MD5_FILE=	${.CURDIR}/../ming/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/rb_ext
CONFIGURE_ARGS=	--with-ming-include="${LOCALBASE}/include/ming"
MAKE_ARGS=	SWIG="${SWIG}"
INSTALL_TARGET=	site-install

SWIG=		swig1.3

EXAMPLES=	../examples/rb/*.rb

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -s `cd ${PORTSDIR}/graphics/ming; ${MAKE} -V WRKDIR`/* ${WRKDIR}/

post-extract:
	${LN} -sf ../ming.i ${WRKSRC}/

pre-configure:
	cd ${WRKSRC}; \
	${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} depend SWIG="${SWIG}" ming_wrap.c; \
	${RM} -f depend

post-install:
	${INSTALL_DATA} ${WRKSRC}/ming.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
.endif

.include <bsd.port.mk>
