# New ports collection makefile for:	rapidsvn
# Date created:		Jan 1, 2005
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rapidsvn
PORTVERSION=	0.9.4
PORTREVISION=	4
PORTEVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.rapidsvn.org/download/release/${PORTVERSION}/

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Cross-platform GUI front-end for the Subversion revision system

BROKEN=		depends on apr-db42-1.3.2 and apr-1.3.2 which conflict with each other

BUILD_DEPENDS=	apr-1-config:${PORTSDIR}/devel/apr-svn \
		neon-config:${PORTSDIR}/www/neon26 \
		svn:${PORTSDIR}/devel/subversion \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/VERSION:${PORTSDIR}/textproc/docbook-xsl

USE_WX=	2.6
WX_CONF_ARGS=	absolute

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:261 libtool:15 automake:19
CONFIGURE_ARGS=	--with-apr-config=apr-1-config \
	--with-apu-config=apu-1-config \
	--with-neon-config=neon-config \
	--with-xsltproc=xsltproc \
	--with-docbook-xsl-manpages=${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl \
	--with-manpage=yes

USE_LDCONFIG=	yes
MAN1=		rapidsvn.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/manpage/rapidsvn.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
