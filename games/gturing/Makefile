# New ports collection makefile for:	games/gturing
# Date created:				08 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	gturing
PORTVERSION=	0.1.1
PORTREVISION=	8
CATEGORIES=	games gnome
MASTER_SITES=	ftp://ftp.gnome.org/pub/gnome/sources/gturing/0.1/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple turing machine simulator for GNOME 2

USE_X_PREFIX=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeui
USE_GMAKE=	yes
USE_LIBTOOL_VER=13
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
INSTALLS_OMF=	yes
CONFIGURE_TARGET=	--target=${MACHINE_ARCH}-unknown-freebsd${OSREL}

DOCS=	AUTHORS COPYING NEWS ChangeLog TODO README INSTALL

EXAMPLEDIR=	${PREFIX}/share/examples/gturing

EXAMPLES=	3ones2zeroes.tur  add.tur  bb3.tur  dashnumbers.tur  addbin.tur \
		bb5.tur  dec2bin.tur  dec2bin_shift.tur  bb2.tur  bin2dec.tur \
		bin2dec_shift.tur  sort.tur  subst.tur

post-patch:
	@${REINPLACE_CMD} -e 's|-D.*_DISABLE_DEPRECATED||g' \
		${WRKSRC}/configure

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
