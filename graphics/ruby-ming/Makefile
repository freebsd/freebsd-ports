# New ports collection makefile for:	Ruby/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.1.0
CATEGORIES=	graphics ruby
MASTER_SITES=	# none
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTFILES=	# none

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/SWIG-devel \
		${NONEXISTENT}:${PORTSDIR}/graphics/ming:patch
LIB_DEPENDS=	ming.2:${PORTSDIR}/graphics/ming

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

MD5_FILE=	${.CURDIR}/../ming/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/rb_ext
CONFIGURE_ARGS=	--with-ming-include="${LOCALBASE}/include/ming"
MAKE_ARGS=	 SWIG="${SWIG}"
INSTALL_TARGET=	site-install

SWIG=		swig1.3

EXAMPLES=	shape.rb test.rb

do-extract:
	${MKDIR} ${WRKDIR}
	${LN} -s `cd ${PORTSDIR}/graphics/ming && ${MAKE} -V WRKDIR`/* ${WRKDIR}/

post-extract:
	${LN} -sf ../ming.i ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/ming.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/ming
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/ming/
.endfor
.endif

.include <bsd.port.mk>
