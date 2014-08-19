# Created by: Simun Mikecin <numisemis at yahoo dot com>
# $FreeBSD$

PORTNAME=	oci8
DISTVERSION=	1.0.0rc1
CATEGORIES=	databases ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=ruby-oci8
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${DISTVERSION:S/rc/-rc/}
DIST_SUBDIR=	ruby

MAINTAINER= ports@FreeBSD.org
COMMENT=	Ruby interface to Oracle OCI8

BROKEN=		Does not configure

BUILD_DEPENDS=	${LOCALBASE}/oracle8-client/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client
RUN_DEPENDS=	${LOCALBASE}/oracle8-client/lib/libclntsh.a:${PORTSDIR}/databases/oracle8-client

MAKE_JOBS_UNSAFE=	yes

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
RUBY_EXTCONF_SUBDIRS=	ext/oci8

CONFIGURE_ARGS=	--with-instant-client="${LOCALBASE}/oracle8-client/lib"
INSTALL_TARGET=	site-install

DOCS_EN=	ChangeLog README

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

DEPRECATED=	RubyForge shutdown May 15 2014
EXPIRATION_DATE=	2014-09-20

post-install:
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
