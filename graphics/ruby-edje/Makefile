# New ports collection makefile for:	ruby-edje
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	edje
PORTVERSION=	20061008
PORTREVISION=	0
CATEGORIES=	graphics ruby
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-edje-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Edje library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake \
		${RUBY_SA}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas

USE_BZIP2=	yes
USE_RUBY=	yes
USE_EFL=	edje

RUBY_SA=	${RUBY_SITEARCHLIBDIR}

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
