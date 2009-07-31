# New ports collection makefile for:	gnetlist
# Date created:			4 April 2001
# Whom:				bruno schwander <bruno@tinkerbox.org>
#
# $FreeBSD$
#

PORTNAME=	netlist
PORTVERSION=	1.4.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	cad
MASTER_SITES=	ftp://ftp.geda.seul.org/pub/geda/release/v1.4/${PORTVERSION}/ \
		http://geda.seul.org/release/v1.4/${PORTVERSION}/
PKGNAMEPREFIX=	geda-
DISTNAME=	${PKGNAMEPREFIX}g${PORTNAME}-${PORTVERSION}

MAINTAINER=	stas@FreeBSD.org
COMMENT=	The gEDA's netlister

LIB_DEPENDS=	geda.33:${PORTSDIR}/cad/libgeda
RUN_DEPENDS=	${LOCALBASE}/share/geda/sym:${PORTSDIR}/cad/geda-symbols

DATADIR=	${PREFIX}/share/geda
DOCSDIR=	${PREFIX}/share/doc/geda

GNU_CONFIGURE=	yes
USE_GNOME=	gtk20
CONFIGURE_ARGS=	--with-docdir=${DOCSDIR}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		gnetlist.1

post-patch:
	@${REINPLACE_CMD} -E \
		-e "s,^(DATADIR[[:space:]]*=[[:space:]]*)gEDA,\1geda," \
		${WRKSRC}/configure

.include <bsd.port.mk>
