# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edje
PORTVERSION=	1.7.8
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		LOCAL/gblach/e17/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Edje is a complex graphical design and layout engine

LICENSE=	BSD

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pathfix pkgconfig shared-mime-info
USE_EFL=	eina eet evas ecore eio embryo libtool_hack librt_hack
USE_EFL_EVAS_LOADERS=	eet jpeg png
USE_EFL_ECORE=	evas file imf imf_evas
USE_LUA=	5.1+
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--without-vim

post-patch:
	@${REINPLACE_CMD} -E -e "/^SUBDIRS[[:space:]]+=/s/utils//" \
	    ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

.include <bsd.port.mk>
