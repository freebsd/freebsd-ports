# $FreeBSD$

PORTNAME=	rapidsvn
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://www.rapidsvn.org/download/release/${PORTVERSION}/

MAINTAINER=	robert.ayrapetyan@gmail.com
COMMENT=	Cross-platform GUI front-end for the Subversion revision system

BUILD_DEPENDS=	${LOCALBASE}/bin/svn:${PORTSDIR}/devel/subversion \
		xsltproc:${PORTSDIR}/textproc/libxslt \
		${LOCALBASE}/share/xsl/docbook/VERSION:${PORTSDIR}/textproc/docbook-xsl

USE_WX=	2.8
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute

GNU_CONFIGURE=	yes
USES=		gettext
CONFIGURE_TARGET=
CONFIGURE_ARGS=	--with-apr-config=apr-1-config \
	--with-apu-config=apu-1-config \
	--with-svn-include=${LOCALBASE}/include \
	--with-svn-lib=${LOCALBASE}/lib \
	--with-xsltproc=xsltproc \
	--with-docbook-xsl-manpages=${LOCALBASE}/share/xsl/docbook/manpages/docbook.xsl \
	--program-prefix="" \
	--with-doxygen=no \
	--with-manpage=yes

USE_LDCONFIG=	yes

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/manpage/rapidsvn.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>
