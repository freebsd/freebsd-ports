# Created by: Vanilla I. Shu <vanilla@FreeBSD.org>
# $FreeBSD$

PORTNAME=	geda
PORTVERSION=	1.8.1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://ftp.geda-project.org/geda-gaf/stable/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	${PORTNAME}-gaf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GPL Electronic Design Automation tools

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	stroke:${PORTSDIR}/devel/libstroke \
		guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

OPTIONS_DEFINE=	DOCS

USES=		pathfix gettext perl5 gmake pkgconfig
USE_GNOME=	desktopfileutils gtk20
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

MAN1=		convert_sym.1 garchive.1 gattrib.1 gmk_sym.1 \
		gnetlist.1 grenum.1 gsch2pcb.1 gschem.1 \
		gschlas.1 gsymcheck.1 gsymfix.1 gxyrs.1 \
		olib.1 pads_backannotate.1 pcb_backannotate.1 refdes_renum.1 \
		sarlacc_schem.1 sarlacc_sym.1 schdiff.1 smash_megafile.1 \
		sw2asc.1 tragesym.1
INFO=		geda-scheme

CONFLICTS=	geda-docs-[0-9]* geda-examples-[0-9]* geda-gattrib-[0-9]* \
		geda-gschem-[0-9]* geda-netlist-[0-9]* geda-symbols-[0-9]* \
		geda-symcheck-[0-9]* geda-utils-[0-9]* libgeda-[0-9]*

PORTSCOUT=	limitw:1,even

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MDOCS)
CONFIGURE_ARGS+=--docdir=${WRKDIR}/fakeroot
.endif

post-patch:
.for dir in gattrib gschem libgeda
	@${REINPLACE_CMD} -e \
		'/-x/s|INSTALL_DATA|INSTALL|' ${WRKSRC}/${dir}/data/Makefile.in
.endfor
	@${REINPLACE_CMD} -e \
		'/OS_LINUX=/s|no|yes|' ${WRKSRC}/configure
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e '/^#!/s|/usr/bin|${LOCALBASE}/bin|'
	@${GREP} -lR "/usr/bin/perl" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e '/^#!/s|/usr/bin|${LOCALBASE}/bin|'

.include <bsd.port.mk>
