# New ports collection makefile for:	Ruby/Ming
# Date created:		16 Oct 2000
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	ming
PORTVERSION=	0.0.2e
PORTREVISION=	1
CATEGORIES=	graphics ruby
MASTER_SITES=	http://www.opaque.net/ming/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
EXTRACT_SUFX=	.tgz

MAINTAINER=	knu@FreeBSD.org

BUILD_DEPENDS=	swig1.3:${PORTSDIR}/devel/SWIG-devel
LIB_DEPENDS=	ming.0:${PORTSDIR}/graphics/ming

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

MD5_FILE=	${PORTSDIR}/graphics/ming/distinfo

WRKSRC=		${WRKDIR}/${DISTNAME}/rb_ext
CONFIGURE_ARGS=	--with-ming-include="${LOCALBASE}/include/ming"
MAKE_ARGS=	 SWIG="${SWIG}"
INSTALL_TARGET=	site-install

SWIG=		swig1.3

EXAMPLES=	shape.rb test.rb

post-extract:
	${LN} -sf ${WRKSRC}/../py_ext/*.i ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${WRKSRC}/ming.rb ${RUBY_SITELIBDIR}/
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_EXAMPLESDIR}/ming
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_EXAMPLESDIR}/ming/
.endfor
.endif

.include <bsd.port.mk>
