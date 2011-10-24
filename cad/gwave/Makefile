# New ports collection makefile for:	gwave
# Date created:			16 June 2002
# Whom:				Duncan Barclay <dmlb@dmlb.org>
#
# $FreeBSD$
#

PORTNAME=	gwave
PORTVERSION=	20080127
PORTREVISION=	5
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

OPTIONS=	PLOTUTILS "Use GNU plotutils for plotting" off \
		GNUPLOT "Use gnuplot for plotting" on \
		EXAMPLES "Install example spice files" off

DOCFILES=	Guile.notes \
		gwave-concepts.txt \
		gwave-hooks.txt \
		gwave-procedures.txt \
		gwave-variables.txt \
		hspice-output.txt \
		hspice.txt \
		spice3.txt

MAN1=		sp2sp.1

.include <bsd.port.pre.mk>

.if defined(WITH_PLOTUTILS)
RUN_DEPENDS+=	graph:${PORTSDIR}/graphics/plotutils
.endif

.if !defined(WITHOUT_GNUPLOT)
RUN_DEPENDS+=	gnuplot:${PORTSDIR}/math/gnuplot
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for FILE in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/doc/${FILE} ${DOCSDIR}
.endfor
.endif

.if defined(WITH_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

.include <bsd.port.post.mk>
