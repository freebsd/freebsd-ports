# Created by: alepulver
# $FreeBSD$

PORTNAME=	pdfedit
PORTVERSION=	0.4.5
PORTREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	SF

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	PDF document manipulating library

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_filesystem.so:devel/boost-libs \
		libfreetype.so:print/freetype2 \
		libpng16.so:graphics/png \
		libt1.so:devel/t1lib

USES=		gmake perl5 tar:bzip2
USE_PERL5=	build
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-root-dir=${STAGEDIR} \
		--with-ft-library=${LOCALBASE}/lib \
		--with-ft-includes=${LOCALBASE}/include \
		--with-t1-library=${LOCALBASE}/lib \
		--with-t1-includes=${LOCALBASE}/include \
		--with-parallel-make=off \
		--disable-gui \
		--enable-pdfedit-core-dev \
		--enable-tools
INSTALL_TARGET=	install install-tools
PORTDOCS=	Changelog README AUTHORS

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=DOCS

BROKEN_sparc64=		Fails to configure: error: Could not link against boost_program_options

post-extract:
	${INSTALL_DATA} ${WRKSRC}/doc/AUTHORS ${WRKSRC}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
