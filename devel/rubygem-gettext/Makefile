# New ports collection makefile for:	Ruby GetText
# Date created:		4 February 2002
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	2.1.0
PORTREVISION=	2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Ruby implementation of the gettext library

RUN_DEPENDS=	rubygem-locale>=2.0.5:${PORTSDIR}/devel/rubygem-locale

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rgettext bin/rmsgfmt bin/rmsgmerge

post-install:
	@(cd ${PREFIX}/${GEM_LIB_DIR} && \
	    ${PATCH} -s -f -p0 < ${PATCHDIR}/extra::patch-lib_gettext_runtime_locale_path.rb && \
	    ${RM} lib/gettext/runtime/locale_path.rb.orig)

.include <bsd.port.mk>
