# New ports collection makefile for:	FreeRIDE
# Date created:		16 June 2004
# Whom:			Alexander Novitsky <alecn2002@yandex.ru>
#
# $FreeBSD$
#

PORTNAME?=	${MASTERPORTNAME}
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	devel ruby
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	alecn2002@yandex.ru
COMMENT?=	Ruby Integrated Developement Environment written in Ruby

MASTERPORTNAME=	freeride
DISTNAME=	${MASTERPORTNAME}-${PORTVERSION}

USE_RUBY=	yes
NO_BUILD=	yes

# IF >>>>>>

.if ${PORTNAME} == ${MASTERPORTNAME}
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/fox12.so:${PORTSDIR}/x11-toolkits/ruby-fox12 \
		${RUBY_SITELIBDIR}/freebase/freebase.rb:${PORTSDIR}/devel/freebase \
		${RUBY_SITEARCHLIBDIR}/rrb_ripper.so:${PORTSDIR}/devel/ruby-rrb

post-patch:
	${CP} ${FILESDIR}/install.rb ${WRKSRC}/

do-install:
	cd ${WRKSRC}; ${RUBY} install.rb --prefix=${PREFIX}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/freeride ${PREFIX}/bin
	${CHMOD} a+w ${RUBY_SITELIBDIR:S|${LOCALBASE}|${PREFIX}|g}/freeride/config
#
# For testing of installation, no real install
#
install-noharm: build pre-install
	cd ${WRKSRC}; ${RUBY} install.rb --no-harm
.endif

# <<<<<< IF

.include <bsd.port.mk>
