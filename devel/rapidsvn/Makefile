# New ports collection makefile for:	rapidsvn
# Date created:		Jan 1, 2005
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	rapidsvn
PORTVERSION=	0.12.0
CATEGORIES=	devel
MASTER_SITES=	http://www.rapidsvn.org/download/release/0.12/
DISTNAME=	${PORTNAME}-0.12.0-1

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Cross-platform GUI front-end for the Subversion revision system

BUILD_DEPENDS=	neon-config:${PORTSDIR}/www/neon29 \
		svn:${PORTSDIR}/devel/subversion \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/VERSION:${PORTSDIR}/textproc/docbook-xsl

USE_WX=	2.6
WX_CONF_ARGS=	absolute

GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_AUTOTOOLS=	autoconf:262 libtool:22 automake:19
CONFIGURE_TARGET=
CONFIGURE_ARGS=	--with-apr-config=apr-1-config \
	--with-apu-config=apu-1-config \
	--with-svn-include=${LOCALBASE}/include \
	--with-svn-lib=${LOCALBASE}/lib \
	--with-neon-config=neon-config \
	--with-xsltproc=xsltproc \
	--with-docbook-xsl-manpages=${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl \
	--program-prefix="" \
	--with-manpage=yes

USE_LDCONFIG=	yes
MAN1=		rapidsvn.1

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/manpage/rapidsvn.1 ${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
