# New ports collection makefile for:	ruby-edje
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	edje
PORTVERSION=	20060516
CATEGORIES=	graphics ruby
MASTER_SITES=	http://mbsd.msk.ru/dist/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-edje-${PORTVERSION}

MAINTAINER=	ssedov@mbsd.msk.ru
COMMENT=	Ruby bindings for Edje library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake \
		${RUBY_SITEARCHLIBDIR}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas
LIB_DEPENDS=	edje.5:${PORTSDIR}/graphics/edje

USE_BZIP2=	yes
USE_RUBY=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s#%%X11BASE%%#${X11BASE}#g" ${WRKSRC}/Rakefile

do-build:
	@(cd ${WRKSRC}; ${SETENV} EDJE_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} EDJE_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
