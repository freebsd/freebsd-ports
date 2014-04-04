# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	rdbc1
PORTVERSION=	001103
PORTREVISION=	2
CATEGORIES=	databases ruby
MASTER_SITES=	http://homepage3.nifty.com/guion/SOFT/RDBC/ \
		ftp://ftp.dinoex.de/pub/approved/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}_${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby Database Connectivity

RUN_DEPENDS=	rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg

USE_RUBY=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	yes

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.rb ${STAGEDIR}${RUBY_SITELIBDIR}/
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}/ja
	${CP} -R ${WRKSRC}/doc/en/* ${STAGEDIR}${RUBY_MODDOCDIR}/
	${CP} -R ${WRKSRC}/doc/ja/* ${STAGEDIR}${RUBY_MODDOCDIR}/ja/
.endif

.include <bsd.port.mk>
