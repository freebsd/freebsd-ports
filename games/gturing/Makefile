# New ports collection makefile for:	games/gturing
# Date created:				08 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	gturing
PORTVERSION=	0.1.1
CATEGORIES=	games gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/gturing/0.1/

MAINTAINER=	rael@vectorstar.net

LIB_DEPENDS=	gnomeui-2.0:${PORTSDIR}/x11-toolkits/libgnomeui \
		gnomeprintui-2.0:${PORTSDIR}/x11-toolkits/libgnomeprintui

USE_X_PREFIX=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--localstatedir=${PREFIX}/share/gnome \
		--datadir=${PREFIX}/share/gnome
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

DOCS=	AUTHORS COPYING NEWS ChangeLog TODO README INSTALL

EXAMPLEDIR=	${PREFIX}/share/examples/gturing

EXAMPLES=	3ones2zeroes.tur  add.tur  bb3.tur  dashnumbers.tur  addbin.tur \
		bb5.tur  dec2bin.tur  dec2bin_shift.tur  bb2.tur  bin2dec.tur \
		bin2dec_shift.tur  sort.tur  subst.tur

pre-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure
	@find ${WRKSRC} -name "Makefile.in" | xargs ${REINPLACE_CMD} -e \
		's|[(]datadir[)]/gnome/|(datadir)/|g ; \
		s|[(]datadir[)]/locale|(prefix)/share/locale|g'

post-install:
	${INSTALL} -d -o root -g wheel -m 0755 ${EXAMPLEDIR}
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/tapes/${f} ${EXAMPLEDIR}
.endfor
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
