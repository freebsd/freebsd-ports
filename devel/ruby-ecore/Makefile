# New ports collection makefile for:	ruby-ecore
# Date created:		22 June 2006
# Whom:			Stanislav Sedov <ssedov@mbsd.msk.ru>
#
# $FreeBSD$
#

PORTNAME=	ecore
PORTVERSION=	20061008
PORTREVISION=	0
CATEGORIES=	devel ruby
MASTER_SITES=	http://sunner.elcomnet.ru/~stas/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-ecore-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	Ruby bindings for Ecore library

BUILD_DEPENDS=	${LOCALBASE}/bin/rake:${PORTSDIR}/devel/rubygem-rake \
		${RUBY_SA}/evas/rb_evas.h:${PORTSDIR}/graphics/ruby-evas

USE_BZIP2=	yes
USE_RUBY=	yes
USE_EFL=	ecore

RUBY_SA=	${RUBY_SITEARCHLIBDIR}

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} "s#%%X11BASE%%#${X11BASE}#g" ${WRKSRC}/Rakefile

do-build:
	@(cd ${WRKSRC}; ${SETENV} ECORE_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake)

do-install:
	@(cd ${WRKSRC}; ${SETENV} ECORE_PREFIX=${LOCALBASE} \
		${LOCALBASE}/bin/rake install)

.include <bsd.port.post.mk>
