# New ports collection makefile for:   mico
# Date created:        11 July 1998
# Whom:                Marc G. Fournier <scrappy@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	mico
PORTVERSION=	2.3.9
CATEGORIES=	devel
MASTER_SITES=	http://www.mico.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A CORBA 2.0 implementation which goal is freely available

WRKSRC=			${WRKDIR}/mico
INSTALLS_SHLIB=		yes
GNU_CONFIGURE=		yes
USE_REINPLACE=		yes
USE_GMAKE=		yes
USE_GCC=		3.2
CONIFUGRE_ARGS+=	--enable-minimum-corba --enable-cd \
			--disable-mini-stl \

MAN1=		idl.1 imr.1 nsadmin.1
MAN5=		micorc.5
MAN8=		ird.8 micod.8 nsd.8

post-patch:
	${REINPLACE_CMD} -e "s,so.1.0,so, ;s,-O2,${CFLAGS}," ${WRKSRC}/configure

post-configure:
	${FIND} ${WRKSRC} -name Makefile | ${XARGS} \
		${REINPLACE_CMD} -e "s,/doc/,/share/doc/,"
	${REINPLACE_CMD} -e "s,/doc/,/share/doc/," ${WRKSRC}/demo/MakeVars

post-install:
	${LN} -sf ${PREFIX}/lib/libmico${PORTVERSION}.so.1 ${PREFIX}/lib/libmico.${PORTVERSION}.so
	${LN} -sf ${PREFIX}/lib/libmicoaux${PORTVERSION}.so.1 ${PREFIX}/lib/libmicoaux.${PORTVERSION}.so
	${LN} -sf ${PREFIX}/lib/libmicocoss${PORTVERSION}.so.1 ${PREFIX}/lib/libmicocoss.${PORTVERSION}.so
	${LN} -sf ${PREFIX}/lib/libmicogtk${PORTVERSION}.so.1 ${PREFIX}/lib/libmicogtk.${PORTVERSION}.so
	${LN} -sf ${PREFIX}/lib/libmicoqt${PORTVERSION}.so.1 ${PREFIX}/lib/libmicoqt.${PORTVERSION}.so
	${LN} -sf ${PREFIX}/lib/libmicotcl${PORTVERSION}.so.1 ${PREFIX}/lib/libmicotcl.${PORTVERSION}.so
	${LN} -sf ${PREFIX}/lib/libmicox${PORTVERSION}.so.1 ${PREFIX}/lib/libmicox.${PORTVERSION}.so
	@${STRIP_CMD} ${PREFIX}/bin/containmentd
	@${STRIP_CMD} ${PREFIX}/bin/eventd
	@${STRIP_CMD} ${PREFIX}/bin/idl
	@${STRIP_CMD} ${PREFIX}/bin/imr
	@${STRIP_CMD} ${PREFIX}/bin/iordump
	@${STRIP_CMD} ${PREFIX}/bin/ird
	@${STRIP_CMD} ${PREFIX}/bin/mico-cpp
	@${STRIP_CMD} ${PREFIX}/bin/micod
	@${STRIP_CMD} ${PREFIX}/bin/noded
	@${STRIP_CMD} ${PREFIX}/bin/nsadmin
	@${STRIP_CMD} ${PREFIX}/bin/nsd
	@${STRIP_CMD} ${PREFIX}/bin/propertyd
	@${STRIP_CMD} ${PREFIX}/bin/proxyd
	@${STRIP_CMD} ${PREFIX}/bin/randomd
	@${STRIP_CMD} ${PREFIX}/bin/referenced
	@${STRIP_CMD} ${PREFIX}/bin/timed
	@${STRIP_CMD} ${PREFIX}/bin/traderd
	@${STRIP_CMD} ${PREFIX}/bin/traversald

.include <bsd.port.mk>
