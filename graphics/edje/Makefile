# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edje
PORTVERSION=	1.7.9
PORTREVISION=	3
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Edje is a complex graphical design and layout engine

LICENSE=	BSD2CLAUSE

DIST_SUBDIR=	e17
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig shared-mime-info lua tar:bzip2
USE_EFL=	eina eet evas ecore eio embryo libtool_hack librt_hack
USE_EFL_EVAS_LOADERS=	eet jpeg png
USE_EFL_ECORE=	evas file imf imf_evas
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--without-vim

post-patch:
	@${REINPLACE_CMD} -e "s/lua >=/lua-${LUA_VER} >=/g" \
		-e 's/requirement_lua="lua"/requirement_lua="lua-${LUA_VER}"/g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -E -e "/^SUBDIRS[[:space:]]+=/s/utils//" \
	    ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

.include <bsd.port.mk>
