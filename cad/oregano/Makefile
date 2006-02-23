# New ports collection makefile for:	oregano
# Date created:			19 Feb 2001
# Whom:				Anders Andersson <anders@hack.org>
#
# $FreeBSD$
#

PORTNAME=	oregano
PORTVERSION=	0.40.5
CATEGORIES=	cad gnome
MASTER_SITES=	http://gforge.lug.fi.uba.ar/frs/download.php/64/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Schematic capture and simulation of electrical circuits

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gnomehack gnomeprefix gtksourceview intlhack libglade2 \
		libgnomeprintui libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
INSTALLS_OMF=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	"Does not build on 4.X"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|src/main\.c|${PORTNAME}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
