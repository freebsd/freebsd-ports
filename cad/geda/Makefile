# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geda
PORTVERSION=	1.8.2
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://ftp.geda-project.org/geda-gaf/stable/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	${PORTNAME}-gaf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GPL Electronic Design Automation tools

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	libstroke.so:${PORTSDIR}/devel/libstroke \
		libguile.so:${PORTSDIR}/lang/guile
RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

OPTIONS_DEFINE=	DOCS

USES=		desktop-file-utils gettext gmake pathfix perl5 pkgconfig \
		shared-mime-info shebangfix
SHEBANG_FILES=	examples/lightning_detector/bom libgeda/docs/*.dox \
		utils/gxyrs/*.pl utils/scripts/* \
		utils/docs/*.dox gattrib/docs/*.dox \
		gschem/docs/*.dox gsymcheck/docs/*.dox \
		gnetlist/docs/*.dox
USE_GNOME=	gtk20
USE_PERL5=	run
USE_PYTHON=	run
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-libstroke=${LOCALBASE}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-gaf
DATADIR=	${PREFIX}/share/gEDA

INFO=		geda-scheme

CONFLICTS=	geda-docs-[0-9]* geda-examples-[0-9]* geda-gattrib-[0-9]* \
		geda-gschem-[0-9]* geda-netlist-[0-9]* geda-symbols-[0-9]* \
		geda-symcheck-[0-9]* geda-utils-[0-9]* libgeda-[0-9]*

PORTSCOUT=	limitw:1,even

.include <bsd.port.options.mk>

post-patch:
.for dir in gattrib gschem libgeda
	@${REINPLACE_CMD} -e \
		'/-x/s|INSTALL_DATA|INSTALL|' ${WRKSRC}/${dir}/data/Makefile.in
.endfor
	@${REINPLACE_CMD} -e \
		'/OS_LINUX=/s|no|yes|' ${WRKSRC}/configure

.include <bsd.port.mk>
