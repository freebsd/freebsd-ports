# New ports collection makefile for:   libofx
# Date created:        February 16 2003
# Whom:                Glenn Johnson <glennpj@charter.net>
#
# $FreeBSD$
#

PORTNAME=	libofx
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OpenSource implementation of the OFX (Open Financial eXchange)

LIB_DEPENDS=	curl.5:${PORTSDIR}/ftp/curl \
		xml\\+\\+-1.0.1:${PORTSDIR}/textproc/libxml++ \
		osp.5:${PORTSDIR}/textproc/opensp

USE_ICONV=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	aclocal:110 autoheader:262 automake:110 autoconf:262 libtool:22
ACLOCAL_ARGS=	-I m4
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-doxygen --disable-dot --disable-gengetopt \
		--with-opensp-includes=${LOCALBASE}/include/OpenSP
USE_LDCONFIG=	yes

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog INSTALL NEWS README totest.txt
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
	@(cd ${WRKSRC}/doc; ${COPYTREE_SHARE} html ${DOCSDIR})
.endif

.include <bsd.port.mk>
