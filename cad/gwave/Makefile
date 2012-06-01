# New ports collection makefile for:	gwave
# Date created:			16 June 2002
# Whom:				Duncan Barclay <dmlb@dmlb.org>
#
# $FreeBSD$
#

PORTNAME=	gwave
PORTVERSION=	20080127
PORTREVISION=	6
CATEGORIES=	cad
MASTER_SITES=	http://geda.seul.org/dist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Waveform viewer for analogue electronic simulation tools

LIB_DEPENDS=	guile.21:${PORTSDIR}/lang/guile \
		guilegtk-1.2.0:${PORTSDIR}/x11-toolkits/guile-gtk

USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
CPPFLAGS+=	-I${LOCALBASE}/include

OPTIONS_DEFINE=	PLOTUTILS GNUPLOT EXAMPLES
OPTIONS_DEFAULT=	GNUPLOT
PLOTUTILS_DESC=	Enable plotting using plotutils

DOCFILES=	Guile.notes \
		gwave-concepts.txt \
		gwave-hooks.txt \
		gwave-procedures.txt \
		gwave-variables.txt \
		hspice-output.txt \
		hspice.txt \
		spice3.txt

MAN1=		sp2sp.1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPLOTUTILS}
RUN_DEPENDS+=	graph:${PORTSDIR}/graphics/plotutils
.endif

.if ${PORT_OPTIONS:MGNUPLOT}
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif

.if ${PORT_OPTIONS:MEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.include <bsd.port.mk>
