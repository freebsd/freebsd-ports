# New ports collection makefile for:	P4Ruby
# Date created:		16 August 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	p4
PORTVERSION=	1.4251
CATEGORIES=	devel ruby
MASTER_SITES=	http://public.perforce.com/guest/tony_smith/perforce/API/Ruby/release/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME:U}Ruby-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	knu@FreeBSD.org
COMMENT=	Ruby interface to the Perforce API

EXTRACT_DEPENDS=	${LOCALBASE}/lib/perforce/libclient.a:${PORTSDIR}/devel/p4api

USE_RUBY=	yes

P4APIVER=	2003.01
P4APIDIR=	${WRKDIR}/p4api
INSTALL_TARGET=	site-install

EXAMPLES=	example.rb

DOCS=		Changes \
		doc/*

post-extract:
	${MKDIR} ${P4APIDIR}
	${LN} -s ${LOCALBASE}/include/perforce/*.h ${P4APIDIR}/
	${LN} -s ${LOCALBASE}/lib/perforce/*.a ${P4APIDIR}/

do-configure:
	cd ${WRKSRC}; ${RUBY} p4conf.rb --apidir="${P4APIDIR}" --apiver="${P4APIVER}"

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODEXAMPLESDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODEXAMPLESDIR}/
.endfor
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
