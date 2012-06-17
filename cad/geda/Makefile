# New ports collection makefile for:	geda
# Date created:			24 Nov 1998
# Whom:				Vanilla I. Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	geda
PORTVERSION=	1.6.2
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	http://geda.seul.org/release/%SUBDIR%/
MASTER_SITE_SUBDIR=	v${PORTVERSION:R}/${PORTVERSION}
DISTNAME=	${PORTNAME}-gaf-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The GPL Electronic Design Automation tools

LICENSE=	GPLv2 # (or later)

LIB_DEPENDS=	stroke:${PORTSDIR}/devel/libstroke \
		guile:${PORTSDIR}/lang/guile
RUN_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

OPTIONS_DEFINE=	DOCS

USE_GNOME=	desktopfileutils gnomehack gtk20
USE_PERL5_RUN=	yes
USE_PYTHON=	run
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--with-libstroke=${LOCALBASE}
USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}-gaf
DATADIR=	${PREFIX}/share/gEDA

MAN1=		gnetlist.1 grenum.1 gschem.1 gsymcheck.1

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
		'/<glib\/gm/d ; \
		 s|<glib/types.h>|<glib.h>|' ${WRKSRC}/libgeda/src/s_path.c
	@${GREP} -lR "/usr/bin/python" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e '/^#!/s|/usr/bin|${LOCALBASE}/bin|'
	@${GREP} -lR "/usr/bin/perl" ${WRKSRC} | ${XARGS} \
		${REINPLACE_CMD} -e '/^#!/s|/usr/bin|${LOCALBASE}/bin|'

.include <bsd.port.mk>
