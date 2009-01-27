# New Ports collection makefile for:	rubyrrdtool
# Date created:		19 April 2007
# Whom:			Konstantin SAURBIER (saurbier@math.uni-bielefeld.de)
#
# $FreeBSD$

PORTNAME=	rrdtool
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	rubyrrdtool
DISTNAME=	RubyRRDtool-${PORTVERSION}

MAINTAINER=	saurbier@math.uni-bielefeld.de
COMMENT=	A Ruby interface to RRDTool

LIB_DEPENDS=	rrd:${PORTSDIR}/databases/rrdtool
BUILD_DEPENDS=	sow:${PORTSDIR}/devel/rubygem-hoe

BROKEN=		does not compile with rrdtool 1.3

DEPRECATED=	port no longer maintained by upstream use rrdtools own ruby bindings instead
EXPIRATION_DATE=	2009-03-01

GEM_NAME=	RubyRRDtool-0.6.0
GEM_ENV=	MAKEFLAGS="CPPFLAGS=-I${LOCALBASE}/include"

USE_RUBY=	yes
USE_RUBYGEMS=	yes

# This target is only meant to be used by the port maintainer.
x-generate-plist:
	(${PORTSDIR}/Tools/scripts/plist -d -m ${MTREE_FILE} ${PREFIX} \
	| ${SED} -E \
		's,.*share/nls/.+$$,,g \
		;s,^${GEM_CACHE}$$,%%GEM_CACHE%%,g \
		;s,${GEM_DOC_DIR}(/.+)?$$,%%GEM_DOC_DIR%%\1,g \
		;s,${GEM_LIB_DIR}(/.+)?$$,%%GEM_LIB_DIR%%\1,g \
		;s,^${GEM_SPEC}$$,%%GEM_SPEC%%,g \
		;s,^${GEMS_BASE_DIR}/(.+)$$,\1,g \
		;s,^@dirrm (${SPEC_DIR}|${GEMS_DIR}|lib/ruby).*$$,,g \
		' | ${TR} -s '\n') > temp-pkg-plist

.include <bsd.port.mk>
