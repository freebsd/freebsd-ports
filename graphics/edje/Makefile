# New ports collection makefile for:	edje
# Date created:				08/08/2004
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	edje
DISTVERSION=	1.1.0
PORTEPOCH=	2
CATEGORIES=	graphics enlightenment
MASTER_SITES=	http://download.enlightenment.org/releases/ \
		http://files.roorback.net/e17/2011-12-02/base/

MAINTAINER=	magik@roorback.net
COMMENT=	Edje is a complex graphical design and layout engine

LICENSE=	BSD

LIB_DEPENDS=	lua-5.1:${PORTSDIR}/lang/lua
RUN_DEPENDS=	update-mime-database:${PORTSDIR}/misc/shared-mime-info

DIST_SUBDIR=	e17
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_EFL=	eet evas ecore embryo libtool_hack librt_hack
USE_EFL_EVAS_LOADERS=	eet jpeg png
USE_EFL_ECORE=	evas file imf imf_evas
USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes

CONFIGURE_ARGS+=	--without-vim

.if !defined(NOPORTEXAMPLES)
CONFIGURE_ARGS+=	--enable-install-examples
.else
CONFIGURE_ARGS+=	--disable-install-examples
.endif

post-patch:
	@${REINPLACE_CMD} -E -e "/^SUBDIRS[[:space:]]+=/s/utils//" \
	    ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|= \$$(datadir)/\$$(PACKAGE)/examples|= $$(datadir)/examples/$$(PACKAGE)|' \
		${WRKSRC}/src/examples/Makefile.in

post-install:
	-update-mime-database ${PREFIX}/share/mime
.if defined(NOPORTEXAMPLES)
	@${RMDIR} ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
